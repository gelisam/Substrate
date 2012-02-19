#include "widget/ScriptEditor.h"

#include "App.h"

#include <QtGui/QTextCursor>
#include <QtGui/QTextCharFormat>


ScriptEditor::ScriptEditor(QWidget* parent)
: TextEditor(parent)
{
}

void ScriptEditor::init() {
  TextEditor::init();
  
  open(":/resources/demo.sh");
  
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
