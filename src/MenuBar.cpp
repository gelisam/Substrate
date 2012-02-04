#include "MenuBar.h"


MenuBar::MenuBar(QWidget* parent)
: QMenuBar(parent)
, _fileMenu(new FileMenu(this))
{
  addMenu(_fileMenu);
}

FileMenu* MenuBar::fileMenu() const {
  return _fileMenu;
}
