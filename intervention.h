#ifndef INTERVENTION_H
#define INTERVENTION_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

class intervention
{
    int id;
    QString type;
    QDate date_int;
    QString id_employe;
    int num_serie;
public:
    intervention(){};
    intervention(int i,QString t,QDate d, QString ie, int ns);

    QString getType(){return type;}
    QDate getDate(){return date_int;}
    int getID(){return id;}
    QString getID_Employe(){return id_employe;}
    int getNum_Serie(){return num_serie;}

    void setType(QString t){type=t;}
    void setDate(QDate d){date_int=d;}
    void setID(int i){id=i;}
    void setID_Employe(QString ie){id_employe=ie;}
    void setNum_Serie(int ns){num_serie=ns;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer();
    bool modifier();
    int notification();
    QSqlQueryModel * trier(int status, int choix);
    QSqlQueryModel * rechercher(int choix);
    bool exporter();
    void statistiques(QWidget * w);

};

#endif // INTERVENTION_H
