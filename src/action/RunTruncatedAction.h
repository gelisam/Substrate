#ifndef RUN_TRUNCATED_ACTION_H
#define RUN_TRUNCATED_ACTION_H

#include <QtGui/QAction>


class RunTruncatedAction : public QAction
{
  Q_OBJECT;
  
public:
  RunTruncatedAction(QObject* parent);
  void init();
  
private slots:
  void act();
};

#endif
