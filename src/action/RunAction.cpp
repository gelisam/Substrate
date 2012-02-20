#include "action/RunAction.h"

#include "App.h"


RunAction::RunAction(QObject* parent)
: QAction("&Entire Script", parent)
{
}

void RunAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunAction::act() {
  QTextEdit* inputEditor = app->currentInputEditor();
  QTextEdit* scriptEditor = app->scriptEditor();
  
  QString input = inputEditor->toPlainText();
  QString scriptContents = scriptEditor->toPlainText();
  
  app->oven()->cook(input, scriptContents);
}
