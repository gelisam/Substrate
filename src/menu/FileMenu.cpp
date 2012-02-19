#include "menu/FileMenu.h"


FileMenu::FileMenu(QWidget* parent)
: QMenu("&File", parent)
, _openAction(new OpenAction(this))
, _quitAction(new QuitAction(this))
{
  addAction(_openAction);
  addSeparator();
  addAction(_quitAction);
}

void FileMenu::init() {
  _openAction->init();
  _quitAction->init();
}


OpenAction* FileMenu::openAction() const {
  return _openAction;
}

QuitAction* FileMenu::quitAction() const {
  return _quitAction;
}
