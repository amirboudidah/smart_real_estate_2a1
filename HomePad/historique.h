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
      QString load2();
      void save1(QString,QString);
      void save2(QString);
      void save3(QString,QString,QString);
      void save4(QString,QString,QString);
      void save5(QString);
};

#endif // HISTORIQUE_H

