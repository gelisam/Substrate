#include "action/SaveAction.h"

#include "App.h"

#include <QtGui/QFileDialog>


SaveAction::SaveAction(QObject* parent)
: QAction("&Save", parent)
{
}

void SaveAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void SaveAction::act() {
  Project* project = app->project();
  if (project->filename().isEmpty()) {
    app->mainWindow()->menuBar()->fileMenu()->saveAsAction()->trigger();
  } else {
    project->save();
  }
}
