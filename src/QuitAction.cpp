#include "QuitAction.h"
#include "App.h"


QuitAction::QuitAction(QObject* parent)
: QAction("&Quit", parent)
{
  connect(this, SIGNAL(triggered()), app->mainWindow(), SLOT(close()));
}
