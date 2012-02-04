#ifndef FILE_MENU_H
#define FILE_MENU_H

#include <QtGui/QMenu>

#include "QuitAction.h"


class FileMenu : public QMenu
{
  Q_OBJECT;
  
private:
  QuitAction* _quitAction;
  
public:
  FileMenu(QWidget* parent=0);
  
  void init();
  
  QuitAction* quitAction() const;
};

#endif
