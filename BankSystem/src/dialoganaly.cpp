#include "dialoganaly.h"

#include <QHeaderView>
#include <QSplitter>
#include <QStandardItemModel>
#include <QTableView>

#include "analy/pieview.h"
#include "databaseutils.h"


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

    QTextStream stream(&file);
    QString line;

    model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

    int row = 0;
    do {
        line = stream.readLine();
        if (!line.isEmpty()) {
            model->insertRows(row, 1, QModelIndex());

            QStringList pieces = line.split(',', QString::SkipEmptyParts);
            model->setData(model->index(row, 0, QModelIndex()),
                           pieces.value(0));
            model->setData(model->index(row, 1, QModelIndex()),
                           pieces.value(1));
            model->setData(model->index(row, 0, QModelIndex()),
                           QColor(pieces.value(2)), Qt::DecorationRole);
            row++;
        }
    } while (!line.isEmpty());

    file.close();
    statusBar()->showMessage(tr("Loaded %1").arg(icd), 2000);
}

