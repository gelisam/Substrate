#include "menu/RunMenu.h"


RunMenu::RunMenu(QWidget* parent)
: QMenu("&Run", parent)
, _runTruncatedAction(new RunTruncatedAction(this))
, _runAction(new RunAction(this))
{
  addAction(_runTruncatedAction);
  addAction(_runAction);
}

void RunMenu::init() {
  _runTruncatedAction->init();
  _runAction->init();
}


RunTruncatedAction* RunMenu::runTruncatedAction() const {
  return _runTruncatedAction;
}

RunAction* RunMenu::runAction() const {
  return _runAction;
}
