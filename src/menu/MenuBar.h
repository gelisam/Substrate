#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <QtGui/QMenuBar>

#include "menu/FileMenu.h"


class MenuBar : public QMenuBar
{
  Q_OBJECT;
  
private:
  FileMenu* _fileMenu;
  
public:
  MenuBar(QWidget* parent=0);
  
  void init();
  
  FileMenu* fileMenu() const;
};

#endif
