#include "StringStore.h"


StringStore::StringStore(const LocalStore& store)
: PrimitiveStore<QString>(store)
{
}


QString StringStore::toString() const {
  return _value;
}

bool StringStore::fromString(const QString& s) {
  _value = s;
  return true;
}
