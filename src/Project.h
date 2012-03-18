#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>


class Project : public QObject
{
  Q_OBJECT;
  
private:
  QString _filename;
  
public:
  Project(QObject* parent=0);
  
  void init();
  
  QString filename() const;
  void setFilename(QString filename);
  
  bool reload();
  bool save() const;
};

#endif
