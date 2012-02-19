#ifndef RUN_MENU_H
#define RUN_MENU_H

#include <QtGui/QMenu>

#include "action/RunTruncatedAction.h"
#include "action/RunAction.h"


class RunMenu : public QMenu
{
  Q_OBJECT;
  
private:
  RunTruncatedAction* _runTruncatedAction;
  RunAction* _runAction;
  
public:
  RunMenu(QWidget* parent=0);
  
  void init();
  
  RunTruncatedAction* runTruncatedAction() const;
  RunAction* runAction() const;
};

#endif
