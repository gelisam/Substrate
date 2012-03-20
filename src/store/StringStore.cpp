#include "StringStore.h"


StringStore::StringStore(const LocalStore& store)
: QObject(NULL)
, _store(store)
{
}


const QString StringStore::value() const {
  return _store[""];
}

void StringStore::setValue(const QString& value) {
  _store.insert("", value);
}
