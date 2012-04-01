#ifndef FILE_MENU_H
#define FILE_MENU_H

#include <QtGui/QMenu>

#include "action/OpenAction.h"
#include "action/ReloadAction.h"
#include "action/SaveAction.h"
#include "action/SaveAsAction.h"
#include "action/QuitAction.h"


class FileMenu : public QMenu
{
  Q_OBJECT;
  
private:
  OpenAction* _openAction;
  ReloadAction* _reloadAction;
  SaveAction* _saveAction;
  SaveAsAction* _saveAsAction;
  QuitAction* _quitAction;
  
public:
  FileMenu(QWidget* parent);
  void init();
  
  OpenAction* openAction() const;
  ReloadAction* reloadAction() const;
  SaveAction* saveAction() const;
  SaveAsAction* saveAsAction() const;
  QuitAction* quitAction() const;
};

#endif
