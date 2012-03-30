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
, _inputs(_store.path("inputs"))
, _script(_store.path("script"))
{
  // store the version in a format which I plan to use in the future.
  _version.setValue("Substrate_version: 0.3");
}

void Project::init() {
  setFilename(":/resources/demo.sub");
  reload();
  
  connect(_dataStore.diskStore(), SIGNAL(changed()),
          this,                   SLOT(reload()));
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
  if (!_inputs.reload()) return false;
  if (!_script.reload()) return false;
  
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  inputPane->clear();
  for(int i=0; i<_inputs.length(); ++i) {
    inputPane->addInputEditor(_inputs[i]->value());
  }
  inputPane->setCurrentIndex(0);
  
  ScriptEditor* scriptEditor = app->scriptEditor();
  scriptEditor->clear();
  scriptEditor->setPlainText(_script.value());
  
  return true;
}

bool Project::save() {
  InputPane* inputPane = app->mainWindow()->centralWidget()->inputPane();
  _inputs.setLength(inputPane->count());
  for(int i=0; i<_inputs.length(); ++i) {
    InputEditor* inputEditor = qobject_cast<InputEditor*>(inputPane->widget(i));
    _inputs[i]->setValue(inputEditor->toPlainText());
  }
  
  _script.setValue(app->scriptEditor()->toPlainText());
  
  _version.flush();
  _inputs.flush();
  _script.flush();
  
  return _dataStore.save();
}
