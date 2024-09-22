#include "intervention.h"
#include <QFile>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

intervention::intervention(int i, QString  t, QDate d, QString ie, int ns)
{
    id=i;
    type=t;
    date_int=d;
    id_employe=ie;
    num_serie=ns;
}

bool intervention::ajouter()
{
    QSqlQuery query;
    query.prepare("create table if not exists intervention (id, type, date_int, id_employe, num_serie)");
    query.prepare("INSERT INTO intervention (type, date_int, id_employe, num_serie)""VALUES (:type, :date_int, :id_employe, :num_serie)");
    query.bindValue(":type",type);
    query.bindValue(":date_int",date_int);
    query.bindValue(":id_employe",id_employe);
    query.bindValue(":num_serie",num_serie);
    return query.exec();
}

QSqlQueryModel * intervention::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from intervention");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date intervention"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID Employe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Numero de Serie"));
    return model;
}

bool intervention::supprimer()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from intervention where id= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool intervention::modifier()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update intervention set type= :type, date_int= :date_int, id_employe= :id_employe, num_serie= :num_serie where id = :id");
    query.bindValue(":id", res);
    query.bindValue(":type",type);
    query.bindValue(":date_int",date_int);
    query.bindValue(":id_employe",id_employe);
    query.bindValue(":num_serie",num_serie);
    return query.exec();
}

int intervention::notification()
{
    int i=0;
    QSqlQuery query("SELECT date_int FROM intervention");
    while (query.next())
    {
        QDate date=query.value(0).toDate();
        if (date.addDays(7)<QDate::currentDate())
        {
            i++;
        }

    }
    return i;
}

QSqlQueryModel * intervention::trier(int status, int choix)
{
    QSqlQueryModel * model=afficher();
    QString query;
    QString ch;

        switch (choix)
        {
            case 1:
            {
              ch="id";
              break;
            }
            case 2:
            {
              ch="type";
              break;
            }
            case 3:
            {
              ch="date_int";
              break;
            }
            case 4:
            {
              ch="id_employe";
              break;
            }
            case 5:
            {
              ch="num_serie";
              break;
            }
            default:
              break;
        }

    if (status==1)
    {
        query="SELECT * FROM intervention ORDER BY "+ch+" ASC";
    }
    else query="SELECT * FROM intervention ORDER BY "+ch+" DESC";
    model->setQuery(query);
    return model;
}

QSqlQueryModel * intervention::rechercher(int choix)
{
    QSqlQueryModel * model=afficher();
    QString res,ch;
    switch (choix)
    {
        case 1:
        {
          ch="id";
          res= QString::number(id);
          break;
        }
        case 2:
        {
          ch="type";
          res="'"+type+"'";
          break;
        }
        case 3:
        {
          ch="date_int";
          res="'"+date_int.toString("dd.MMM.yy")+"'";
          break;
        }
        case 4:
        {
          ch="id_employe";
          res="'"+id_employe+"'";
          break;
        }
        case 5:
        {
          ch="num_serie";
          res=QString::number(num_serie);
          break;
        }
        default:
          break;
    }
    QString query="SELECT * FROM intervention WHERE "+ch+"="+res;
    model->setQuery(query);
    return model;
}

bool intervention::exporter()
{
    bool test=false;
    QSqlQueryModel * model=afficher();
    QString textData;
    int rows = model->rowCount();
    int columns = model->columnCount();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
                textData += model->data(model->index(i,j)).toString();
                textData += " || " ;
        }
        textData += "\n";
    }
    QFile txtFile("test.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        test=true;
        QTextStream out(&txtFile);
        out << "ID ||      Type      ||  Date intervention  ||ID Employe||N° Serie\n";
        out << textData;
        txtFile.close();
    }
    return test;
}

void intervention::statistiques(QWidget * w)
{
        int nbm = 0,nbsr=0;
            QSqlQuery query("SELECT COUNT(*) FROM intervention WHERE type='Maintenance'");
            while(query.next())
            {
                nbm = query.value(0).toInt();
            }
            QSqlQuery query2("SELECT COUNT(*) FROM intervention WHERE type='Service Rapide'");
            while(query2.next())
            {
               nbsr= query2.value(0).toInt();
            }

        QPieSeries *series = new QPieSeries();

        series->append("Maintenance",nbm);
        series->append("Service Rapide",nbsr);

        series->setHoleSize(0.0);
        series->setPieSize(1.0);

        QPieSlice * M = series->slices().at(0);
        QPieSlice * SR = series->slices().at(1);

        M->setLabelVisible(true);
        SR->setLabelVisible(true);

        M->setBrush(QColor::fromRgb(0, 0, 0));
        SR->setBrush(QColor::fromRgb(205, 0, 0));

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Types");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->setAnimationOptions(QChart::AllAnimations);

        QChartView * chartview = new QChartView(chart);
        chartview->resize(w->width(),w->height());
        chartview->setParent(w);
}
