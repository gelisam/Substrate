#include "menu/MenuBar.h"


MenuBar::MenuBar(QWidget* parent)
: QMenuBar(parent)
, _fileMenu(new FileMenu(this))
, _projectMenu(new ProjectMenu(this))
, _runMenu(new RunMenu(this))
{
  addMenu(_fileMenu);
  addMenu(_projectMenu);
  addMenu(_runMenu);
}

void MenuBar::init() {
  _fileMenu->init();
  _projectMenu->init();
  _runMenu->init();
}


FileMenu* MenuBar::fileMenu() const {
  return _fileMenu;
}

ProjectMenu* MenuBar::projectMenu() const {
  return _projectMenu;
}

RunMenu* MenuBar::runMenu() const {
  return _runMenu;
}
