#include "widget/InputPane.h"


InputPane::InputPane(QWidget* parent)
: QTabWidget(parent)
, _inputEditor(new InputEditor(this))
{
  addTab(_inputEditor, "Input");
}

void InputPane::init() {
  _inputEditor->init();
}


InputEditor* InputPane::inputEditor() const {
  return _inputEditor;
}
