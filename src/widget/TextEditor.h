#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QtGui/QTextEdit>
#include <QtGui/QKeyEvent>


class TextEditor : public QTextEdit
{
  Q_OBJECT;
  
public:
  TextEditor(QWidget* parent=0);
  
  void init();
  void open(const QString& filename);
  
protected:
  virtual void keyPressEvent(QKeyEvent* e);
  
private slots:
  void colorize();
};

#endif
