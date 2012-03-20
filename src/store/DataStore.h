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
  DataStore();
  
  void debug() const;
  
  QString filename() const;
  void setFilename(const QString& filename);
  
  bool reload();
  bool save() const;
  
  const QString operator[](const QString& key) const;
  QString take(const QString& key); // removes the entry
  void insert(const QString& key, const QString& value);
  
  bool isKeyValid(const QString& key) const;
  bool contains(const QString& key) const;
  void remove(const QString& key);
  void clear();
};

#endif
