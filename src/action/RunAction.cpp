#include "action/RunAction.h"

#include "App.h"


RunAction::RunAction(QObject* parent)
: QAction("Run &Entire Script", parent)
{
}

void RunAction::init() {
  setShortcut(QKeySequence("Shift+F5"));
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunAction::act() {
  QTextEdit* textEdit = app->mainWindow()->textEditWidget();
  app->oven()->cook(textEdit->toPlainText());
}
