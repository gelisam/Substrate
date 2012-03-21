#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>

#include "store/DataStore.h"
#include "store/LocalStore.h"
#include "store/StringStore.h"


class Project : public QObject
{
  Q_OBJECT;
  
private:
  DataStore _dataStore;
  LocalStore _store;
  
  StringStore _version;
  StringStore _script;
  
public:
  Project(QObject* parent);
  
  void init();
  
  QString filename() const;
  void setFilename(QString filename);
  
  bool reload();
  bool save();
};

#endif
