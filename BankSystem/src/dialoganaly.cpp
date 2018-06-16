#include "dialoganaly.h"

#include <QHeaderView>
#include <QSplitter>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>

#include "analy/pieview.h"
#include "databaseutils.h"

#include <QDebug>
#include <QSqlResult>
#include <QMap>

#define DEBUG_PRE "DIALOG ANALY:"
DialogAnaly::DialogAnaly(QString icd):id_card(icd)
{

    setupModel();
    setupViews();


    loadFile(icd);

    setWindowTitle(tr("Chart"));
    resize(870, 550);
}

void DialogAnaly::setupModel()
{
    model = new QStandardItemModel(8, 2, this);
    model->setHeaderData(0, Qt::Horizontal, tr("Label"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quantity"));
}

void DialogAnaly::setupViews()
{
    QSplitter *splitter = new QSplitter;
    QTableView *table = new QTableView;
    pieChart = new PieView;
    splitter->addWidget(table);
    splitter->addWidget(pieChart);
    splitter->setStretchFactor(0, 0);
    splitter->setStretchFactor(1, 1);

    table->setModel(model);
    pieChart->setModel(model);

    QItemSelectionModel *selectionModel = new QItemSelectionModel(model);
    table->setSelectionModel(selectionModel);
    pieChart->setSelectionModel(selectionModel);

    QHeaderView *headerView = table->horizontalHeader();
    headerView->setStretchLastSection(true);

    QHBoxLayout *layout_main=new QHBoxLayout(this);
    layout_main->addWidget(splitter);

}


void DialogAnaly::loadFile(const QString icd)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QSqlQuery query(db);
    QString tmp="SELECT figure,reason,date,cardid,type FROM consume_log WHERE cid='%1' ";
    if(!query.exec(tmp.arg(icd))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return ;
    }


    model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

    int row = 0;
    QMap<QString,float> map;
    while (query.next()) {
        map[query.value("type").toString()]+=query.value("figure").toFloat();
    }
    for(auto item:map.keys()){
            model->insertRows(row, 1, QModelIndex());

            model->setData(model->index(row, 0, QModelIndex()),
                           item);
            model->setData(model->index(row, 1, QModelIndex()),
                           map.value(item));
            int c=row*256/map.size() ;
            model->setData(model->index(row, 0, QModelIndex()),
                           QColor((128+c)%256,256-c,(64+c)%256), Qt::DecorationRole);
            row++;
        }
    }


