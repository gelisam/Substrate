#ifndef STRING_STORE_H
#define STRING_STORE_H

#include "store/PrimitiveStore.h"


class StringStore : public PrimitiveStore<QString>
{
protected:
  virtual QString toString() const;
  virtual bool fromString(const QString&);
  
public:
  StringStore(const LocalStore& store);
};

#endif
