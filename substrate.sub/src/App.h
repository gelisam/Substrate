#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>

#include "Oven.h"
#include "Project.h"
#include "widget/MainWindow.h"


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  Oven* _oven;
  Project* _project;
  MainWindow* _mainWindow;
  
public:
  Application(int argc, char** argv);
  ~Application();
  
  void init();
  void run();
  
  Oven* oven() const;
  Project* project() const;
  MainWindow* mainWindow() const;
  
  InputEditor* currentInputEditor() const;
  ScriptEditor* scriptEditor() const;
  
public slots:
  void errorMessage(const QString&);
};

extern Application* app;

#endif
