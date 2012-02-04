#include "FileMenu.h"


FileMenu::FileMenu(QWidget* parent)
: QMenu("&File", parent)
, _quitAction(new QuitAction(this))
{
  addAction(_quitAction);
}

QuitAction* FileMenu::quitAction() const {
  return _quitAction;
}
