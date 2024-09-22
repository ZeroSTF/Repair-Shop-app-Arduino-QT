#include "equipement.h"
#include <iostream>

Equipement::Equipement()
{
     id_eq=0;
     nom_eq="";
     marque_eq="";
     quantite_eq=0;
}
Equipement::Equipement(int id, QString nom, QString marq, int qtite)
{
    id_eq=id;
    nom_eq=nom;
    marque_eq=marq;
    quantite_eq=qtite;
}
//---------------------------------------------------------------------------------

int Equipement::get_id() { return id_eq; }
QString Equipement::get_nom(){return nom_eq; }
QString Equipement::get_marque(){ return marque_eq; }
int Equipement::get_quantite()const { return quantite_eq; }
void Equipement::set_id( int m){ this->id_eq=m; }
void Equipement::set_nom(QString m){ this->nom_eq=m;}
void Equipement::set_marque(QString n){ this->marque_eq=n;}
void Equipement::set_quantite( int n){ this->quantite_eq=n;}
//---------------------------------------------------------------------------
bool Equipement::modifier_equipement()
{
    QSqlQuery query;

           QString id = QString::number(id_eq);
           QString marque = marque_eq;
           QString nom = nom_eq;
          QString quantite= QString::number(quantite_eq);
           query.prepare("UPDATE equipement SET nom_eq=:nome, marque_eq=:marquee, quantite_eq=:quantitee WHERE identifiant_eq=:ide;");

           query.bindValue(":nome", nom);
            query.bindValue(":marquee", marque);
            query.bindValue(":quantitee", quantite);
            query.bindValue(":ide", id);


           return query.exec();

}

//-----------------------------------------------------------
bool Equipement::ajouter_equipement()
{
    QSqlQuery query;
    QString charid=QString::number(id_eq);
      QString qtite_string = QString::number(quantite_eq); //conversion du numero en string
         query.prepare("INSERT INTO equipement (identifient_eq, nom_eq, marque_eq, quantite_eq) "
                       "VALUES (:id, :nom, :marque, :quantite)");

         query.bindValue(":id", charid);
         query.bindValue(":nom", nom_eq);
         query.bindValue(":marque", marque_eq);
         query.bindValue(":quantite", qtite_string);

        return query.exec();

}
//--------------------------------------------------------
QSqlQueryModel* Equipement::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT* FROM equipement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));    //on met les nom qui vont s'afficher
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("designation"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

        return model;

}
//----------------------------------------------------------------------------------------

bool Equipement::supprimer_equipement(int id_sup)
{
    QSqlQuery query;   // pour gerer la suppression
    QSqlQuery query2;  // pour gerer la recherche
     QString id_string = QString::number(id_sup);

     QString nom,marque; //creation des variable qui vont prendre les valeurs trouvé

        query2.prepare("SELECT* FROM equipement WHERE identifiant_eq=:id");
        query2.bindValue(":id",id_sup);

        int compte=0;
        query2.exec();  // lancement de l'excution de la recherche
          while(query2.next())
          {
               nom= query2.value(1).toString();
               marque= query2.value(2).toString();



              compte++;
           }
          if(compte != 0) //on verifie si on a trouver quelque chose
          {
             int confirmation = QMessageBox::warning(nullptr, "trouver",
                          "voulez vous <strong>supprimer</strong> " +id_string+ " " +nom+ " " +marque+ ", \n click here to exit.", QMessageBox::Yes | QMessageBox::No);
             if(confirmation == QMessageBox::Yes)
              {
                query.prepare(" Delete from equipement where identifiant_eq=:id");  //preparation de la requete de suppression
                query.bindValue(":id", id_sup);
                query.exec();
              }
            else
                { QMessageBox::information(nullptr, QObject::tr("trouver"),
                                           QObject::tr("suppression annulé. \n click here to exit."),QMessageBox::Cancel);
                 }
             return true;
          }
          else {
              QMessageBox::information(nullptr, QObject::tr("resultat"),
                                                         QObject::tr("aucune correspondance pour cet ID. \n click here to exit."),QMessageBox::Cancel);
          }

          return query2.exec();

}
//-----------------------------------------------------------------------------

 void Equipement::exportFichier(QString fichier)
 {


     QFile file(fichier);  //on lie le save avec la fenetre qdialog
     if(file.open(QIODevice::WriteOnly | QIODevice::Text))
     {
         QTextStream ecriture(&file);
     QSqlQuery query;  // pour gerer la recherche

      QString nom,marque,id,quantite; //creation des variable qui vont prendre les valeurs trouvé

         query.prepare("SELECT* FROM equipement");

         int compte=0;
         query.exec();  // lancement de l'excution de la recherche
           while(query.next())
           {
               id= query.value(0).toString();
               nom= query.value(1).toString();
                marque= query.value(2).toString();
                quantite=query.value(1).toString();
            ecriture << id << "\t"<< nom << "\t"<< marque << "\t"<< quantite << "\n";
               compte++;
            }
           file.close();

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("erreur"),
                                                    QObject::tr("erreur douverture fichier. \n click here to exit."),QMessageBox::Cancel);

     }

 }
