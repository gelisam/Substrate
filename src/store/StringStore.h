#ifndef STRING_STORE_H
#define STRING_STORE_H

#include <QtCore/QObject>

#include "store/LocalStore.h"


class StringStore : public QObject
{
  Q_OBJECT;
  
private:
  LocalStore _store;
  
public:
  StringStore(const LocalStore& store);
  
  const QString value() const;
  void setValue(const QString& value);
};

#endif
