#ifndef QUIT_ACTION_H
#define QUIT_ACTION_H

#include <QtGui/QAction>


class QuitAction : public QAction
{
  Q_OBJECT;
  
public:
  QuitAction(QObject* parent);
  void init();
};

#endif
