#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>

#include "menu/MenuBar.h"
#include "widget/ScriptEditor.h"
#include "widget/StatusBar.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  MenuBar* _menuBar;
  ScriptEditor* _scriptEditor;
  StatusBar* _statusBar;
  
public:
  MainWindow(QWidget* parent=0);
  
  void init();
  
  MenuBar* menuBar() const;
  ScriptEditor* scriptEditor() const;
  StatusBar* statusBar() const;
};

#endif
