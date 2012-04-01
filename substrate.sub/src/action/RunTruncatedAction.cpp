#include "action/RunTruncatedAction.h"

#include "App.h"


RunTruncatedAction::RunTruncatedAction(QObject* parent)
: QAction("Up to &Current Line", parent)
{
}

void RunTruncatedAction::init() {
  setShortcut(QKeySequence("F5"));
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunTruncatedAction::act() {
  InputEditor* inputEditor = app->currentInputEditor();
  ScriptEditor* scriptEditor = app->scriptEditor();
  
  QString inputContents = inputEditor->toPlainText();
  QString scriptContents = scriptEditor->truncatedContents();
  
  app->oven()->cook(inputContents, scriptContents);
}
