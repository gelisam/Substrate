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
  
  hello = new QPushButton("Hello World");
}

void Application::Application::run() {
  hello->show();
  
  exec();
}
