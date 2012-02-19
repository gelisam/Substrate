#include "menu/FileMenu.h"


FileMenu::FileMenu(QWidget* parent)
: QMenu("&File", parent)
, _openAction(new OpenAction(this))
, _saveAsAction(new SaveAsAction(this))
, _quitAction(new QuitAction(this))
{
  addAction(_openAction);
  addAction(_saveAsAction);
  addSeparator();
  addAction(_quitAction);
}

void FileMenu::init() {
  _openAction->init();
  _saveAsAction->init();
  _quitAction->init();
}


OpenAction* FileMenu::openAction() const {
  return _openAction;
}

SaveAsAction* FileMenu::saveAsAction() const {
  return _saveAsAction;
}

QuitAction* FileMenu::quitAction() const {
  return _quitAction;
}
