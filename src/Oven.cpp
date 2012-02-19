#include "Oven.h"

#include "App.h"

#include <QtCore/QTemporaryFile>
#include <QtCore/QProcess>
#include <QtCore/QTextStream>


Oven::Oven(QObject* parent)
: QObject(parent)
{
}

void Oven::init() {
}


void Oven::cook(QString input, QString scriptContents) {
  QTemporaryFile file;
  QProcess process;
  
  if (file.open()) {
    QString filename = file.fileName();
    
    file.write(scriptContents.toUtf8());
    if (!file.error()) {
      file.close();
      
      process.setProcessChannelMode(QProcess::ForwardedChannels);
      process.start("bash", QStringList() << filename);
      
      QTextStream inputStream(&process);
      inputStream << input;
      inputStream.flush();
      process.closeWriteChannel();
      
      if (process.waitForStarted() && process.waitForFinished()) {
        // success!
        return;
      }
    }
  }
  
  if (file.error() != QTemporaryFile::NoError) {
    app->errorMessage(file.errorString());
  } else {
    app->errorMessage(process.errorString());
  }
  
  // error.
  return;
}
