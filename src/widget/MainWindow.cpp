#include "widget/MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _textEditWidget(new QTextEdit("Hello World", this))
, _statusBar(new QStatusBar(this))
{
  setMenuBar(_menuBar);
  setCentralWidget(_textEditWidget);
  setStatusBar(_statusBar);
}

void MainWindow::init() {
  _menuBar->init();
}


MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

QTextEdit* MainWindow::textEditWidget() const {
  return _textEditWidget;
}

QStatusBar* MainWindow::statusBar() const {
  return _statusBar;
}
