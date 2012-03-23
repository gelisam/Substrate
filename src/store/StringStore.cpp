#include "StringStore.h"


StringStore::StringStore(const LocalStore& store)
: SpecializedStore(store)
, _value()
{
}


const QString StringStore::value() const {
  return _value;
}

void StringStore::setValue(const QString& value) {
  _value = value;
}


void StringStore::flush() {
  _store.insert("", _value);
}

bool StringStore::reload() {
  _value = _store[""];
  return true;
}
