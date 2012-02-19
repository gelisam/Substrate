#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <QtGui/QMenuBar>

#include "menu/FileMenu.h"
#include "menu/RunMenu.h"


class MenuBar : public QMenuBar
{
  Q_OBJECT;
  
private:
  FileMenu* _fileMenu;
  RunMenu* _runMenu;
  
public:
  MenuBar(QWidget* parent=0);
  
  void init();
  
  FileMenu* fileMenu() const;
  RunMenu* runMenu() const;
};

#endif
