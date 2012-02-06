#include "action/OpenAction.h"

#include "App.h"

#include <QtCore/QFile>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>


OpenAction::OpenAction(QObject* parent)
: QAction("&Open", parent)
{
}

void OpenAction::init() {
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
      if (!file.error()) {
        QTextEdit* textEdit = app->mainWindow()->textEditWidget();
        textEdit->setDocumentTitle(filename);
        textEdit->setPlainText(contents);
        
        // success!
        return;
      }
    }
    
    QMessageBox::warning(
      app->mainWindow(), "Error",
      file.errorString());
    
    // error.
    return;
  }
  
  // cancelled.
}
