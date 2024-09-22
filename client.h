#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QFrame>
#include <QtCharts/QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
//#include<QtPrintSupport/QPrintMainWindow>

class client
{
public:
    client();
client(int,QString,QString,int,QString);
    void setcin(int n);
    void setprenom(QString n);
    void setnom(QString n);
    void settel(int n);
    void setville(QString n);
    int get_cin();
    QString get_prenom();
    QString get_nom();
    int get_tel();
    QString get_ville();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    bool recherche(int);
   QSqlQueryModel * rech(QString);
   bool recherchen(int);
  QSqlQueryModel * rechn(QString);
  bool recherchep(int);
 QSqlQueryModel * rechp(QString);
    QSqlQueryModel * trie_NOM();
    QSqlQueryModel * trie_cin();
    QSqlQueryModel * trie_adr();
    void statistique(QWidget * w);
private:
    QString  prenom, nom,ville;
    int cin,tel;
};
#endif // CLIENT_H
