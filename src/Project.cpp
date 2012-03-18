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
  setFilename(":/resources/demo.sub");
  reload();
}


QString Project::filename() const {
  return _filename;
}

void Project::setFilename(QString filename) {
  _filename = filename;
}


bool Project::reload() {
  QDir dir(_filename);
  
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

bool Project::save() const {
  if (_filename.isEmpty()) {
    app->errorMessage("no filename");
    return false;
  }
  
  QDir dir(_filename);
  dir.mkpath(".");
  
  // store the version number,
  // in a format which I plan to use in the future.
  {
    QString filename = QString("values.txt");
    QFile file(dir.absoluteFilePath(filename));
    if (file.open(QFile::WriteOnly)) {
      QTextStream out(&file);
      
      out << "Substrate_version: 0.3";
    } else {
      app->errorMessage(file.errorString());
      return false;
    }
  }
  
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
