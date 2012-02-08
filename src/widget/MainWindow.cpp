#include "widget/MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, _menuBar(new MenuBar(this))
, _textEditor(new TextEditor(this))
, _statusBar(new StatusBar(this))
{
  setMenuBar(_menuBar);
  setCentralWidget(_textEditor);
  setStatusBar(_statusBar);
}

void MainWindow::init() {
  _menuBar->init();
  _statusBar->init();
}


MenuBar* MainWindow::menuBar() const {
  return _menuBar;
}

TextEditor* MainWindow::textEditor() const {
  return _textEditor;
}

StatusBar* MainWindow::statusBar() const {
  return _statusBar;
}
