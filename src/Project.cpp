#include "Project.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTextStream>


Project::Project(QObject* parent)
: QObject(parent)
, _dataStore()
, _store(_dataStore)
, _version(_store.path("values.txt"))
, _script(_store.path("script"))
{
  // store the version in a format which I plan to use in the future.
  _version.setValue("Substrate_version: 0.3");
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
  if (!_version.reload()) return false;
  if (!_script.reload()) return false;
  
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
  scriptEditor->setPlainText(_script.value());
  
  return true;
}

bool Project::save() {
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  for(int i=0; i<inputPane->count(); ++i) {
    QString key = QString("inputs/%1").arg(i);
    
    InputEditor* inputEditor = qobject_cast<InputEditor*>(inputPane->widget(i));
    _dataStore.insert(key, inputEditor->toPlainText());
  }
  
  _script.setValue(app->scriptEditor()->toPlainText());
  
  _version.flush();
  _script.flush();
  
  return _dataStore.save();
}
