#include "menu/ProjectMenu.h"


ProjectMenu::ProjectMenu(QWidget* parent)
: QMenu("&Project", parent)
, _addInputAction(new AddInputAction(this))
{
  addAction(_addInputAction);
}

void ProjectMenu::init() {
  _addInputAction->init();
}


AddInputAction* ProjectMenu::addInputAction() const {
  return _addInputAction;
}
