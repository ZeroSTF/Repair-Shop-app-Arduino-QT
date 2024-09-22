#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMainWindow>
#include<QMessageBox>
#include"mainwindow.h"
#include "mainwindow.h"
#include"client.h"
#include"arduino.h"
#include"equipement.h"
#include"connection.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include "QTextStream"
#include <QTextDocument>
#include"vehicule.h"
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include "QFileDialog"
#include"equipement.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "intervention.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    /* ui->temp_lcdNumber->display("-------");
         tabWidget = new QSerialPort(this);
         serialBuffer = "";
         parsed_data = "";
         temperature_value = 0.0;*/
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
       QRegExp rxNom(NOM_RX);
       QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);

       //ZeroS
       //reopens database (theres probs a better way to do it)
          Connection c;
          bool test=c.createconnect();
          if(test)
          {
              QMessageBox::information(nullptr, QObject::tr("Database is Open"),
                          QObject::tr("Connection Successful.\n"
                                      "Click Ok to exit."), QMessageBox::Ok);
              //fills the employe comboboxe with data from the db
              QSqlQuery query1("SELECT ID, NOM, PRENOM FROM STAFF");
              while (query1.next())
                  {
                    QString idch=query1.value(0).toString();
                    QString nomch=query1.value(1).toString();
                    QString prenomch=query1.value(2).toString();
                    QString FullName=idch+"||"+nomch+" "+prenomch;
                    ui->comboBox_4->addItem(FullName);
                    ui->comboBox_4->setEditText(FullName);
                  }
              //fills the num serie combobox with data from db
              QSqlQuery query2("SELECT numero FROM vehicule");
              while (query2.next())
                  {
                    QString nsch=query2.value(0).toString();
                    ui->comboBox_5->addItem(nsch);
                    ui->comboBox_5->setEditText(nsch);
                  }


              //fills the tableview widget
              ui->tableView->setModel(Itmp.afficher());

              //notification system
              if (Itmp.notification()>0)
              {
                  QString notif=QString::number(Itmp.notification())+" interventions non effectuées d'une semaine ou plus.\n""Click Ok to exit.";
                  QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
              }
          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Database is not Open"),
                          QObject::tr("Connection Failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

//mahdi?
       ui->lineEdit_nom->setValidator(valiNom);
           ui->lineEdit_prenom->setValidator(valiNom);
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_cin_sup->setValidator(new QIntValidator(0,99999999,this));
     ui->lineEdit_numtel->setValidator(new QIntValidator(0,99999999,this));
     ui->lineEdit_numtel_2->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_client->setModel(C.afficher());
    ui->Le_numero->setValidator(new QIntValidator(100,9999999,this));
   // ui->tab_recherche->setModel(C.rech(ui->lineEdit_rech->text()));
ui->tab_client->setModel(C.trie_NOM());

//michel
ui->le_id->setValidator( new QIntValidator( 0, 9999, this));
ui->la_quantite->setValidator( new QIntValidator( 0, 500, this));
ui->tab_aff_principal->setModel(E.afficher());
ui->box_trier->addItem("nom");
ui->box_trier->addItem("marque");
ui->box_trier->addItem("quantite");
if (E.statistique()==NULL)
{
    QMessageBox::warning(nullptr, QObject::tr("Erreur"), QObject::tr("Pas d'equipements enregistés, pas de statistiques valables\n""Click Ok to exit."), QMessageBox::Ok);
}
else
{
QChartView* chartview= new QChartView();
chartview->setChart(E.statistique());
chartview->setRenderHint(QPainter::Antialiasing);
chartview->setParent(ui->tab_statistiq);
}

   //omar
   ui->tableView_3->setModel(Etmp->afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_valideer_clicked()
{
    /*QString username= ui->lineEdit_name->text();
                QString password= ui->lineEdit_pass->text();
            if ( username == "mahdi" && password =="mahdi" )
            {
               QMessageBox::information(this,"Login","Username and Password is correct,welcome mahdi ");

                this->hide();
                MainWindow integ1;
                integ1.setModal(true);
                integ1.exec();

            }
            else if (username == "dali" && password =="dali" )
                            {
                               QMessageBox::information(this,"Login","Username and Password is correct ,welcome dali");

                                this->hide();
                                MainWindow integ1;
                                integ1.setModal(true);
                                integ1.exec();
            }
            else
            {
               QMessageBox::warning(this,"Login","Username and Password is not correct ");


            }*/
            QStackedWidget stackedWidget;
                    connect(ui->stackedWidget, SIGNAL(clicked()), this, SLOT(viewData));
                    QString username=ui->lineEdit_name->text();
                            QString password = ui->lineEdit_pass->text();
                            if(username == "mahdi" && password == "mahdi")
                            { QMessageBox::information(this, "Login", "Username and password is correct, Welcome mahdi");
                           //connect(ui->MainWindow->page_3, SIGNAL(on_connecter_clicked()), this, SLOT(viewData));
                            ui->stackedWidget->setCurrentIndex(1);
                            }
                                //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                else if(username == "dali" && password == "dali")
                            { QMessageBox::information(this, "Login", "Username and password is correct, Welcome dali");
                               ui->stackedWidget->setCurrentIndex(2);
                            }
                                    //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                    else if(username == "michel" && password == "michel")
                                    { QMessageBox::information(this, "Login", "Username and password is correct, Welcome michel");
                               ui->stackedWidget->setCurrentIndex(3);
                            }
                                        //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                        else if(username == "ZeroS" && password == "ZeroS")
                                        { QMessageBox::information(this, "Login", "Username and password is correct, Welcome ZeroS");
                               ui->stackedWidget->setCurrentIndex(4);
                            }
                                            //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                         else if(username == "omar" && password == "omar")
                                            { QMessageBox::information(this, "Login", "Username and password is correct, Welcome omar"
                                                                                      ""
                                                                                      ""
                                                                                      "");
                               ui->stackedWidget->setCurrentIndex(5);
                            }
}



void MainWindow::on_pushButton_ajouter_clicked()
{
    int verif=0;
    QString nom=ui->lineEdit_nom->text();
        if(nom=="")
        {
           //ui->lineEdit_nom->setText("saisir le nom");
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("donner un nom.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
else
            verif++;
int cin=ui->lineEdit_cin->text().toInt();
if(cin==NULL)
{
   //ui->lineEdit_nom->setText("saisir le cin");
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("donner cin.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
else
    verif++;
QString prenom=ui->lineEdit_prenom->text();
if(prenom=="")
{
   //ui->lineEdit_nom->setText("saisir le prenom");
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("donner prenom.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
else
    verif++;
//QString nom=ui->lineEdit_nom->text();
int tel=ui->lineEdit_numtel->text().toInt();
if(tel==NULL)
{
   //ui->lineEdit_nom->setText("saisir le tel");
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("donner le numero de telephone.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
else
    verif++;
QString ville=ui->comboBox->currentText();
if(ville=="")
{
   //ui->lineEdit_nom->setText("saisir le adresse");
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("donner adresse.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
else
    verif++;
 client C(cin,nom,prenom,tel,ville);
 if(verif==5)
 {
 bool test=C.ajouter();
 if(test)
 {
     ui->tab_client->setModel(C.afficher());
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}
 else
     QMessageBox::critical(nullptr, QObject::tr("database is open"),
                 QObject::tr("ajout non effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_update_clicked()
{
    int cin=ui->lineEdit_cin_2->text().toInt();

    QString nom=ui->lineEdit_nom_2->text();

    QString prenom=ui->lineEdit_prenom_2->text();

    int tel=ui->lineEdit_numtel_2->text().toInt();

   QString ville=ui->comboBox_2->currentText();

    client C1(cin,prenom,nom,tel,ville);

    bool test=C1.modifier();
    if(test)
    {
        ui->tab_client->setModel(C.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    client C;
    int cin =ui->lineEdit_cin_sup->text().toInt();
    bool test=C.supprimer(cin);
            QMessageBox msgBox;
                if(test){
                    msgBox.setText("suppression reussit");
                    ui->tab_client->setModel(C.afficher());
                }
                else
                    msgBox.setText("echec de suppression");
                    msgBox.exec();
}

void MainWindow::on_pushButton_imprimer_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog Dialog(&printer,this);

    if(Dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_pushButton_PDF_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tab_client->model()->rowCount();
                        const int columnCount = ui->tab_client->model()->columnCount();
                        out <<  "<html>\n"
                                               "<head>\n"
                                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                               <<  QString("<title>%1</title>\n").arg("strTitle")
                                               <<  "</head>\n"
                                               "<body bgcolor=#ffffff link=#5000A0>\n"

                                              //     "<align='right'> " << datefich << "</align>"
                                               "<center> <H1>Liste Des Clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                           // headers
                                           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                           for (int column = 0; column < columnCount; column++)
                                               if (!ui->tab_client->isColumnHidden(column))
                                                   out << QString("<th>%1</th>").arg(ui->tab_client->model()->headerData(column, Qt::Horizontal).toString());
                                           out << "</tr></thead>\n";

                                           // data table
                                           for (int row = 0; row < rowCount; row++) {
                                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                               for (int column = 0; column < columnCount; column++) {
                                                   if (!ui->tab_client->isColumnHidden(column)) {
                                                       QString data = ui->tab_client->model()->data(ui->tab_client->model()->index(row, column)).toString().simplified();
                                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                   }
                                               }
                                               out << "</tr>\n";
                                           }
                                           out <<  "</table> </center>\n"
                                               "</body>\n"
                                               "</html>\n";
      QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                   QTextDocument doc;
                    doc.setHtml(strStream);
                    doc.setPageSize(printer.pageRect().size());
                    doc.print(&printer);


}

void MainWindow::on_pushButton_trie_clicked()
{
    client C;
        QString choix=ui->comboBox_trid->currentText();
        if (choix=="prenom")
        {
            ui->tab_client->setModel(C.trie_NOM());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_NOM();//tri produit
            if (test)
            {

        ui->tab_client->setModel(C.trie_NOM());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri prenom effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        if (choix=="ville")
        {
            ui->tab_client->setModel(C.trie_adr());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_adr();//tri produit
            if (test)
            {

        ui->tab_client->setModel(C.trie_adr());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri ville effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        if (choix=="cin")
        {
            ui->tab_client->setModel(C.trie_cin());
            ui->tab_client->setModel(C.afficher());
            bool test=C.trie_cin();//tri produit
            if (test)
            {

        ui->tab_client->setModel(C.trie_cin());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri cin effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);

            }
            else
                  QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                              QObject::tr("tri  failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_recherchee_clicked()
{
    client cl;

         QString choix=ui->valeurClient->currentText();

             if (choix=="cin")
             {
                 QString cin = ui->lineEdit_rech->text();
                 ui->tableView_2->setModel(cl.rech(cin));
             }
             if (choix=="nom")
             {
                 QString nom = ui->lineEdit_rech->text();
                 ui->tableView_2->setModel(cl.rechn(nom));
             }
             if (choix=="prenom")
             {
                 QString prenom = ui->lineEdit_rech->text();
                 ui->tableView_2->setModel(cl.rechp(prenom));
             }

}

void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
 C.statistique(ui->widget);
}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    C.statistique(ui->widget);
}

void MainWindow::on_pb_ajouter_clicked()
{
    int numero=ui->Le_numero->text().toInt();
        int killometrage=ui->Le_kilometrage->text().toInt();
        QString  marque=ui->le_marque->text();
        QString  couleur=ui->le_couleur->text();
        Vehicule V(numero,marque,killometrage,couleur);

    bool test=V.ajouter();
    QMessageBox msgBOx ;
    if (test)
    {
        ui->Tab_vehicule->setModel(V.afficher());
        msgBOx.setText("ajouter avec succes");
    }
    else
        msgBOx.setText("echec de ajouter");
    msgBOx.exec();


}

void MainWindow::on_pushButton_clicked()
{
ui->Tab_vehicule->setModel(V.afficher());
}

void MainWindow::on_pb_supp_clicked()
{
    Vehicule V1  ;
    V1.setnumero(ui->Le_supp->text().toInt());
        bool test=V1.supprimer(V1.getnumero());
        QMessageBox msgBOx ;
        if (test)
        {
            msgBOx.setText("suppression avec succes");
            ui->Tab_vehicule->setModel(V.afficher());
        }
        else
            msgBOx.setText("echec de suppression");
        msgBOx.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int numero=ui->Le_numero_2->text().toInt();
        int killometrage=ui->Le_kilometrage_2->text().toInt();
        QString  marque=ui->le_marque_2->text();
        QString  couleur=ui->le_couleur_2->text();
        Vehicule V(numero,marque,killometrage,couleur);
        bool test=V.modifier();
        QMessageBox msgBOx ;
        if (test)
        {
            ui->Tab_vehicule->setModel(V.afficher());
            msgBOx.setText("modifier avec succes");
        }
        else
            msgBOx.setText("echec de modifier");
        msgBOx.exec();
}

void MainWindow::on_pb_trier_clicked()
{
    Vehicule V;
        ui->Tab_vrier->setModel(V.trie_NOM());
        ui->Tab_vrier->setModel(V.afficher());
        bool test=V.trie_NOM();
                QMessageBox msgBox;
                    if(test){
                        msgBox.setText("trie reussit");
                        ui->Tab_vrier->setModel(V.trie_NOM());
                    }
                    else
                        msgBox.setText("echec de trie");
                        msgBox.exec();
}

void MainWindow::on_pb_recherchereee_clicked()
{
    Vehicule V;
          QString  marque=ui->le_marque_3recherche->text();
           ui->Tab_recherche->setModel(V.rechercher(marque));
}

void MainWindow::on_pb_imprmierrr_clicked()
{

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog Dialog(&printer,this);

    if(Dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_pb_exporter_clicked()
{
    QTableView *table= new QTableView;
                           table = ui->Tab_vrier;

                           QString filters("CSV files (.csv);;All files (.*)");
                           QString defaultFilter("CSV files (*.csv)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);

                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {

                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                         QObject::tr("Export avec succes .\n"
                                                                     "Click OK to exit."), QMessageBox::Ok);

        }
}
void MainWindow::on_bouton_ajouter_clicked()
{
    int id;
         QString nom=ui->le_nom->text();
           QString marq=ui->combo_marq->currentText();
         int qtite = ui->la_quantite->text().toInt();

         Equipement E(id,nom,marq,qtite);
           bool test = E.ajouter_equipement();
           if(test)
             {
                 QMessageBox::information(nullptr,QObject::tr("OK"),
                                          QObject::tr("Ajout effectué\n cliquer ici pour continuer"),
                                          QMessageBox::Cancel);
                 ui->tab_aff_principal->setModel(E.afficher());

                 QChartView* chartview= new QChartView(E.statistique()); //mise a jour de l'affichage stats apres ajout
                 chartview->setRenderHint(QPainter::Antialiasing);
                 chartview->setParent(ui->tab_statistiq);
             }
             else
                { QMessageBox::warning(nullptr,QObject::tr("not OK"),
                                          QObject::tr("echec ajout veuillez verifier vos informations \n cliquer ici pour sortir"),
                                          QMessageBox::Cancel);
             }
}

void MainWindow::on_bouton_modifier_clicked()
{
    QString idn=ui->le_id->text();
    if(idn != "")
    {
    int id=ui->le_id->text().toInt();
         QString nom=ui->le_nom->text();
         QString marq=ui->combo_marq->currentText();
     int qtite = ui->la_quantite->text().toInt();

      Equipement E(id,nom,marq,qtite);
      bool test = E.modifier_equipement();
      if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectué\n cliquer ici pour continuer"),
                                     QMessageBox::Cancel);
            ui->tab_aff_principal->setModel(E.afficher());

            QChartView* chartview= new QChartView(E.statistique()); //mise a jour de l'affichage stats apres ajout
            chartview->setRenderHint(QPainter::Antialiasing);
            chartview->setParent(ui->tab_statistiq);
        }
        else
           { QMessageBox::warning(nullptr,QObject::tr("Error update"),
                                     QObject::tr("echec mofidification\n cliquer ici pour sortir"),
                                     QMessageBox::Cancel);
            }
    }
    else
    {
         QMessageBox::information(nullptr,QObject::tr("Error update"),
                                  QObject::tr("le champ id est vide \n cliquer ici pour continuer"),
                                  QMessageBox::Cancel);


    }
}

void MainWindow::on_bouton_supprimer_clicked()
{
    Equipement E1;
           int id=ui->le_supp->text().toInt();
              E1.set_id(id);

              bool test = E1.supprimer_equipement(E1.get_id());

              if(test){
                  ui->tab_aff_principal->setModel(E.afficher());
                  QChartView* chartview= new QChartView(E.statistique()); //actualisation de l'affichage des stat
                  chartview->setRenderHint(QPainter::Antialiasing);
                  chartview->setParent(ui->tab_statistiq);
              }
              else
                  QMessageBox::warning(nullptr, QObject::tr("probleme"),
                                                             QObject::tr("une erreur est survenue lors de l'excussion du programme. "
                                                                         "\n click here to exit."),QMessageBox::Cancel);
}

void MainWindow::on_bouton_export_clicked()
{
    Equipement E;
       QString fichier = QFileDialog::getSaveFileName(0, "Enregistrer un fichier", QString(), "text (*.txt)");

      E.exportFichier(fichier);
}

void MainWindow::on_bouton_recherche_clicked()
{
    Equipement E;
    QString idn;
    QString mot=ui->le_recherche->text();
    ui->tab_aff_principal->setModel(E.recherche(mot));
}

void MainWindow::on_bouton_retour_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_bouton_trie_clicked()
{

    QString a = ui->box_trier->currentText();
        int i=0;
        if(a == "nom")
            i=1;
        else if (a == "marque")
            i=2;
        else if (a == "quantite")
        {
            i=3;
        }

        ui->tab_aff_principal->setModel(E.trier(i));

}

//ZeroS
void MainWindow::on_Button_Ajouter_clicked()
{
   int i,ns=ui->comboBox_5->currentText().toInt();
   QStringList list = ui->comboBox_4->currentText().split(QLatin1Char('|'));
   QString ie=list[0];
   QString t=ui->comboBox_3->currentText();
   QDate d=ui->dateEdit->date();
   intervention I(i,t,d,ie,ns);
   bool test=I.ajouter();
   if (test)
   {
       ui->tableView->setModel(Itmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Ajout effectué\n""Click Ok to exit."), QMessageBox::Ok);
   }
   else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Ajout non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Button_Supprimer_clicked()
{
    int i;
    i=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    if(i==NULL)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Selectionnez l'intervention à supprimer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
    {
        Itmp.setID(i);
        bool test=Itmp.supprimer();
        if (test)
        {
            ui->tableView->setModel(Itmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Suppression effectuée\n""Click Ok to exit."), QMessageBox::Ok);
        }
        else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Suppression non effectuée. \n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Button_Afficher_clicked()
{
    ui->tableView->setModel(Itmp.afficher());
}

void MainWindow::on_Button_Modifier_clicked()
{
    int i;
    i=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    if(i==NULL)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Selectionnez l'intervention à modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
         {
           QString t=ui->comboBox_3->currentText();
           QDate d=ui->dateEdit->date();
           QStringList list = ui->comboBox_4->currentText().split(QLatin1Char('|'));
           QString ie=list[0];
           int ns=ui->comboBox_5->currentText().toInt();

            intervention I1(i,t,d,ie,ns);
            bool test=I1.modifier();
            if(test)
            {
                ui->tableView->setModel(Itmp.afficher());
                        QMessageBox::information(nullptr, QObject::tr("Succés"),
                                    QObject::tr("Modification effectuée.\n"
                                                "Click Ok to exit."), QMessageBox::Ok);}
            else
                QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                            QObject::tr("Modification non effectuée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void MainWindow::on_Button_Trier_clicked()
{
    int choix=0;
    if(ui->comboBox_5->currentText()=="par ID")
    {
        choix=1;
    }
    else if(ui->comboBox_5->currentText()=="par Type")
    {
        choix=2;
    }
    else if(ui->comboBox_5->currentText()=="par Date")
    {
        choix=3;
    }
    else if(ui->comboBox_5->currentText()=="par Employe")
    {
        choix=4;
    }
    else
    {
        choix=5;
    }
    ui->tableView->setModel(Itmp.trier(status,choix));
    status++;
    status=status % 2;
}

void MainWindow::on_Button_Rechercher_clicked()
{
    int choix=0;
    if(ui->comboBox_6->currentText()=="par ID")
    {
        if(ui->lineEdit_2->text().toInt()==NULL)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Donnez l'ID de l'intervention à rechercher.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
        Itmp.setID(ui->lineEdit_2->text().toInt());
        choix=1;
        }
    }
    else if(ui->comboBox_6->currentText()=="par Type")
    {
        Itmp.setType(ui->comboBox->currentText());
        choix=2;
    }
    else if(ui->comboBox_6->currentText()=="par Date")
    {
        Itmp.setDate(ui->dateEdit->date());
        choix=3;
    }
    else if(ui->comboBox_6->currentText()=="par Employe")
    {
        QStringList list = ui->comboBox_4->currentText().split(QLatin1Char('|'));
        QString ie=list[0];
        Itmp.setID_Employe(ie);
        choix=4;
    }
    else
    {
        Itmp.setNum_Serie(ui->comboBox_5->currentText().toInt());
        choix=5;
    }
    ui->tableView->setModel(Itmp.rechercher(choix));
}

void MainWindow::on_Button_Export_clicked()
{
    bool test=Itmp.exporter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Succés"), QObject::tr("Export effectué\n""Click Ok to exit."), QMessageBox::Ok);
    }
    else QMessageBox::warning(nullptr, QObject::tr("Erreur"),QObject::tr("Export non effectué. \n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    Itmp.statistiques(ui->widget_3);
}

void MainWindow::on_pushButton_2_clicked()
{
    A.write_to_arduino("1");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//omar
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_ajouter_2_clicked()
{
    //recuperation des informtions
    QString id=ui->lineEdit_ID->text();
    QString nom=ui->lineEdit_nom_3->text();
    QString prenom=ui->lineEdit_prenom_3->text();
    QString fonction=ui->comboBox_8->currentText();
    QDate datedenaissance=ui->dateEdit_2->date();
    staff S(id,nom,prenom,fonction,datedenaissance);

    bool test1=S.ajouter();
    //id=ui->tableView_3->selectionBehavior();
   // bool test2=S.supprimer(id);
   // bool test2=S.supprimer(ui->tableView_3->selectionBehavior());
    if (test1) //si requete executée ==>QMessageBox::information
    {
        ui->tableView_3->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    QString id=ui->lineEdit_ID->text();
    bool test =Etmp->supprimer(id);
    if (test)
    {
          ui->tableView_3->setModel(Etmp->afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                                 QObject::tr("suppression avec succes .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                                 QObject::tr("delete failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modifier_clicked()
{
    staff S ;
  QString id=ui->lineEdit_ID->text();
 QString nom=ui->lineEdit_nom_3->text();
 QString prenom=ui->lineEdit_prenom_3->text();
 QString fonction=ui->comboBox_8->currentText();
 QDate date_naissance=ui->dateEdit_2->date();
 staff S1(id,nom,prenom,fonction,date_naissance);
 //bool test= S.modifier(id,nom,prenom,fonction,date_naissance);
  bool test;
  test= S1.modifier( id , nom, prenom, fonction, date_naissance);
 if (test)
     //[☺]
    {
     ui->tableView_3->setModel(S1.afficher());
     QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("MODIFICATION avec succes .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

     }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("UPDATE failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();

    QSqlQuery qry ;



     qry.prepare("SELECT nom, prenom , id , fonction , date_naissance FROM staff");
    if (qry.exec())
    {


       QMessageBox::information(nullptr, QObject::tr("select"),
                    QObject::tr("selection avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("error"),
                    QObject::tr("select failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_rechercher_clicked()
{
    if(ui->checkBox_id->isChecked()){

    QString id=ui->ln_rechercher_id->text();
    QSqlQueryModel* test=Etmp->rechercher_id(id);
    QMessageBox msgBox;
        if(test){
            msgBox.setText("recherche avec succes");
            ui->tableView_3->setModel(Etmp->rechercher_id(id));
        }
            else
            msgBox.setText(("client introuvable"));

            msgBox.exec();
    }
    else if(ui->checkBox_nom->isChecked())
    {
       QString nom=ui->ln_recherche_nom->text();
       QSqlQueryModel* test2=Etmp->rechercher_nom(nom);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_nom(nom));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
    else if(ui->checkBox_prenom->isChecked())
    {
       QString prenom=ui->ln_chercher_prenom->text();
       QSqlQueryModel* test2=Etmp->rechercher_prenom(prenom);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_prenom(prenom));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
    else if((ui->checkBox_prenom->isChecked())&&(ui->checkBox_nom->isChecked()))
    {
        QString nom=ui->ln_recherche_nom->text();
       QString prenom=ui->ln_chercher_prenom->text();
       QSqlQueryModel* test2=Etmp->rechercher_nomprenom(nom, prenom);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_nomprenom(nom, prenom));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
    else if((ui->checkBox_id->isChecked())&&(ui->checkBox_nom->isChecked()))
    {
        QString nom=ui->ln_recherche_nom->text();
      QString id=ui->ln_rechercher_id->text();
       QSqlQueryModel* test2=Etmp->rechercher_nomid(nom, id);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_nomid(nom, id));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
    else if((ui->checkBox_id->isChecked())&&(ui->checkBox_prenom->isChecked()))
    {
        QString prenom=ui->ln_chercher_prenom->text();
       QString id=ui->ln_rechercher_id->text();
       QSqlQueryModel* test2=Etmp->rechercher_prenomid(prenom, id);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_prenomid(prenom, id));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
    else if((ui->checkBox_id->isChecked())&&(ui->checkBox_prenom->isChecked())&&(ui->checkBox_nom->isChecked()))
    {
        QString nom=ui->ln_recherche_nom->text();
        QString prenom=ui->ln_chercher_prenom->text();
       QString id=ui->ln_rechercher_id->text();
       QSqlQueryModel* test2=Etmp->rechercher_prenom_id_nom(prenom, id,nom);
       QMessageBox msgBox;
           if(test2){
               msgBox.setText("recherche avec succes");
               ui->tableView_3->setModel(Etmp->rechercher_prenom_id_nom(prenom, id,nom));
           }
               else
               msgBox.setText(("client introuvable"));

               msgBox.exec();
    }
}

void MainWindow::on_trie_par_age_clicked()
{QSqlQueryModel* test=Etmp->triparAge();
    QMessageBox msgBox;
        if(test){
            msgBox.setText("tri avec succes");
            ui->tableView_3->setModel(Etmp->triparAge());
        }
            else
            msgBox.setText(("echec"));

            msgBox.exec();

}

void MainWindow::on_employe_currentChanged(int index)
{

        QTextCharFormat f=ui->calendarWidget->weekdayTextFormat(Qt::Saturday);

                Etmp->calendrier(f,ui->calendarWidget);
        Etmp->statistiques(ui->widget_4);
}
//-------------------------------------------------------
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
        ui->etat_lampe->setText("ON");
    else if (data=="0")
        ui->etat_lampe->setText("OFF");

    //ZeroS///
        if (data=="1")
        {
            if ((ui->stackedWidget->currentIndex()==4)||(ui->stackedWidget->currentIndex()==5))
            ui->stackedWidget->setCurrentIndex(6);
        }
        QString QDatastring(data);
        ui->temperateur->setText(QDatastring);
}





void MainWindow::on_pushButton_temperature_clicked()
{
        QString data=A.read_from_arduino();

    //        QStringRef subString(&data,data.length()-5 ,5 );
    //     qDebug()<< subString;



              qDebug()<< data.count();
              qDebug()<< data;
          if ( data[data.count()]>"18")
              ui->temperateur->setText("surchauffe");
          else if ( data[data.count()]<"18")
               ui->temperateur->setText("etat normale");
}

void MainWindow::on_pushButton_retourclient_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retourvehi_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retourzeros_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_retourzeros_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
