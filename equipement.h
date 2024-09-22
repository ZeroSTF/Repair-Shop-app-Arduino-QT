#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QVector>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>


class Equipement
{
public:
            Equipement();
            Equipement(int , QString , QString, int);
           // Equipement(int id=-1, QString nom="", QString marq ="");
            int get_id();
            QString get_nom();
            QString get_marque();
            int get_quantite()const;
            void set_id( int );
            void set_nom(QString);
            void set_marque(QString);
            void set_quantite( int );
            bool ajouter_equipement();
            bool modifier_equipement();
            QSqlQueryModel* afficher();
            bool supprimer_equipement(int);
            QSqlQueryModel* recherche(QString);
            void exportFichier(QString);
            void messagedAlert();
            QSqlQueryModel* trier(int i);
            QChart* statistique();
private:
    int quantite_eq, id_eq;
    QString nom_eq, marque_eq;
};

#endif // EQUIPEMENT_H
