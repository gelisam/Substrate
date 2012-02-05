#ifndef FILE_MENU_H
#define FILE_MENU_H

#include <QtGui/QMenu>

#include "OpenAction.h"
#include "QuitAction.h"


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
