#include "widget/CentralWidget.h"


CentralWidget::CentralWidget(QWidget* parent)
: QWidget(parent)
, _layout(new QVBoxLayout(this))
, _scriptEditor(new ScriptEditor(this))
{
  _layout->addWidget(_scriptEditor);
}

void CentralWidget::init() {
  _scriptEditor->init();
}


ScriptEditor* CentralWidget::scriptEditor() const {
  return _scriptEditor;
}
