#include "App.h"


Application* app = NULL;

Application::Application(int argc, char** argv)
: QApplication(argc, argv)
, _oven(new Oven(this))
, _project(new Project(this))
, _mainWindow(new MainWindow(NULL))
{
  app = this;
}

void Application::init() {
  setOrganizationName("Bloggy Badger");
  setOrganizationDomain("gelisam.blogspot.com");
  setApplicationName("Substrate");
  
  // initialize fields here instead of in the constructor
  // so that child initializations can access the app global.
  _oven->init();
  _project->init();
  _mainWindow->init();
  
  connect(_oven,       SIGNAL(error(const QString&)),
          this,        SLOT(errorMessage(const QString&)));
  connect(_project,    SIGNAL(error(const QString&)),
          this,        SLOT(errorMessage(const QString&)));
  connect(_mainWindow, SIGNAL(error(const QString&)),
          this,        SLOT(errorMessage(const QString&)));
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


Oven* Application::oven() const {
  return _oven;
}

Project* Application::project() const {
  return _project;
}

MainWindow* Application::mainWindow() const {
  return _mainWindow;
}


InputEditor* Application::currentInputEditor() const {
  return _mainWindow->centralWidget()->inputPane()->currentInputEditor();
}

ScriptEditor* Application::scriptEditor() const {
  return _mainWindow->centralWidget()->scriptEditor();
}


void Application::errorMessage(const QString& message) {
  _mainWindow->statusBar()->errorMessage(message);
}
