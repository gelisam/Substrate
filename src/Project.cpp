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
  return _dataStore.filename();
}

void Project::setFilename(QString filename) {
  _dataStore.setFilename(filename);
}


bool Project::reload() {
  if (!_dataStore.reload()) return false;
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  inputPane->clear();
  for(int i=0;; ++i) {
    QString key = QString("inputs/%1").arg(i);
    if (!_dataStore.contains(key)) break;
    
    inputPane->addInputEditor(_dataStore[key]);
  }
  inputPane->setCurrentIndex(0);
  
  ScriptEditor* scriptEditor = app->scriptEditor();
  scriptEditor->clear();
  {
    QString key = "script";
    if (!_dataStore.contains(key)) return false;
    
    scriptEditor->setPlainText(_dataStore[key]);
  }
  
  return true;
}

bool Project::save() {
  _dataStore.clear();
  
  // store the version number,
  // in a format which I plan to use in the future.
  _dataStore.insert("values.txt", "Substrate_version: 0.3");
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  for(int i=0; i<inputPane->count(); ++i) {
    QString key = QString("inputs/%1").arg(i);
    
    InputEditor* inputEditor = qobject_cast<InputEditor*>(inputPane->widget(i));
    _dataStore.insert(key, inputEditor->toPlainText());
  }
  
  _dataStore.insert("script", app->scriptEditor()->toPlainText());
  
  return _dataStore.save();
}
