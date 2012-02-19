#include "action/RunAction.h"

#include "App.h"


RunAction::RunAction(QObject* parent)
: QAction("&Entire Script", parent)
{
}

void RunAction::init() {
  setShortcut(QKeySequence("Shift+F5"));
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunAction::act() {
  QTextEdit* textEdit = app->mainWindow()->scriptEditor();
  app->oven()->cook(textEdit->toPlainText());
}
