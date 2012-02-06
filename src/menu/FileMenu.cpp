#include "menu/FileMenu.h"


FileMenu::FileMenu(QWidget* parent)
: QMenu("&File", parent)
, _openAction(new OpenAction(this))
, _runAction(new RunAction(this))
, _quitAction(new QuitAction(this))
{
  addAction(_openAction);
  addAction(_runAction);
  addSeparator();
  addAction(_quitAction);
}

void FileMenu::init() {
  _openAction->init();
  _runAction->init();
  _quitAction->init();
}


OpenAction* FileMenu::openAction() const {
  return _openAction;
}

RunAction* FileMenu::runAction() const {
  return _runAction;
}

QuitAction* FileMenu::quitAction() const {
  return _quitAction;
}
