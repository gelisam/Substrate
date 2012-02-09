#include "widget/TextEditor.h"

#include "App.h"

#include <QtCore/QFile>


TextEditor::TextEditor(QWidget* parent)
: QTextEdit(parent)
{
}

void TextEditor::init() {
  open(":/resources/demo.sh");
}


void TextEditor::open(const QString& filename) {
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QString contents = QString::fromUtf8(file.readAll());
    if (file.error() == QFile::NoError) {
      setDocumentTitle(filename);
      setPlainText(contents);
      
      // success!
      return;
    }
  }
  
  // error.
  app->errorMessage(file.errorString());
}
