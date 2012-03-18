#include "action/OpenAction.h"

#include "App.h"

#include <QtGui/QFileDialog>


OpenAction::OpenAction(QObject* parent)
: QAction("&Open", parent)
{
}

void OpenAction::init() {
  setShortcut(QKeySequence::Open);
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void OpenAction::act() {
  QString dirname = QFileDialog::getExistingDirectory(app->mainWindow());
  if (!dirname.isNull()) {
    Project* project = app->project();
    project->setFilename(dirname);
    project->reload();
  }
}
