#include "widget/InputPane.h"


InputPane::InputPane(QWidget* parent)
: QTabWidget(parent)
{
  addTab(new InputEditor(this), "Input");
}

void InputPane::init() {
}


InputEditor* InputPane::addInputEditor(QString initialContents) {
  InputEditor* inputEditor = new InputEditor(this);
  inputEditor->setPlainText(initialContents);
  
  int tabIndex = addTab(inputEditor, "Input");
  setCurrentIndex(tabIndex);
  
  connect(inputEditor, SIGNAL(error(const QString&)),
          this,        SLOT(emitError(const QString&)));
  
  return inputEditor;
}

InputEditor* InputPane::currentInputEditor() const {
  return qobject_cast<InputEditor*>(currentWidget());
}


void InputPane::emitError(const QString& message) {
  emit error(message);
}
