#include "action/ReloadAction.h"

#include "App.h"

#include <QtGui/QFileDialog>


ReloadAction::ReloadAction(QObject* parent)
: QAction("&Reload", parent)
{
}

void ReloadAction::init() {
  setShortcut(QKeySequence::Open);
  
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void ReloadAction::act() {
  Project* project = app->project();
  if (!project->filename().isEmpty()) {
    project->reload();
  }
}
