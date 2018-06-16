#ifndef DIALOGANALY_H
#define DIALOGANALY_H

#include <QDialog>
#include <QHBoxLayout>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
class QItemSelectionModel;
QT_END_NAMESPACE

class DialogAnaly: public QDialog
{
    Q_OBJECT

public:
    DialogAnaly(QString icd);

private slots:

private:
    void setupModel();
    void setupViews();
    void loadFile(const QString icd);

    QAbstractItemModel *model;
    QAbstractItemView *pieChart;
    QItemSelectionModel *selectionModel;

    QString id_card;
};







#endif // DIALOGANALY_H
