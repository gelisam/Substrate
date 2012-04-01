#include "widget/ScriptEditor.h"

#include "App.h"

#include <QtGui/QTextCursor>
#include <QtGui/QTextCharFormat>
#include <QtGui/QTextDocumentFragment>


ScriptEditor::ScriptEditor(QWidget* parent)
: TextEditor(parent)
{
  // clear undo buffer
  setUndoRedoEnabled(false);
  setUndoRedoEnabled(true);
  
  connect(this, SIGNAL(cursorPositionChanged()),
          this, SLOT(colorize()));
}


bool ScriptEditor::open(const QString& filename) {
  if (TextEditor::open(filename)) {
    // success!
    colorize();
    return true;
  }
  
  // error.
  return false;
}


QString ScriptEditor::preprocessScript(QString scriptContents) {
  if (scriptContents.endsWith("|")) {
    scriptContents.chop(1);
  }
  
  return scriptContents;
}

QString ScriptEditor::truncatedContents() const {
  QTextCursor cursor = textCursor();
  
  // Truncate up to and including the current line
  cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
  cursor.movePosition(QTextCursor::Start, QTextCursor::KeepAnchor);
  
  QTextDocumentFragment selection = cursor.selection();
  return preprocessScript(selection.toPlainText());
}


void ScriptEditor::keyPressEvent(QKeyEvent* e) {
  if (e == QKeySequence::Undo) {
    QTextEdit::keyPressEvent(e);
  } else {
    textCursor().beginEditBlock();
    {
      QTextEdit::keyPressEvent(e);
      colorize();
    }
    textCursor().endEditBlock();
  }
}


void ScriptEditor::colorize() {
  QTextCursor cursor = textCursor();
  cursor.joinPreviousEditBlock();
  {
    QTextCharFormat format;
    
    // Highlight up to and including the current line
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
    cursor.movePosition(QTextCursor::Start, QTextCursor::KeepAnchor);
    
    cursor.setCharFormat(format);
    
    // Gray-out the remainder of the document
    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    
    format.setForeground(QColor(192, 192, 192));
    cursor.setCharFormat(format);
  }
  textCursor().endEditBlock();
}
