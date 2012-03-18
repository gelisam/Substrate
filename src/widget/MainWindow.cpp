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


void MainWindow::changeEvent(QEvent* event) {
  if (event->type() == QEvent::ActivationChange) {
    if (isActiveWindow()) {
      emit activated();
    } else {
      emit deactivated();
    }
  }
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
