#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class Historique
{
    QString tmp;
  public:
      Historique();
      void save(QString,QString,QString);
      QString load();
};

#endif // HISTORIQUE_H
