#include "Project.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTextStream>


Project::Project(QObject* parent)
: QObject(parent)
{
}

void Project::init() {
}


bool Project::save(QString dirname) const {
  QDir dir(dirname);
  dir.mkpath(".");
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  dir.mkpath("inputs");
  for(int i=0; i<inputPane->count(); ++i) {
    InputEditor* inputEditor = qobject_cast<InputEditor*>(inputPane->widget(i));
    
    QString filename = QString("inputs/%1").arg(i);
    QFile file(dir.absoluteFilePath(filename));
    if (file.open(QFile::WriteOnly)) {
      QTextStream out(&file);
      
      out << inputEditor->toPlainText();
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
  ScriptEditor* scriptEditor = app->scriptEditor();
  {
    QString filename = QString("script");
    QFile file(dir.absoluteFilePath(filename));
    if (file.open(QFile::WriteOnly)) {
      QTextStream out(&file);
      
      out << scriptEditor->toPlainText();
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
  return true;
}
