#include "action/AddInputAction.h"

#include "App.h"


AddInputAction::AddInputAction(QObject* parent)
: QAction("Add &Input", parent)
{
}

void AddInputAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void AddInputAction::act() {
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  
  int tabIndex = inputPane->addTab(new InputEditor(inputPane), "Input");
  inputPane->setCurrentIndex(tabIndex);
}
