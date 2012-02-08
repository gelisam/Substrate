#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QtGui/QTextEdit>


class TextEditor : public QTextEdit
{
  Q_OBJECT;
  
public:
  TextEditor(QWidget* parent=0);
  
  void init();
};

#endif
