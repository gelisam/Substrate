#ifndef STRING_STORE_H
#define STRING_STORE_H

#include "store/SpecializedStore.h"


class StringStore : public SpecializedStore
{
  Q_OBJECT;
  
private:
  QString _value;
  
public:
  StringStore(const LocalStore& store);
  
  const QString value() const;
  void setValue(const QString& value);
  
  virtual void flush();
  virtual bool reload();
};

#endif
