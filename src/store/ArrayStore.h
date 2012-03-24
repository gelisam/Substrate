#ifndef ARRAY_STORE_H
#define ARRAY_STORE_H

#include "store/SpecializedStore.h"

#include <assert.h>


template <class TStore>
class ArrayStore : public SpecializedStore
{
private:
  QList<TStore*> _stores;
  
  static QString key(int i) {
    return QString("%1").arg(i);
  }
  
public:
  ArrayStore(const LocalStore& store)
  : SpecializedStore(store)
  {
  }
  
  ~ArrayStore() {
    foreach(TStore* store, _stores) {
      delete store;
    }
    _stores.clear();
  }
  
  TStore* operator[](int i) const {
    return _stores[i];
  }
  
  TStore* push_back() {
    TStore* r = new TStore(_store.path(key(length())));
    _stores.push_back(r);
    return r;
  }
  
  
  int length() const {
    return _stores.length();
  }
  
  void setLength(int len) {
    assert(len >= 0);
    
    while (length() < len) {
      push_back();
    }
    
    while (length() > len) {
      delete _stores.takeLast();
    }
  }
  
  
  virtual void flush() {
    for(int i=0;; ++i) {
      if (i < length()) {
        _stores[i]->flush();
      } else if (_store.contains(key(i))) {
        _store.remove(key(i));
      } else {
        break;
      }
    }
  }
  
  virtual bool reload() {
    int len;
    for(len=0;
        _store.contains(key(len));
        ++len)
    {}
    setLength(len);
    
    for(int i=0; i<len; ++i) {
      if (!_stores[i]->reload()) return false;
    }
    
    return true;
  }
};

#endif
