#ifndef INT_STORE_H
#define INT_STORE_H

#include "store/PrimitiveStore.h"


class IntStore : public PrimitiveStore<int>
{
protected:
  virtual QString toString() const;
  virtual bool fromString(const QString&);
  
public:
  IntStore(const LocalStore& store);
};

#endif
