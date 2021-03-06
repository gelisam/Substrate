#include "Oven.h"

#include <QtCore/QTemporaryFile>
#include <QtCore/QProcess>
#include <QtCore/QTextStream>


Oven::Oven(QObject* parent)
: QObject(parent)
{
}

void Oven::init() {
}


void Oven::cook(QString inputContents, QString scriptContents) {
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
      inputStream << inputContents;
      inputStream.flush();
      process.closeWriteChannel();
      
      if (process.waitForStarted() && process.waitForFinished()) {
        // success!
        return;
      }
    }
  }
  
  if (file.error() != QTemporaryFile::NoError) {
    emit error(file.errorString());
  } else {
    emit error(process.errorString());
  }
  
  // error.
  return;
}
