#include "widget/MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _scriptEditor(new ScriptEditor(this))
, _statusBar(new StatusBar(this))
{
  setMenuBar(_menuBar);
  setCentralWidget(_scriptEditor);
  setStatusBar(_statusBar);
}

void MainWindow::init() {
  _menuBar->init();
  _scriptEditor->init();
  _statusBar->init();
}


MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

ScriptEditor* MainWindow::scriptEditor() const {
  return _scriptEditor;
}

StatusBar* MainWindow::statusBar() const {
  return _statusBar;
}
