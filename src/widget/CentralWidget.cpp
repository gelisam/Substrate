#include "widget/CentralWidget.h"


CentralWidget::CentralWidget(QWidget* parent)
: QWidget(parent)
, _layout(new QVBoxLayout(this))
, _inputPane(new InputPane(this))
, _scriptEditor(new ScriptEditor(this))
{
  _layout->addWidget(_inputPane);
  _layout->addWidget(_scriptEditor);
}

void CentralWidget::init() {
  _inputPane->init();
  _scriptEditor->init();
}


InputPane* CentralWidget::inputPane() const {
  return _inputPane;
}

ScriptEditor* CentralWidget::scriptEditor() const {
  return _scriptEditor;
}
