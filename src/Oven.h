#ifndef OVEN_H
#define OVEN_H

#include <QtCore/QObject>


class Oven : public QObject
{
  Q_OBJECT;
  
public:
  Oven(QObject* parent=0);
  
  void init();
  void cook(QString scriptContents);
};

#endif
