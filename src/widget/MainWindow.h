#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>

#include "menu/MenuBar.h"
#include "widget/StatusBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  QTextEdit* _textEditWidget;
  StatusBar* _statusBar;
  
public:
  MainWindow(QWidget* parent=0);
  
  void init();
  
  MenuBar* menuBar() const;
  QTextEdit* textEditWidget() const;
  StatusBar* statusBar() const;
};

#endif
