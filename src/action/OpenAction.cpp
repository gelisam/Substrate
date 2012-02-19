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
  QString filename = QFileDialog::getOpenFileName(
    app->mainWindow(),
    "Open Bash Script",
    QString(), // current working directory
    "Bash scripts (*.bash *.sh);;All files (*.*)");
  if (!filename.isNull()) {
    app->mainWindow()->scriptEditor()->open(filename);
  }
}
