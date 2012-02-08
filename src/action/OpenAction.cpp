#include "action/OpenAction.h"

#include "App.h"

#include <QtCore/QFile>
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
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QString contents = QString::fromUtf8(file.readAll());
      if (file.error() == QFile::NoError) {
        QTextEdit* textEdit = app->mainWindow()->textEditWidget();
        textEdit->setDocumentTitle(filename);
        textEdit->setPlainText(contents);
        
        // success!
        return;
      }
    }
    
    app->errorMessage(file.errorString());
    
    // error.
    return;
  }
  
  // cancelled.
}
