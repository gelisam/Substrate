#ifndef SCRIPT_EDITOR_H
#define SCRIPT_EDITOR_H

#include <QtGui/QTextEdit>
#include <QtGui/QKeyEvent>


class ScriptEditor : public QTextEdit
{
  Q_OBJECT;
  
public:
  ScriptEditor(QWidget* parent=0);
  
  void init();
  void open(const QString& filename);
  
protected:
  virtual void keyPressEvent(QKeyEvent* e);
  
private slots:
  void colorize();
};

#endif
