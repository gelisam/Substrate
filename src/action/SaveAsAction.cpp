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
  QString dirname = QFileDialog::getSaveFileName(
    app->mainWindow(),
    QString(), // default caption
    QString(), // current working directory
    "Substrate folders (*.sub);;All files (*.*)");
  if (!dirname.isNull()) {
    if (!dirname.endsWith(".sub")) dirname.append(".sub");
    
    app->project()->save(dirname);
  }
}
