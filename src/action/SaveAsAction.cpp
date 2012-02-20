#include "action/SaveAsAction.h"

#include "App.h"

#include <QtGui/QFileDialog>


SaveAsAction::SaveAsAction(QObject* parent)
: QAction("Save &As...", parent)
{
}

void SaveAsAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void SaveAsAction::act() {
  QString filename = QFileDialog::getSaveFileName(
    app->mainWindow(),
    QString(), // default caption
    QString(), // current working directory
    "Substrate folders (*.sub);;All files (*.*)");
  if (!filename.isNull()) {
    if (!filename.endsWith(".sub")) filename.append(".sub");
    
    app->project()->save(filename);
  }
}
