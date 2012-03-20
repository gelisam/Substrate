#ifndef LOCAL_STORE_H
#define LOCAL_STORE_H

#include <QtCore/QObject>

#include "store/DataStore.h"


class LocalStore : public QObject
{
  Q_OBJECT;
  
private:
  DataStore& _store;
  QString _path;
  
public:
  LocalStore(DataStore& store);
  LocalStore(DataStore& store, const QString& localPath);
  LocalStore(const LocalStore& store, const QString& localPath);
  LocalStore(const LocalStore& that);
  
  const QString operator[](const QString& key) const;
  QString take(const QString& key); // removes the entry
  void insert(const QString& key, const QString& value);
  
  bool isKeyValid(const QString& key) const;
  bool contains(const QString& key) const;
  void remove(const QString& key);
};

#endif
