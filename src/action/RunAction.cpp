#include "action/RunAction.h"

#include "App.h"

#include <QtCore/QTemporaryFile>
#include <QtCore/QProcess>
#include <QtGui/QMessageBox>


RunAction::RunAction(QObject* parent)
: QAction("&Run", parent)
{
}

void RunAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void RunAction::run(QString scriptContents) {
  QTemporaryFile file;
  QProcess process;
  
  if (file.open()) {
    QString filename = file.fileName();
    
    file.write(scriptContents.toUtf8());
    if (!file.error()) {
      file.close();
      
      process.setProcessChannelMode(QProcess::ForwardedChannels);
      process.start("bash", QStringList() << filename);
      
      if (process.waitForStarted() && process.waitForFinished()) {
        // success!
        return;
      }
    }
  }
  
  if (file.error() != QTemporaryFile::NoError) {
    QMessageBox::warning(
      app->mainWindow(), "Error",
      file.errorString());
  } else {
    QMessageBox::warning(
      app->mainWindow(), "Error",
      process.errorString());
  }
  
  // error.
  return;
}

void RunAction::act() {
  QTextEdit* textEdit = app->mainWindow()->textEditWidget();
  run(textEdit->toPlainText());
}
