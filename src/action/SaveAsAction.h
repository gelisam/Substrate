#ifndef SAVE_AS_ACTION_H
#define SAVE_AS_ACTION_H

#include <QtGui/QAction>


class SaveAsAction : public QAction
{
  Q_OBJECT;
  
public:
  SaveAsAction(QObject* parent);
  void init();
  
private slots:
  void act();
};

#endif
