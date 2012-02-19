#ifndef INPUT_EDITOR_H
#define INPUT_EDITOR_H

#include "widget/TextEditor.h"


class InputEditor : public TextEditor
{
  Q_OBJECT;
  
public:
  InputEditor(QWidget* parent=0);
  
  virtual void init();
};

#endif
