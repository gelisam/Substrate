#ifndef FILE_MENU_H
#define FILE_MENU_H

#include <QtGui/QMenu>

#include "action/OpenAction.h"
#include "action/RunTruncatedAction.h"
#include "action/RunAction.h"
#include "action/QuitAction.h"


class FileMenu : public QMenu
{
  Q_OBJECT;
  
private:
  OpenAction* _openAction;
  RunTruncatedAction* _runTruncatedAction;
  RunAction* _runAction;
  QuitAction* _quitAction;
  
public:
  FileMenu(QWidget* parent=0);
  
  void init();
  
  OpenAction* openAction() const;
  RunTruncatedAction* runTruncatedAction() const;
  RunAction* runAction() const;
  QuitAction* quitAction() const;
};

#endif
