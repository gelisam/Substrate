#ifndef DISK_STORE_H
#define DISK_STORE_H

// A simpler disk access API.
// Better use the DataStore, which is faster, simpler, and more flexible.

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
class QFileSystemWatcher;


QString operator/(const QString& tree, const QString& leaf);

class DiskStore : public QObject
{
  Q_OBJECT;
  
private:
  QString _filename;
  QFileSystemWatcher* _watcher;
  
public:
  DiskStore();
  
  QString filename() const;
  void setFilename(const QString& filename);
  
  const QString operator[](const QString& leaf);
  void insert(const QString& leaf, const QString& value);
  
  static bool isValidLeaf(const QString& key);
  static bool isValidTree(const QString& key);
  
  bool containsLeaf(const QString& key) const;
  bool containsTree(const QString& key) const;
  
  void removeLeaf(const QString& key);
  void removeTree(const QString& key);
  
  QStringList children(const QString& tree) const;
  QStringList branches(const QString& tree="") const;
  QStringList leaves(const QString& tree="") const;
  
private slots:
  void emitChanged();
  
signals:
  void changed();
  void error(const QString&);
};

#endif
