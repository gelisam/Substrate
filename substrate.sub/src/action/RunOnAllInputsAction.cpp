#include "action/RunOnAllInputsAction.h"

#include "App.h"


RunOnAllInputsAction::RunOnAllInputsAction(QObject* parent)
: QAction("On &All Inputs", parent)
{
}

void RunOnAllInputsAction::init() {
  setShortcut(QKeySequence("Shift+F5"));
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunOnAllInputsAction::act() {
  ScriptEditor* scriptEditor = app->scriptEditor();
  QString scriptContents = scriptEditor->truncatedContents();
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  for(int i=0; i<inputPane->count(); ++i) {
    InputEditor* inputEditor = qobject_cast<InputEditor*>(inputPane->widget(i));
    QString input = inputEditor->toPlainText();
    
    app->oven()->cook(input, scriptContents);
  }
}
