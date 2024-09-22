#include "client.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QObject>
#include<QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
client ::client()
{
cin=0;
nom="";
prenom="";
tel=0;
ville="";
}
client::client(int cin,QString nom,QString prenom,int tel,QString ville)
{
this->cin=cin;
    this->nom=nom;
this->prenom=prenom;
this->tel=tel;
this->ville=ville;

}


void client::setcin(int n){this->cin=cin;}
void client::setprenom(QString n){this->prenom=prenom;}
void client::setnom(QString n){this->nom=nom;}
void client::settel(int n){this->tel=tel;}
void client::setville(QString n){this->ville=ville;}

int client::get_cin(){return cin;}
QString client::get_prenom(){return prenom;}
QString client::get_nom(){return nom;}
int client::get_tel(){return tel;}
QString client::get_ville(){return ville;}
bool client::ajouter()
{

    QSqlQuery query;
    QString cin_string =QString::number(cin);
          query.prepare("INSERT INTO Client (cin, nom, prenom, tel, ville) "
                        "VALUES (:cin, :nom, :prenom, :tel, :ville)");
          query.bindValue(0, cin_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, tel);
          query.bindValue(4, ville);
        return  query.exec();

}
bool client::supprimer(int cin)
{
    QSqlQuery query;
      QString res =QString::number(cin);
    query.prepare(" Delete from Client where cin=:cin");
    query.bindValue(":cin", res);

  return  query.exec();
}
QSqlQueryModel * client::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM Client");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ville"));
return model;
}
bool client::modifier()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("update Client set cin= :cin, nom= :nom, prenom= :prenom, tel= :tel, ville= :ville where cin = :cin ");
query.bindValue(":cin", res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom );
query.bindValue(":tel",tel);
query.bindValue(":ville",ville);
return    query.exec();
}
QSqlQueryModel * client::trie_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Client ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ville"));
    return model;
}
QSqlQueryModel * client::trie_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Client ORDER BY cin ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ville"));
    return model;
}
QSqlQueryModel * client::trie_adr()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Client ORDER BY ville ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ville"));
    return model;
}
bool client::recherche(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE cin=:cin; ");
    query.bindValue(":cin",x);

    return query.exec();
}
QSqlQueryModel * client::rech(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM client WHERE cin = '"+a+"'");
        model->setHeaderData(0,Qt::Vertical,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Vertical,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
        model->setHeaderData(3,Qt::Vertical,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Vertical,QObject::tr("ville"));
        return model;


}
bool client::recherchen(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE nom=:nom;");
    query.bindValue(":nom",x);

    return query.exec();
}
QSqlQueryModel * client::rechn(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM client WHERE nom = '"+a+"'");
        model->setHeaderData(0,Qt::Vertical,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Vertical,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
        model->setHeaderData(3,Qt::Vertical,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Vertical,QObject::tr("ville"));
        return model;


}
bool client::recherchep(int x)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE prenom=:prenom;");
    query.bindValue(":prenom",x);

    return query.exec();
}
QSqlQueryModel * client::rechp(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM client WHERE prenom = '"+a+"'");
        model->setHeaderData(0,Qt::Vertical,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Vertical,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Vertical,QObject::tr("nom"));
        model->setHeaderData(3,Qt::Vertical,QObject::tr("numero de telephone"));
        model->setHeaderData(4,Qt::Vertical,QObject::tr("ville"));
        return model;


}
void client::statistique(QWidget * w)
{
        int nbm = 0,nbsr=0,nbr =0,nb =0;
            QSqlQuery query("SELECT COUNT(*) FROM client WHERE ville='tunis'");
            while(query.next())
            {
                nbm = query.value(0).toInt();
            }
            QSqlQuery query2("SELECT COUNT(*) FROM client WHERE ville='sfax'");
            while(query2.next())
            {
               nbsr= query2.value(0).toInt();
            }
            QSqlQuery query3("SELECT COUNT(*) FROM client WHERE ville='sousse'");
            while(query3.next())
            {
               nbr= query3.value(0).toInt();
            }
            QSqlQuery query4("SELECT COUNT(*) FROM client WHERE ville='nabeul'");
            while(query4.next())
            {
               nb= query4.value(0).toInt();
            }
        QPieSeries *series = new QPieSeries();

        series->append("tunis",nbm);
        series->append("sfax",nbsr);
series->append("sousse",nbr);
series->append("nabeul",nb);
        series->setHoleSize(0.0);
        series->setPieSize(1.0);
        series->setPieSize(2.0);
 series->setPieSize(3.0);
        QPieSlice * M = series->slices().at(0);
        QPieSlice * SR = series->slices().at(1);
QPieSlice * R = series->slices().at(2);
QPieSlice * n = series->slices().at(3);
        M->setLabelVisible(true);
        SR->setLabelVisible(true);
R->setLabelVisible(true);
n->setLabelVisible(true);
        M->setBrush(QColor::fromRgb(85, 31, 31));
        SR->setBrush(QColor::fromRgb(205, 0, 0));
R->setBrush(QColor::fromRgb(160, 205, 120));
n->setBrush(QColor::fromRgb(100, 100, 20));
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("ville");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->setAnimationOptions(QChart::AllAnimations);

        QChartView * chartview = new QChartView(chart);
        chartview->resize(w->width(),w->height());
        chartview->setParent(w);


}
