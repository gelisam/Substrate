#ifndef INPUT_PANE_H
#define INPUT_PANE_H

#include <QtGui/QTabWidget>

#include "widget/InputEditor.h"


class InputPane : public QTabWidget
{
  Q_OBJECT;
  
public:
  InputPane(QWidget* parent=0);
  
  void init();
  
  InputEditor* addInputEditor(QString initialContents=QString());
  InputEditor* currentInputEditor() const;
};

#endif
