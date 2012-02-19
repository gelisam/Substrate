#include "widget/TextEditor.h"

#include "App.h"

#include <QtCore/QFile>


TextEditor::TextEditor(QWidget* parent)
: QTextEdit(parent)
{
}

void TextEditor::init() {
}


bool TextEditor::open(const QString& filename) {
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QString contents = QString::fromUtf8(file.readAll());
    if (file.error() == QFile::NoError) {
      setDocumentTitle(filename);
      setPlainText(contents);
      
      // success!
      return true;
    }
  }
  
  // error.
  app->errorMessage(file.errorString());
  return false;
}
