#ifndef RUN_ON_ALL_INPUTS_ACTION_H
#define RUN_ON_ALL_INPUTS_ACTION_H

#include <QtGui/QAction>


class RunOnAllInputsAction : public QAction
{
  Q_OBJECT;
  
public:
  RunOnAllInputsAction(QObject* parent);
  void init();
  
private slots:
  void act();
};

#endif
