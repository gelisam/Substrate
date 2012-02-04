#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, textEditWidget(new QTextEdit("Hello World"))
{
  setCentralWidget(textEditWidget);
}
