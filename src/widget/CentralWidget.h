#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QtGui/QWidget>

#include "widget/InputEditor.h"
#include "widget/ScriptEditor.h"

#include <QtGui/QVBoxLayout>


class CentralWidget : public QWidget
{
  Q_OBJECT;
  
private:
  QVBoxLayout* _layout;
  InputEditor* _inputEditor;
  ScriptEditor* _scriptEditor;
  
public:
  CentralWidget(QWidget* parent=0);
  
  void init();
  
  InputEditor* inputEditor() const;
  ScriptEditor* scriptEditor() const;
};

#endif
