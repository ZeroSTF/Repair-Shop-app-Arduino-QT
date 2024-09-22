#include "vehicule.h"
#include"QSqlQuery"
#include<QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

Vehicule::Vehicule()
{
numero=0;
kilometrage=0;
marque=" " ;
couleur="";
}

Vehicule ::Vehicule(int numero , QString marque ,int kilometrage,QString couleur)
{this->numero=numero;this->kilometrage=kilometrage;this->marque=marque;this->couleur=couleur;}
int Vehicule ::getnumero() {return numero;}
int Vehicule ::getkilometrage() {return kilometrage;}

QString Vehicule :: getmarque() {return marque;}
QString Vehicule :: getcouleur() {return couleur;}
void Vehicule::  setnumero(int numero) {this->numero=numero;}
void Vehicule::  setkilometrage(int kilometrage) {this->kilometrage=kilometrage;}
void Vehicule::  setmarque(QString marque) {this->marque=marque;}
void Vehicule::  setcouleur(QString  couleur){this->couleur=couleur;}

bool Vehicule:: ajouter()
{

    QString numero_string= QString ::  number (numero);
    QString kilometrage_string= QString ::  number (kilometrage);



    QSqlQuery query;

          query.prepare("INSERT INTO vehicule (NUMERO,MARQUE,KILOMETRAGE,COULEUR)"
                        "VALUES (:numero,:marque,:kilometrage,:couleur)");
          query.bindValue(0, numero_string);
                    query.bindValue(1, marque);
                    query.bindValue(2, kilometrage_string);
                    query.bindValue(3, couleur);

                  return  query.exec();
        return   query.exec();
  }
bool Vehicule::supprimer(int numero)
{
    QSqlQuery query;
      QString res =QString::number(numero);
    query.prepare(" Delete from vehicule where numero= :numero");
    query.bindValue(":numero", res);

  return   query.exec();






}
QSqlQueryModel* Vehicule :: afficher()
{

QSqlQueryModel*  model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM vehicule");
      model->setHeaderData(0, Qt::Horizontal, QObject:: tr("numero"));
      model->setHeaderData(1, Qt::Horizontal,QObject:: tr("marque"));
      model->setHeaderData(2, Qt::Horizontal,QObject:: tr("kilometrage"));
      model->setHeaderData(3, Qt::Horizontal,QObject:: tr("couleur"));




return model;

}
bool Vehicule::modifier()
{
    QSqlQuery query;
              QString charnumero=QString::number(numero);
              QString charKilometrage=QString::number(kilometrage);

              query.prepare("UPDATE vehicule SET numero=:numero,kilometrage=:kilometrage, marque=:marque, couleur=:couleur WHERE numero=:numero");
              query.bindValue(":numero", charnumero);
              query.bindValue(":kilometrage", kilometrage);
              query.bindValue(":marque", marque);
              query.bindValue(":couleur", couleur);

               return query.exec();

}
QSqlQueryModel* Vehicule :: trie_NOM()

{
    QSqlQueryModel * model= new QSqlQueryModel();


    model->setQuery("SELECT * FROM vehicule ORDER BY kilometrage ");


          model->setHeaderData(0,Qt::Horizontal,QObject::tr("numero"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("marque"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("kilometrage"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("couleur"));

    return model;
}


QSqlQueryModel* Vehicule ::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule where marque ='"+a+"' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("marque"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("kilometrage"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("couleur"));

        return model;

}

