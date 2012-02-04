#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include <QtGui/QPushButton>

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  
  QCoreApplication::setOrganizationName("Bloggy Badger");
  QCoreApplication::setOrganizationDomain("gelisam.blogspot.com");
  QCoreApplication::setApplicationName("Substrate");
  
  QPushButton hello("Hello World");
  hello.show();
  
  app.exec();
}
