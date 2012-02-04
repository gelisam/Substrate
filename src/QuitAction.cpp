#include "QuitAction.h"
#include "App.h"


QuitAction::QuitAction(QObject* parent)
: QAction("&Quit", parent)
{
}

void QuitAction::init() {
  connect(this,              SIGNAL(triggered()),
          app->mainWindow(), SLOT(close()));
}
