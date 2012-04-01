#ifndef OVEN_H
#define OVEN_H

#include <QtCore/QObject>


class Oven : public QObject
{
  Q_OBJECT;
  
public:
  Oven(QObject* parent);
  void init();
  
  void cook(QString inputContents, QString scriptContents);
  
signals:
  void error(const QString&);
};

#endif
