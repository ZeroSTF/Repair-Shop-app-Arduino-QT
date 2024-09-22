#ifndef STAFF_H
#define STAFF_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include<QTextCharFormat>
#include<QCalendarWidget>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

class staff
{
    QString nom ,prenom ,fonction ,ID;
    QDate date_de_naissance ;
   // int ID  ;
public:
    //constructeurs
    staff(){} ;
    staff (QString ,QString,QString,QString,QDate);
    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getFonction(){return fonction;}
    QDate getdate_naissance(){return date_de_naissance;}
    QString getID(){return ID;}
    //stters
    void setNom(QString n ){this->nom=n;}
    void setPrenom(QString p){this->prenom=p;}
    void setFonction(QString f){this->fonction=f;}
    void setdate_naissance(QDate d){this->date_de_naissance=d;}
    void setID(int id){this->ID=id;}
    //fonctionnalites de base relatives a l'entité employé
    bool ajouter();
    QSqlQueryModel * afficher();


   bool supprimer(QString );
   bool modifier(QString ,QString,QString,QString,QDate);
   QSqlQueryModel* triparAge();
         QSqlQueryModel* rechercher_nom(QString );
         QSqlQueryModel* rechercher_prenom(QString );
         QSqlQueryModel * rechercher_nomprenom(QString, QString );
          QSqlQueryModel * rechercher_nomid(QString , QString );
           QSqlQueryModel * rechercher_prenomid(QString , QString );
           QSqlQueryModel * rechercher_prenom_id_nom(QString , QString ,QString );
           QSqlQueryModel* rechercher_id(QString);
           void calendrier(QTextCharFormat ,QCalendarWidget * );
           void statistiques(QWidget * w);
};

#endif // STAFF_H
