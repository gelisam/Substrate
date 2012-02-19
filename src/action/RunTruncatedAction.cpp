#include "action/RunTruncatedAction.h"

#include "App.h"

#include <QtGui/QTextEdit>
#include <QtGui/QTextCursor>
#include <QtGui/QTextDocumentFragment>


RunTruncatedAction::RunTruncatedAction(QObject* parent)
: QAction("Up to &Current Line", parent)
{
}

void RunTruncatedAction::init() {
  setShortcut(QKeySequence("F5"));
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


static QString preprocessScript(QString scriptContents) {
  if (scriptContents.endsWith("|")) {
    scriptContents.chop(1);
  }
  
  return scriptContents;
}

void RunTruncatedAction::act() {
  QTextEdit* inputEditor = app->inputEditor();
  QTextEdit* scriptEditor = app->scriptEditor();
  
  QString input = inputEditor->toPlainText();
  
  QTextCursor cursor = scriptEditor->textCursor();
  
  // Truncate up to and including the current line
  cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
  cursor.movePosition(QTextCursor::Start, QTextCursor::KeepAnchor);
  
  QTextDocumentFragment selection = cursor.selection();
  QString scriptContents = preprocessScript(selection.toPlainText());
  
  app->oven()->cook(input, scriptContents);
}
