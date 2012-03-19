#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QMap>


class DataStore : public QObject
{
  Q_OBJECT;
  
private:
  QString _filename;
  QMap<QString, QString> _cache;
  
public:
  DataStore(QObject* parent=0);
  
  QString filename() const;
  void setFilename(QString filename);
  
  bool reload();
  bool save() const;
  
  const QString operator[](QString key) const;
  QString take(QString key); // removes the entry
  void insert(QString key, QString value);
  
  bool isKeyValid(QString key) const;
  bool contains(QString key) const;
  void remove(QString key);
  void clear();
};

#endif
