#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _textEditWidget(new QTextEdit("Hello World"))
{
  setCentralWidget(_textEditWidget);
}

QTextEdit* MainWindow::textEditWidget() const {
  return _textEditWidget;
}
