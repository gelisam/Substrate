#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>


class MainWindow : public QMainWindow
{
  Q_OBJECT;
  
private:
  QTextEdit* textEditWidget;
  
public:
  MainWindow(QWidget* parent=0);
};

#endif
