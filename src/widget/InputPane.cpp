#include "widget/InputPane.h"


InputPane::InputPane(QWidget* parent)
: QTabWidget(parent)
{
  addTab(new InputEditor(this), "Input");
}

void InputPane::init() {
  currentInputEditor()->init();
}


InputEditor* InputPane::currentInputEditor() const {
  return qobject_cast<InputEditor*>(currentWidget());
}
