#ifndef OPEN_ACTION_H
#define OPEN_ACTION_H

#include <QtGui/QAction>


class OpenAction : public QAction
{
  Q_OBJECT;
  
public:
  OpenAction(QObject* parent=0);
  
  void init();
  
private slots:
  void act();
};

#endif
