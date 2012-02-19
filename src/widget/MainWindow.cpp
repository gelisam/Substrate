#include "widget/MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _centralWidget(new CentralWidget(this))
, _statusBar(new StatusBar(this))
{
  setMenuBar(_menuBar);
  setCentralWidget(_centralWidget);
  setStatusBar(_statusBar);
}

void MainWindow::init() {
  _menuBar->init();
  _centralWidget->init();
  _statusBar->init();
}


MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

CentralWidget* MainWindow::centralWidget() const {
  return _centralWidget;
}

StatusBar* MainWindow::statusBar() const {
  return _statusBar;
}
