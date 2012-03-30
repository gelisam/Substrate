#include "DiskStore.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QFileSystemWatcher>
#include <QtCore/QTextStream>

#include <assert.h>


QString operator/(const QString& tree, const QString& leaf) {
  assert(DiskStore::isValidTree(tree));
  
  if (leaf.isEmpty()) {
    return tree;
  } else if (tree.isEmpty()) {
    return leaf;
  } else {
    return QString("%1/%2").arg(tree).arg(leaf);
  }
}


static QString path(const QString& _root, const QString& leaf) {
  assert(DiskStore::isValidTree(leaf));
  
  return QDir(_root).absoluteFilePath(leaf);
}

static QDir parentDir(const QString& _root, const QString& leaf) {
  return QFileInfo(path(_root, leaf)).absoluteDir();
}


static void watchNothing(QFileSystemWatcher* watcher) {
  QStringList paths = watcher->directories();
  
  if (!paths.isEmpty()) {
    watcher->removePaths(watcher->directories());
  }
}
  
static void watchAll(
  QFileSystemWatcher* watcher, const QString& root,
  const DiskStore* disk
) {
  if (root.isEmpty()) return;
  if (root.startsWith(QChar(':'))) return;
  
  foreach(QString key, disk->branches()) {
    watcher->addPath(path(root, key));
  }
}


DiskStore::DiskStore()
: QObject(NULL)
, _watcher(new QFileSystemWatcher(this))
{
  connect(_watcher, SIGNAL(directoryChanged(const QString&)),
          this,     SLOT(emitChanged()));
}


QString DiskStore::filename() const {
  return _filename;
}

void DiskStore::setFilename(const QString& filename) {
  watchNothing(_watcher);
  
  _filename = filename;
  
  watchAll(_watcher, _filename, this);
}


const QString DiskStore::operator[](const QString& leaf) const {
  QFile file(path(_filename, leaf));
  
  if (file.open(QFile::ReadOnly)) {
    QTextStream in(&file);
    
    return in.readAll();
  } else {
    app->errorMessage(file.errorString());
    return QString();
  }
}

void DiskStore::insert(const QString& leaf, const QString& value) const {
  parentDir(_filename, leaf).mkpath(".");
  
  QFile file(path(_filename, leaf));
  
  if (file.open(QFile::WriteOnly)) {
    watchNothing(_watcher);
    
    QTextStream out(&file);
    out << value;
    
    watchAll(_watcher, _filename, this);
  } else {
    app->errorMessage(file.errorString());
  }
}


bool DiskStore::isValidLeaf(const QString& key) {
  if (key.isEmpty()) return false;
  if (key.startsWith(QChar('/'))) return false;
  if (key.endsWith(QChar('/'))) return false;
  if (key.contains("//")) return false;
  
  return true;
}

bool DiskStore::isValidTree(const QString& key) {
  if (key.isEmpty()) return true;
  
  return DiskStore::isValidLeaf(key);
}


bool DiskStore::containsLeaf(const QString& key) const {
  if (_filename.isEmpty()) return false;
  
  QFileInfo info(path(_filename, key));
  
  return info.exists() && info.isFile();
}

bool DiskStore::containsTree(const QString& key) const {
  if (_filename.isEmpty()) return false;
  
  QFileInfo info(path(_filename, key));
  
  return info.exists() && info.isDir();
}


void DiskStore::removeLeaf(const QString& key) const {
  watchNothing(_watcher);
  
  QFile file(path(_filename, key));
  
  if (!file.remove()) {
    app->errorMessage(file.errorString());
  }
  
  watchAll(_watcher, _filename, this);
}

void DiskStore::removeTree(const QString& key) const {
  watchNothing(_watcher);
  
  QDir dir(path(_filename, key));
  
  // TODO: remove contents...
  
  if (!dir.rmdir(".")) {
    app->errorMessage(QString("Could not remove %1").arg(key));
  }
  
  watchAll(_watcher, _filename, this);
}


QStringList DiskStore::children(const QString& tree) const {
  QDir dir(path(_filename, tree));
  
  return dir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}

QStringList DiskStore::branches(const QString& tree) const {
  QStringList r;
  r << tree;
  
  foreach(QString child, children(tree)) {
    QString key = tree / child;
    
    if (containsTree(key)) {
      r << branches(key);
    }
  }
  
  return r;
}

QStringList DiskStore::leaves(const QString& tree) const {
  QStringList r;
  
  foreach(QString child, children(tree)) {
    QString key = tree / child;
    
    if (containsLeaf(key)) {
      r << key;
    } else {
      r << leaves(key);
    }
  }
  
  return r;
}


void DiskStore::emitChanged() {
  emit changed();
}
