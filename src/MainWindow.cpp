#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _textEditWidget(new QTextEdit("Hello World"))
{
  setMenuBar(_menuBar);
  setCentralWidget(_textEditWidget);
}

MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

QTextEdit* MainWindow::textEditWidget() const {
  return _textEditWidget;
}
