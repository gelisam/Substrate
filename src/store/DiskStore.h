#ifndef DISK_STORE_H
#define DISK_STORE_H

// A simpler disk access API.
// Better use the DataStore, which is faster, simpler, and more flexible.

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>


QString operator/(const QString& tree, const QString& leaf);

class DiskStore : public QObject
{
  Q_OBJECT;
  
private:
  QString _filename;
  
public:
  DiskStore();
  
  QString filename() const;
  void setFilename(const QString& filename);
  
  const QString operator[](const QString& leaf) const;
  void insert(const QString& leaf, const QString& value) const;
  
  static bool isValidLeaf(const QString& key);
  static bool isValidTree(const QString& key);
  
  bool containsLeaf(const QString& key) const;
  bool containsTree(const QString& key) const;
  
  void removeLeaf(const QString& key) const;
  void removeTree(const QString& key) const;
  
  QStringList children(const QString& tree) const;
  QStringList leaves(const QString& tree="") const;
};

#endif
