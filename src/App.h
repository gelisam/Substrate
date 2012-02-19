#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>

#include "Oven.h"
#include "widget/MainWindow.h"


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  Oven* _oven;
  MainWindow* _mainWindow;
  
public:
  Application(int argc, char** argv);
  ~Application();
  
  void init();
  void run();
  
  void errorMessage(const QString& message) const;
  
  Oven* oven() const;
  MainWindow* mainWindow() const;
  
  InputEditor* inputEditor() const;
  ScriptEditor* scriptEditor() const;
};

extern Application* app;

#endif
