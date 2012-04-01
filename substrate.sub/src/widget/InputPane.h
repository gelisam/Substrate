#ifndef INPUT_PANE_H
#define INPUT_PANE_H

#include <QtGui/QTabWidget>

#include "widget/InputEditor.h"


class InputPane : public QTabWidget
{
  Q_OBJECT;
  
public:
  InputPane(QWidget* parent);
  void init();
  
  InputEditor* addInputEditor(QString initialContents=QString());
  InputEditor* currentInputEditor() const;
  
private slots:
  void emitError(const QString&);
  
signals:
  void error(const QString&);
};

#endif
