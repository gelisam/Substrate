#ifndef RUN_MENU_H
#define RUN_MENU_H

#include <QtGui/QMenu>

#include "action/RunTruncatedAction.h"
#include "action/RunAction.h"
#include "action/RunOnAllInputsAction.h"


class RunMenu : public QMenu
{
  Q_OBJECT;
  
private:
  RunTruncatedAction* _runTruncatedAction;
  RunAction* _runAction;
  RunOnAllInputsAction* _runOnAllInputsAction;
  
public:
  RunMenu(QWidget* parent);
  void init();
  
  RunTruncatedAction* runTruncatedAction() const;
  RunAction* runAction() const;
  RunOnAllInputsAction* runOnAllInputsAction() const;
};

#endif
