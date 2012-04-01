#include "widget/TextEditor.h"

#include <QtCore/QFile>


TextEditor::TextEditor(QWidget* parent)
: QTextEdit(parent)
{
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
  emit error(file.errorString());
  return false;
}
