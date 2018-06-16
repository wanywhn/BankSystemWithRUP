#ifndef DIALOGANALY_H
#define DIALOGANALY_H

#include <QDialog>
#include <QHBoxLayout>



class DialogAnaly : public QDialog
{
    Q_OBJECT
public:
    DialogAnaly(QString icd);


    void init_ui();
    void init_res();
    void init_data();

private:
    QString id_card;

    QHBoxLayout	*layout_main;



};

#endif // DIALOGANALY_H
