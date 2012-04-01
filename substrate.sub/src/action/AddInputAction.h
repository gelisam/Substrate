#ifndef ADD_INPUT_ACTION_H
#define ADD_INPUT_ACTION_H

#include <QtGui/QAction>


class AddInputAction : public QAction
{
  Q_OBJECT;
  
public:
  AddInputAction(QObject* parent);
  void init();
  
private slots:
  void act();
};

#endif
