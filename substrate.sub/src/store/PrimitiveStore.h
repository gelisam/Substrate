#ifndef PRIMITIVE_STORE_H
#define PRIMITIVE_STORE_H

#include "store/SpecializedStore.h"


template <class T>
class PrimitiveStore : public SpecializedStore
{
protected:
  T _value;
  
  virtual QString toString() const=0;
  virtual bool fromString(const QString&)=0;
  
public:
  PrimitiveStore(const LocalStore& store)
  : SpecializedStore(store)
  {
  }
  
  const T& value() const {
    return _value;
  }
  
  void setValue(const T& value) {
    _value = value;
  }
  
  
  virtual void flush() {
    _store.insert("", toString());
  }
  
  virtual bool reload() {
    return fromString(_store[""]);
  }
};

#endif
