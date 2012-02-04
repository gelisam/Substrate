#include "App.h"


Application* app = NULL;

Application::Application(int argc, char** argv)
: QApplication(argc, argv)
{
  app = this;
  
  setOrganizationName("Bloggy Badger");
  setOrganizationDomain("gelisam.blogspot.com");
  setApplicationName("Substrate");
  
  // initialize fields here instead of the init list
  // so that constructors can access the app global.
  
  textEditWidget = new QTextEdit("Hello World");
}

Application::~Application() {
  delete textEditWidget;
}

void Application::Application::run() {
  textEditWidget->show();
  
  exec();
}
