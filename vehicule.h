#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQueryModel>
#include <qsqlquery.h>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
QT_CHARTS_USE_NAMESPACE

class Vehicule
{

public:
    Vehicule();
    Vehicule(int,QString,int,QString);
    void setkilometrage(int   );
    void setnumero(int  );
    void setmarque(QString  );
    void setcouleur(QString  );
    int getnumero();
    int getkilometrage();
    QString  getmarque();
    QString  getcouleur();
    bool ajouter();
      bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel * trie_NOM();
    QSqlQueryModel * rechercher(QString a);

private:
    int numero,kilometrage;
    QString marque,couleur ;

};


#endif // VEHICULE_H
