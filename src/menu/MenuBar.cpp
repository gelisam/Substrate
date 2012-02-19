#include "menu/MenuBar.h"


MenuBar::MenuBar(QWidget* parent)
: QMenuBar(parent)
, _fileMenu(new FileMenu(this))
, _runMenu(new RunMenu(this))
{
  addMenu(_fileMenu);
  addMenu(_runMenu);
}

void MenuBar::init() {
  _fileMenu->init();
  _runMenu->init();
}


FileMenu* MenuBar::fileMenu() const {
  return _fileMenu;
}

RunMenu* MenuBar::runMenu() const {
  return _runMenu;
}
