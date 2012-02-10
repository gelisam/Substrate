#include "widget/TextEditor.h"

#include "App.h"

#include <QtCore/QFile>
#include <QtGui/QTextCursor>
#include <QtGui/QTextCharFormat>


TextEditor::TextEditor(QWidget* parent)
: QTextEdit(parent)
{
}

void TextEditor::init() {
  open(":/resources/demo.sh");
  
  // clear undo buffer
  setUndoRedoEnabled(false);
  setUndoRedoEnabled(true);
  
  connect(this, SIGNAL(cursorPositionChanged()),
          this, SLOT(colorize()));
}


void TextEditor::open(const QString& filename) {
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QString contents = QString::fromUtf8(file.readAll());
    if (file.error() == QFile::NoError) {
      setDocumentTitle(filename);
      setPlainText(contents);
      
      // success!
      colorize();
      return;
    }
  }
  
  // error.
  app->errorMessage(file.errorString());
}

void TextEditor::keyPressEvent(QKeyEvent* e) {
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


void TextEditor::colorize() {
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
