#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>

#include "MainWindow.h"


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  MainWindow* mainWindow;
  
public:
  Application(int argc, char** argv);
  ~Application();
  
  void run();
};

extern Application* app;

#endif
