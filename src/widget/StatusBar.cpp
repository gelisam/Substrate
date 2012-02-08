#include "widget/StatusBar.h"


StatusBar::StatusBar(QWidget* parent)
: QStatusBar(parent)
, showingErrorMessage(false)
{
}

void StatusBar::init() {
  setAutoFillBackground(true);
  
  connect(this, SIGNAL(messageChanged(const QString&)),
          this, SLOT(clearErrorFlag(const QString&)));
}


void StatusBar::errorMessage(const QString& message) {
  showMessage(message, 1500);
  
  // important: set to true after calling showMessage
  // so that messageChanged doesn't reset the flag.
  showingErrorMessage = true;
}


void StatusBar::paintEvent(QPaintEvent* event) {
  if (showingErrorMessage) {
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), QColor(210, 40, 0));
  }
  QStatusBar::paintEvent(event);
}

void StatusBar::clearErrorFlag(const QString&) {
  showingErrorMessage = false;
}
