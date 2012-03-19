#include "DataStore.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include <assert.h>


DataStore::DataStore(QObject* parent)
: QObject(parent)
{
}


QString DataStore::filename() const {
  return _filename;
}

void DataStore::setFilename(QString filename) {
  _filename = filename;
}


bool DataStore::reload() {
  if (_filename.isEmpty()) {
    app->errorMessage("no filename");
    return false;
  }
  
  QMap<QString, QString> cache;
  
  QDir dir(_filename);
  foreach(QString entry, dir.entryList(QDir::Files)) {
    QString filename = dir.absoluteFilePath(entry);
    QFile file(filename);
    
    if (file.open(QFile::ReadOnly)) {
      QTextStream in(&file);
      
      QString key = QString("/%1").arg(entry);
      QString value = in.readAll();
      
      cache.insert(key, value);
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
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
    QString filename = QString(key);
    QFile file(dir.absoluteFilePath(filename));
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


const QString DataStore::operator[](QString key) const {
  return _cache.value(key);
}

QString DataStore::take(QString key) {
  return _cache.take(key);
}

void DataStore::insert(QString key, QString value) {
  assert(isKeyValid(key));
  
  _cache.insert(key, value);
}


bool DataStore::isKeyValid(QString key) const {
  if (!key.startsWith(QChar('/'))) return false;
  if (key.count(QChar('/')) != 1) return false;
  if (key.contains(QChar('\n'))) return false;
  if (key.contains(QChar(' '))) return false;
  if (key.contains(QChar(':'))) return false;
  
  return true;
}

bool DataStore::contains(QString key) const {
  return _cache.contains(key);
}

void DataStore::remove(QString key) {
  _cache.remove(key);
}

void DataStore::clear() {
  _cache.clear();
}
