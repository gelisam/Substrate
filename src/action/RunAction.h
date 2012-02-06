#ifndef RUN_ACTION_H
#define RUN_ACTION_H

#include <QtGui/QAction>


class RunAction : public QAction
{
  Q_OBJECT;
  
public:
  RunAction(QObject* parent=0);
  
  void init();
  
private slots:
  void run(QString scriptContents);
  void act();
};

#endif
