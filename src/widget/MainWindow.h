#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>

#include "menu/MenuBar.h"
#include "widget/CentralWidget.h"
#include "widget/StatusBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  CentralWidget* _centralWidget;
  StatusBar* _statusBar;
  
public:
  MainWindow(QWidget* parent);
  void init();
  
  MenuBar* menuBar() const;
  CentralWidget* centralWidget() const;
  StatusBar* statusBar() const;
};

#endif