//-------------------------------------------------------------------------------------
QSqlQueryModel* Equipement::recherche(QString mot)
 {

     QSqlQueryModel* model = new QSqlQueryModel();

         model->setQuery("SELECT* FROM equipement WHERE identifiant_eq='"+mot+"' or nom_eq='"+mot+"' or marque_eq='"+mot+"'");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));    //on met les nom qui vont s'afficher
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("designation"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));


         QSqlQuery query;  // pour gerer la recherche

      QString nom,marque,id,quantite; //creation des variable qui vont prendre les valeurs trouvé

      query.prepare("SELECT* FROM equipement WHERE identifiant_eq=:id or nom_eq=:nome or marque_eq=:mque");
      query.bindValue(":id",mot);
      query.bindValue(":nome",mot);
      query.bindValue(":mque",mot);

         int compte=0;
         query.exec();  // lancement de l'excution de la recherche
           while(query.next())
           {
               compte++;
            }

        if(compte ==0)
        { QMessageBox::information(nullptr, QObject::tr("resultat"),
                                                    QObject::tr("non trouve \n click here to exit."),QMessageBox::Cancel);

         }
        return model;
 }
//-------------------------------------------------------------------------------------------------------------------

void Equipement::messagedAlert()
 {
     QSqlQuery query;

     QString dix = QString::number(10);

   query.prepare("SELECT * FROM equipement");
     int val;
     Equipement e;

     query.exec();  // lancement de l'excution de la recherche
       while(query.next())
       {
           val=query.value(3).toString().toUInt();

            if(val <= 10)
              {
                e.set_id(query.value(0).toString().toInt());
                e.set_nom(query.value(1).toString());
                e.set_marque(query.value(2).toString());
                e.set_quantite(query.value(3).toString().toInt());
                QString qtite = QString::number(e.get_quantite());
                QMessageBox::critical(nullptr," Alerte stock bas\n"," "+e.get_nom()+" \t "+e.get_marque()+"\t Quantité: "+qtite+" \n cliquer ici pour continuer",
                                                    QMessageBox::Cancel);
                }

        }

 }
//----------------------------------------------------------------------------------------------------------

QSqlQueryModel* Equipement::trier(int i)
{


         QSqlQueryModel* model = new QSqlQueryModel();

         if(i==1)
         {
             model->setQuery("SELECT* FROM equipement ORDER BY nom_eq asc");
         }
         else if (i==2)
         {
             model->setQuery("SELECT* FROM equipement ORDER BY marque_eq asc");
         }
         else if(i==3)
         {
             model->setQuery("SELECT* FROM equipement ORDER BY quantite_eq asc");
         }
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));    //on met les nom qui vont s'afficher
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("designation"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

             return model;
}
//--------------------------------------------------------------------------------------

QChart* Equipement::statistique()
{
    QString marque; //creation des variable qui vont prendre les valeurs trouvé

        QSqlQuery query;
       query.prepare("SELECT * FROM equipement");

       int total=0, nbretoy=0, nbrebmw=0, nbreford=0, nbrepeug=0, nbrekia=0;
       float val;

       query.exec();   // lancement de l'excution de la recherche
         while(query.next())
         {
              marque= query.value(2).toString();
              if(marque=="Toyota")
              nbretoy += query.value(3).toInt();

              else if(marque=="BMW")
              nbrebmw += query.value(3).toInt();

              else if(marque=="Ford")
              nbreford += query.value(3).toInt();

              else if(marque=="Peugeot")
              nbrepeug += query.value(3).toInt();

              else if(marque=="Kia")
              {nbrekia += query.value(3).toInt();
              }
            total+=query.value(3).toInt();
         }
         if (total==0)
         {
             return NULL;
         }
         else
         {
             QPieSeries *series = new QPieSeries();  //initialisation des parties


             series->setHoleSize(0.28);  //epaisseur du graphe
              val=nbretoy*100/total;  //calcul du pourcentage
              QString nbre_string = QString::number(val);
             series->append("TOYOTA "+nbre_string+"%  ",val); //ajout d'une partie

             val=nbrekia*100/total;
             nbre_string = QString::number(val);
             QPieSlice *slice = new QPieSlice(); //series->append("KIA "+nbre_string+"% ", val);  //on ajoute une partie et on creer une coupure de 15 px
                     slice=series->append("KIA "+nbre_string+"% ", val);  //on ajoute une partie et on creer une coupure de 15 px

             slice->setExploded();   //on detache la partie avec une coupé
             slice->setLabelVisible();

             val=nbreford*100/total;
             nbre_string = QString::number(val);
               QPieSlice *slice2 =series->append("FORD "+nbre_string+"% ",val);

               slice2->setExploded();   //on detache la partie avec une coupé
               slice2->setLabelVisible();

              val=nbrepeug*100/total;
              nbre_string = QString::number(val);
              series->append("PEUGEOT "+nbre_string+"% ",val);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setAnimationOptions(QChart::SeriesAnimations);
              chart->setTitle("Statique celon les marques ");
              chart->setTheme(QChart::ChartThemeBlueCerulean); //creation du theme
              chart->legend()->setVisible(true);

              return chart;
         }
}
