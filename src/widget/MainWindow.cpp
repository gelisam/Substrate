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
  
  // Automatically reload and run when coming back to the app,
  // in case what the user was doing in that other window was
  // editing our files.
  QAction* reloadAction = _menuBar->runMenu()->runAction();
  QAction* runAction    = _menuBar->runMenu()->runAction();
  connect(this,         SIGNAL(activated()),
          reloadAction, SLOT(act()));
  connect(this,         SIGNAL(activated()),
          runAction,    SLOT(trigger()));
  
  // Also save when leaving, otherwise the above is going to
  // drop the user's work every time he switches applications.
  QAction* saveAction = _menuBar->runMenu()->runAction();
  connect(this,       SIGNAL(deactivated()),
          saveAction, SLOT(act()));
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
