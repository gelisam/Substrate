#ifndef SPECIALIZED_STORE_H
#define SPECIALIZED_STORE_H

#include <QtCore/QObject>

#include "store/LocalStore.h"


class SpecializedStore : public QObject
{
  Q_OBJECT;
  
protected:
  LocalStore _store;
  
public:
  SpecializedStore(const LocalStore& store);
  
  virtual void flush()=0;
  virtual bool reload()=0;
};

#endif
