#include "DataStore.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QTextStream>

#include <assert.h>


DataStore::DataStore()
: QObject(NULL)
{
}


void DataStore::debug() const {
  printf("{\n");
  foreach(QString key, _cache.keys()) {
    if (_cache[key].isNull()) {
      printf("  \"%s\": NULL\n", qPrintable(key));
    } else {
      printf("  \"%s\": \"%s\"\n", qPrintable(key), qPrintable(_cache[key]));
    }
  }
  printf("}\n");
}


QString DataStore::filename() const {
  return _filename;
}

void DataStore::setFilename(const QString& filename) {
  _filename = filename;
}


static bool load(
  const QString& filename,
  QMap<QString, QString>& cache,
  const QString& folder
) {
  QDir dir(QDir(filename).absoluteFilePath(folder));
  
  foreach(QString entry, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    if (!load(filename, cache, QDir(folder).relativeFilePath(entry))) {
      return false;
    }
  }
  
  foreach(QString entry, dir.entryList(QDir::Files)) {
    QString filename = dir.absoluteFilePath(entry);
    QFile file(filename);
    
    if (file.open(QFile::ReadOnly)) {
      QTextStream in(&file);
      
      QString key = folder.isEmpty()
                  ? entry
                  : QString("%1/%2").arg(folder).arg(entry);
      QString value = in.readAll();
      
      cache.insert(key, value);
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
  return true;
}

bool DataStore::reload() {
  if (_filename.isEmpty()) {
    app->errorMessage("no filename");
    return false;
  }
  
  QMap<QString, QString> cache;
  if (!load(_filename, cache, "")) return false;
  _cache = cache;
  
  return true;
}

bool DataStore::save() const {
  if (_filename.isEmpty()) {
    app->errorMessage("no filename");
    return false;
  }
  
  QDir dir(_filename);
  dir.mkpath(".");
  
  foreach(QString key, _cache.keys()) {
    QString filename = dir.absoluteFilePath(key);
    
    QFileInfo(filename).absoluteDir().mkpath(".");
    
    QFile file(filename);
    if (file.open(QFile::WriteOnly)) {
      QTextStream out(&file);
      
      out << _cache.value(key);
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
  return true;
}


const QString DataStore::operator[](const QString& key) const {
  return _cache.value(key);
}

QString DataStore::take(const QString& key) {
  return _cache.take(key);
}

void DataStore::insert(const QString& key, const QString& value) {
  assert(isKeyValid(key));
  
  _cache.insert(key, value);
}


bool DataStore::isKeyValid(const QString& key) const {
  if (key.isEmpty()) return false;
  if (key.startsWith(QChar('/'))) return false;
  if (key.endsWith(QChar('/'))) return false;
  if (key.contains("//")) return false;
  if (key.contains(QChar('\n'))) return false;
  if (key.contains(QChar(' '))) return false;
  if (key.contains(QChar(':'))) return false;
  
  return true;
}

bool DataStore::contains(const QString& key) const {
  return _cache.contains(key);
}

void DataStore::remove(const QString& key) {
  _cache.remove(key);
}

void DataStore::clear() {
  _cache.clear();
}
