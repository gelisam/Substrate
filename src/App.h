#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGui/QApplication>
#include <QtGui/QTextEdit>


class Application : public QApplication
{
  Q_OBJECT;
  
private:
  QTextEdit* textEditWidget;
  
public:
  Application(int argc, char** argv);
  ~Application();
  
  void run();
};

extern Application* app;

#endif
