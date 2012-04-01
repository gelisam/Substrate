#include "menu/RunMenu.h"


RunMenu::RunMenu(QWidget* parent)
: QMenu("&Run", parent)
, _runTruncatedAction(new RunTruncatedAction(this))
, _runAction(new RunAction(this))
, _runOnAllInputsAction(new RunOnAllInputsAction(this))
{
  addAction(_runTruncatedAction);
  addAction(_runAction);
  addAction(_runOnAllInputsAction);
}

void RunMenu::init() {
  _runTruncatedAction->init();
  _runAction->init();
  _runOnAllInputsAction->init();
}


RunTruncatedAction* RunMenu::runTruncatedAction() const {
  return _runTruncatedAction;
}

RunAction* RunMenu::runAction() const {
  return _runAction;
}

RunOnAllInputsAction* RunMenu::runOnAllInputsAction() const {
  return _runOnAllInputsAction;
}
