#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>
#include <QtGui/QPushButton>


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  QPushButton* hello;
  
public:
  Application(int argc, char** argv);
  
  void run();
};

extern Application* app;

#endif
