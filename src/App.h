#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>

#include "widget/MainWindow.h"


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  MainWindow* _mainWindow;
  
public:
  Application(int argc, char** argv);
  ~Application();
  
  void init();
  void run();
  
  void errorMessage(const QString& message) const;
  
  MainWindow* mainWindow() const;
};

extern Application* app;

#endif
