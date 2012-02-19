#ifndef INPUT_PANE_H
#define INPUT_PANE_H

#include <QtGui/QTabWidget>

#include "widget/InputEditor.h"


class InputPane : public QTabWidget
{
  Q_OBJECT;
  
private:
  InputEditor* _inputEditor;
  
public:
  InputPane(QWidget* parent=0);
  
  void init();
  
  InputEditor* inputEditor() const;
};

#endif
