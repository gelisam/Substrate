#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>

#include "MenuBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  QTextEdit* _textEditWidget;
  
public:
  MainWindow(QWidget* parent=0);
  
  MenuBar* menuBar() const;
  QTextEdit* textEditWidget() const;
};

#endif
