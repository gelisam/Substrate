#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QtGui/QWidget>

#include "widget/InputPane.h"
#include "widget/ScriptEditor.h"

#include <QtGui/QVBoxLayout>


class CentralWidget : public QWidget
{
  Q_OBJECT;
  
private:
  QVBoxLayout* _layout;
  InputPane* _inputPane;
  ScriptEditor* _scriptEditor;
  
public:
  CentralWidget(QWidget* parent=0);
  
  void init();
  
  InputPane* inputPane() const;
  ScriptEditor* scriptEditor() const;
};

#endif
