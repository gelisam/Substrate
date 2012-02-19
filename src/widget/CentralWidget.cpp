#include "widget/CentralWidget.h"


CentralWidget::CentralWidget(QWidget* parent)
: QWidget(parent)
, _layout(new QVBoxLayout(this))
, _inputEditor(new InputEditor(this))
, _scriptEditor(new ScriptEditor(this))
{
  _layout->addWidget(_inputEditor);
  _layout->addWidget(_scriptEditor);
}

void CentralWidget::init() {
  _inputEditor->init();
  _scriptEditor->init();
}


InputEditor* CentralWidget::inputEditor() const {
  return _inputEditor;
}

ScriptEditor* CentralWidget::scriptEditor() const {
  return _scriptEditor;
}
