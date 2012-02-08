#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>

#include "menu/MenuBar.h"
#include "widget/TextEditor.h"
#include "widget/StatusBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  TextEditor* _textEditor;
  StatusBar* _statusBar;
  
public:
  MainWindow(QWidget* parent=0);
  
  void init();
  
  MenuBar* menuBar() const;
  TextEditor* textEditor() const;
  StatusBar* statusBar() const;
};

#endif
