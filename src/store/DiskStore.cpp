#include "DiskStore.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
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


DiskStore::DiskStore()
: QObject(NULL)
{
}


QString DiskStore::filename() const {
  return _filename;
}

void DiskStore::setFilename(const QString& filename) {
  _filename = filename;
}


static QString path(const QString& _root, const QString& leaf) {
  assert(DiskStore::isValidTree(leaf));
  
  return QDir(_root).absoluteFilePath(leaf);
}

static QDir parentDir(const QString& _root, const QString& leaf) {
  return QFileInfo(path(_root, leaf)).absoluteDir();
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
    QTextStream out(&file);
    
    out << value;
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
  QFile file(path(_filename, key));
  
  if (!file.remove()) {
    app->errorMessage(file.errorString());
  }
}

void DiskStore::removeTree(const QString& key) const {
  QDir dir(path(_filename, key));
  
  // TODO: remove contents...
  
  if (!dir.rmdir(".")) {
    app->errorMessage(QString("Could not remove %1").arg(key));
  }
}


QStringList DiskStore::children(const QString& tree) const {
  QDir dir(path(_filename, tree));
  
  return dir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
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
