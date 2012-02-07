#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>
#include <QtGui/QStatusBar>

#include "menu/MenuBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  QTextEdit* _textEditWidget;
  QStatusBar* _statusBar;
  
public:
  MainWindow(QWidget* parent=0);
  
  void init();
  
  MenuBar* menuBar() const;
  QTextEdit* textEditWidget() const;
  QStatusBar* statusBar() const;
};

#endif
