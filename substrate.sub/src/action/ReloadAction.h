#ifndef RELOAD_ACTION_H
#define RELOAD_ACTION_H

#include <QtGui/QAction>


class ReloadAction : public QAction
{
  Q_OBJECT;
  
public:
  ReloadAction(QObject* parent);
  void init();
  
private slots:
  void act();
};

#endif
