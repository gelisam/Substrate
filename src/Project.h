#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>

#include "store/DataStore.h"


class Project : public QObject
{
  Q_OBJECT;
  
private:
  DataStore _dataStore;
  
public:
  Project(QObject* parent);
  
  void init();
  
  QString filename() const;
  void setFilename(QString filename);
  
  bool reload();
  bool save();
};

#endif
