#include "LocalStore.h"

#include <assert.h>


LocalStore::LocalStore(DataStore& store)
: QObject(NULL)
, _store(store)
, _path("")
{
}

LocalStore::LocalStore(DataStore& store, const QString& relativePath)
: QObject(NULL)
, _store(store)
, _path(relativePath)
{
  assert(isKeyValid(relativePath));
}

LocalStore::LocalStore(const LocalStore& store, const QString& relativePath)
: QObject(NULL)
, _store(store._store)
, _path(store._path + relativePath)
{
  assert(isKeyValid(relativePath));
  assert(isKeyValid(_path));
}

LocalStore::LocalStore(const LocalStore& that)
: QObject(NULL)
, _store(that._store)
, _path(that._path)
{
}

LocalStore LocalStore::path(const QString& localPath) const {
  return LocalStore(*this, localPath);
}


const QString LocalStore::operator[](const QString& key) const {
  assert(isKeyValid(key));
  return _store[_path+key];
}

QString LocalStore::take(const QString& key) {
  assert(isKeyValid(key));
  return _store.take(_path+key);
}

void LocalStore::insert(const QString& key, const QString& value) {
  assert(isKeyValid(key));
  _store.insert(_path+key, value);
}


bool LocalStore::isKeyValid(const QString& key) const {
  if (key.isNull()) return false;
  if (key.isEmpty()) return true;
  
  if (key.startsWith(QChar('/'))) return true; // close enough...
  return _store.isKeyValid(key);
}


bool LocalStore::contains(const QString& key) const {
  return _store.contains(_path+key);
}

void LocalStore::remove(const QString& key) {
  _store.remove(_path+key);
}
