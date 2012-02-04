#include "App.h"


Application* app = NULL;

Application::Application(int argc, char** argv)
: QApplication(argc, argv)
, _mainWindow(new MainWindow)
{
  app = this;
}

void Application::init() {
  setOrganizationName("Bloggy Badger");
  setOrganizationDomain("gelisam.blogspot.com");
  setApplicationName("Substrate");
  
  // initialize fields here instead of in the constructor
  // so that child initializations can access the app global.
  _mainWindow->init();
}

Application::~Application() {
  // we need to explicitly delete _mainWindow because we can't
  // pass this object as its constructor; we are not a QWidget.
  delete _mainWindow;
}


void Application::Application::run() {
  _mainWindow->show();
  
  exec();
}


MainWindow* Application::mainWindow() const {
  return _mainWindow;
}
