#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>

#include "store/DataStore.h"
#include "store/LocalStore.h"
#include "store/StringStore.h"
#include "store/IntStore.h"
#include "store/ArrayStore.h"


class Project : public QObject
{
  Q_OBJECT;
  
private:
  DataStore _dataStore;
  LocalStore _store;
  
  StringStore _version;
  ArrayStore<StringStore> _inputs;
  IntStore _input;
  StringStore _script;
  
public:
  Project(QObject* parent);
  
  void init();
  
  QString filename() const;
  void setFilename(QString filename);
  
public slots:
  bool reload();
  bool save();
  
private slots:
  void emitError(const QString&);
  
signals:
  void error(const QString&);
};

#endif
