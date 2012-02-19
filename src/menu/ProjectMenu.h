#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include <QtGui/QMenu>

#include "action/AddInputAction.h"


class ProjectMenu : public QMenu
{
  Q_OBJECT;
  
private:
  AddInputAction* _addInputAction;
  
public:
  ProjectMenu(QWidget* parent=0);
  
  void init();
  
  AddInputAction* addInputAction() const;
};

#endif
