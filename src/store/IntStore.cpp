#include "IntStore.h"


IntStore::IntStore(const LocalStore& store)
: PrimitiveStore<int>(store)
{
}


QString IntStore::toString() const {
  return QString("%1").arg(_value);
}

bool IntStore::fromString(const QString& s) {
  bool r;
  _value = s.toInt(&r);
  return r;
}
