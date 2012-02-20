#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>


class Project : public QObject
{
  Q_OBJECT;
  
public:
  Project(QObject* parent=0);
  
  void init();
  bool load(QString dirname);
  bool save(QString dirname) const;
};

#endif
