#include "action/SaveAsAction.h"

#include "App.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtGui/QFileDialog>


SaveAsAction::SaveAsAction(QObject* parent)
: QAction("Save &As...", parent)
{
}

void SaveAsAction::init() {
  connect(this, SIGNAL(triggered()),
          this, SLOT(act()));
}


void SaveAsAction::act() {
  QString filename = QFileDialog::getSaveFileName(
    app->mainWindow(),
    QString(), // default caption
    QString(), // current working directory
    "Substrate folders (*.sub);;All files (*.*)");
  if (!filename.isNull()) {
    if (!filename.endsWith(".sub")) filename.append(".sub");
    
    QDir dir(filename);
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
        return;
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
        return;
      }
    }
  }
}
