#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>

#include "menu/MenuBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  QTextEdit* _textEditWidget;
  
public:
  MainWindow(QWidget* parent=0);
  
  void init();
  
  MenuBar* menuBar() const;
  QTextEdit* textEditWidget() const;
};

#endif
