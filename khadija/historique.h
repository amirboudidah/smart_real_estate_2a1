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
      void save(QString,QString);
      QString load();
      void save1(QString,QString);
      void save2(QString);
};

#endif // HISTORIQUE_H

