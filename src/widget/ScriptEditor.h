#ifndef SCRIPT_EDITOR_H
#define SCRIPT_EDITOR_H

#include "widget/TextEditor.h"

#include <QtGui/QKeyEvent>


class ScriptEditor : public TextEditor
{
  Q_OBJECT;
  
public:
  ScriptEditor(QWidget* parent=0);
  
  virtual void init();
  virtual bool open(const QString& filename);
  
protected:
  virtual void keyPressEvent(QKeyEvent* e);
  
private slots:
  void colorize();
};

#endif
