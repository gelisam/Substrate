#ifndef SCRIPT_EDITOR_H
#define SCRIPT_EDITOR_H

#include "widget/TextEditor.h"

#include <QtGui/QKeyEvent>


class ScriptEditor : public TextEditor
{
  Q_OBJECT;
  
public:
  ScriptEditor(QWidget* parent);
  
  virtual bool open(const QString& filename);
  
  static QString preprocessScript(QString scriptContents);
  QString truncatedContents() const;
  
protected:
  virtual void keyPressEvent(QKeyEvent* e);
  
private slots:
  void colorize();
};

#endif
