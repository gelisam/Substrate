#include "widget/MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _textEditWidget(new QTextEdit("Hello World", this))
, _statusBar(new StatusBar(this))
{
  setMenuBar(_menuBar);
  setCentralWidget(_textEditWidget);
  setStatusBar(_statusBar);
}

void MainWindow::init() {
  _menuBar->init();
  _statusBar->init();
}


MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

QTextEdit* MainWindow::textEditWidget() const {
  return _textEditWidget;
}

StatusBar* MainWindow::statusBar() const {
  return _statusBar;
}
