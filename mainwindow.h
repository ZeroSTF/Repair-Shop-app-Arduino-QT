#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include"client.h"
#include"arduino.h"
#include"vehicule.h"
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
#include"equipement.h"
#include "intervention.h"
#include "staff.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_valideer_clicked();

    void on_pushButton_recherchee_clicked();

    void on_pushButton_PDF_clicked();

    void on_pushButton_imprimer_clicked();
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_update_clicked();


    void on_pushButton_trie_clicked();


   /* void on_pushButton_PDF_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_recherchee_clicked();*/



    //void on_tabWidget_tabBarClicked(int index);



    void on_tabWidget_2_tabBarClicked(int index);

    void on_tabWidget_2_currentChanged(int index);

    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pb_trier_clicked();

    void on_pb_recherchereee_clicked();

    void on_pb_imprmierrr_clicked();

    void on_pb_exporter_clicked();
//michel
    void update_label();

    void on_bouton_ajouter_clicked();

    void on_bouton_modifier_clicked();

    void on_bouton_supprimer_clicked();

    void on_bouton_export_clicked();

    void on_bouton_recherche_clicked();

    void on_bouton_retour_clicked();

    void on_bouton_trie_clicked();
//ZeroS
    void on_Button_Ajouter_clicked();

        void on_Button_Supprimer_clicked();

        void on_Button_Afficher_clicked();

        void on_Button_Modifier_clicked();

        void on_Button_Trier_clicked();

        void on_Button_Rechercher_clicked();

        void on_Button_Export_clicked();

        void on_tabWidget_tabBarClicked(int index);
//omar

        void on_supprimer_clicked();

        void on_modifier_clicked();

        void on_rechercher_clicked();

        void on_trie_par_age_clicked();

        void on_employe_currentChanged(int index);

        void on_tableView_3_activated(const QModelIndex &index);

        void on_pushButton_ajouter_2_clicked();

        void on_pushButton_temperature_clicked();

        void on_pushButton_retourclient_clicked();

        void on_pushButton_retourvehi_clicked();

        void on_pushButton_retourzeros_clicked();

        void on_pushButton_employe_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_retourzeros_2_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data;
    client C;
    Arduino A;
        Vehicule V;
       Equipement E;
       staff *Etmp;
       //ZeroS
       intervention Itmp;
       int status=1;

};
#endif // MAINWINDOW_H
