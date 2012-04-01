#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H

#include <QtGui/QAction>


class SaveAction : public QAction
{
  Q_OBJECT;
  
public:
  SaveAction(QObject* parent);
  void init();
  
public slots:
  void act();
};

#endif
