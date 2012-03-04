#include "project/Project.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTextStream>


Project::Project(QObject* parent)
: QObject(parent)
{
}

void Project::init() {
  load(":/resources/demo.sub");
}


bool Project::load(QString dirname) {
  QDir dir(dirname);
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  inputPane->clear();
  for(int i=0;; ++i) {
    QString filename = dir.absoluteFilePath("inputs/%1").arg(i);
    QFile file(filename);
    if (!file.exists()) break;
    
    if (file.open(QFile::ReadOnly)) {
      QTextStream in(&file);
      QString inputContents = in.readAll();
      
      inputPane->addInputEditor(inputContents);
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  inputPane->setCurrentIndex(0);
  
  ScriptEditor* scriptEditor = app->scriptEditor();
  scriptEditor->clear();
  {
    QString filename = dir.absoluteFilePath("script");
    QFile file(filename);
    
    if (file.open(QFile::ReadOnly)) {
      QTextStream in(&file);
      QString scriptContents = in.readAll();
      
      scriptEditor->setPlainText(scriptContents);
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
  return true;
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
