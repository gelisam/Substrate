#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QtGui/QStatusBar>
#include <QtGui/QPainter>


class StatusBar : public QStatusBar
{
  Q_OBJECT;
  
private:
  bool showingErrorMessage;
  
public:
  StatusBar(QWidget* parent);
  void init();
  
  void errorMessage(const QString& message);
  
protected:
  virtual void paintEvent(QPaintEvent* event);
  
private slots:
  void clearErrorFlag(const QString& message);
};

#endif
