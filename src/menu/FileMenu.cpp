#include "menu/FileMenu.h"


FileMenu::FileMenu(QWidget* parent)
: QMenu("&File", parent)
, _openAction(new OpenAction(this))
, _reloadAction(new ReloadAction(this))
, _saveAction(new SaveAction(this))
, _saveAsAction(new SaveAsAction(this))
, _quitAction(new QuitAction(this))
{
  addAction(_openAction);
  addAction(_reloadAction);
  addAction(_saveAction);
  addAction(_saveAsAction);
  addSeparator();
  addAction(_quitAction);
}

void FileMenu::init() {
  _openAction->init();
  _reloadAction->init();
  _saveAction->init();
  _saveAsAction->init();
  _quitAction->init();
}


OpenAction* FileMenu::openAction() const {
  return _openAction;
}

ReloadAction* FileMenu::reloadAction() const {
  return _reloadAction;
}

SaveAction* FileMenu::saveAction() const {
  return _saveAction;
}

SaveAsAction* FileMenu::saveAsAction() const {
  return _saveAsAction;
}

QuitAction* FileMenu::quitAction() const {
  return _quitAction;
}
