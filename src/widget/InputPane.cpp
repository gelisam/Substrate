#include "widget/InputPane.h"


InputPane::InputPane(QWidget* parent)
: QTabWidget(parent)
{
  addTab(new InputEditor(this), "Input");
}

void InputPane::init() {
  currentInputEditor()->init();
}


InputEditor* InputPane::addInputEditor(QString initialContents) {
  InputEditor* inputEditor = new InputEditor(this);
  inputEditor->setPlainText(initialContents);
  
  int tabIndex = addTab(inputEditor, "Input");
  setCurrentIndex(tabIndex);
  
  return inputEditor;
}

InputEditor* InputPane::currentInputEditor() const {
  return qobject_cast<InputEditor*>(currentWidget());
}
