#include "DataStore.h"

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
  return _disk.filename();
}

void DataStore::setFilename(const QString& filename) {
  _disk.setFilename(filename);
}


DiskStore* DataStore::diskStore() {
  return &_disk;
}


bool DataStore::reload() {
  if (_disk.filename().isEmpty()) {
    emit error("no filename");
    return false;
  }
  
  _cache.clear();
  foreach(QString key, _disk.leaves()) {
    _cache.insert(key, _disk[key]);
  }
  
  return true;
}

bool DataStore::save() {
  if (_disk.filename().isEmpty()) {
    emit error("no filename");
    return false;
  }
  
  foreach(QString key, _cache.keys()) {
    _disk.insert(key, _cache.value(key));
  }
  
  return true;
}


const QString DataStore::operator[](const QString& key) const {
  return _cache.value(key);
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
