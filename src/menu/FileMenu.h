#ifndef FILE_MENU_H
#define FILE_MENU_H

#include <QtGui/QMenu>

#include "action/OpenAction.h"
#include "action/QuitAction.h"


class FileMenu : public QMenu
{
  Q_OBJECT;
  
private:
  OpenAction* _openAction;
  QuitAction* _quitAction;
  
public:
  FileMenu(QWidget* parent=0);
  
  void init();
  
  OpenAction* openAction() const;
  QuitAction* quitAction() const;
};

#endif
