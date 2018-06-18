#include "databaseutils.h"
#include "dialogsyslogin.h"
#include "systemwidget.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTimer>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define DEBUG_PRE __FILE__ "SystemWidget:" TOSTRING(__LINE__)
SystemWidget::SystemWidget(QWidget *parent) : QWidget(parent)
{

    init_res();
    init_ui();
    de_time->setDateTime(QDateTime::currentDateTime());
    lv_plan->setModel(lm_model);

    connect(btn_accept,&QPushButton::clicked,this,[this](){

        this->update_data();

    });
    connect(btn_reset,&QPushButton::clicked,this,&SystemWidget::reset_date);
    connect(btn_add_user,&QPushButton::clicked,this,&SystemWidget::user_add);
    connect(btn_delete_user,&QPushButton::clicked,this,&SystemWidget::user_delete);
    connect(btn_plan_add,&QPushButton::clicked,this,&SystemWidget::plan_add);
    connect(btn_plan_delete,&QPushButton::clicked,this,&SystemWidget::plan_delete);

    reset_date();

}

void SystemWidget::update_data(bool given,QList<float> list)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
    }

    QString tmp="INSERT INTO lilv (current,one_year,five_year,"
                "daikuan,"
                "credit_enchashment_fee,credit_lixi,credit_overdue_fine,"
                "usd,yen,euro,id)"
                "VALUES ('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10',1)  ON DUPLICATE KEY UPDATE"
//    QString tmp1="UPDATE lilv SET "
                " current='%1',one_year='%2',five_year='%3',daikuan='%4',credit_enchashment_fee='%5',"
                " credit_lixi='%6',credit_overdue_fine='%7',usd=%8,yen=%9,euro=%10 ";
    QSqlQuery query(db);
    QString stmt;
    if(given){
        stmt=tmp;
        while(!list.empty()){
            stmt=stmt.arg(list.first());
            list.pop_front();
        }
        timer.stop();

    }else{
    auto value1=le_deposit_current->text().toFloat();
    auto value2=le_deposit_one_year->text().toFloat();
    auto value3=le_deposit_five_year->text().toFloat();
    auto value4=le_daikuan_lilv->text().toFloat();
    auto value5=le_credit_enchashment_fee->text().toFloat();
    auto value6=le_credit_interest->text().toFloat();
    auto value7=le_credit_overdue_fine->text().toFloat();
    auto value8=le_waihui_usd->text().toFloat();
    auto value9=le_waihui_yen->text().toFloat();
    auto value10=le_waihui_euro->text().toFloat();

    stmt=tmp.arg(value1).arg(value2).arg(value3).arg(value4).arg(value5).arg(value6)
            .arg(value7).arg(value8).arg(value9).arg(value10);
    }

    qDebug()<<DEBUG_PRE<<"STMT:"<<stmt;
    if(!query.exec(stmt)){
        qDebug()<<query.lastError();
        return ;
    }
    this->reset_date();
    QMessageBox::information(this,tr("Success"),tr("Update Success"));
}

void SystemWidget::reset_date()
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    //						0		1		2		3			4
    QString tmp="SELECT current,one_year,five_year,daikuan,credit_enchashment_fee,"
            //			5		6					7	8	9
                "credit_lixi,credit_overdue_fine,usd,yen,euro "
                "FROM lilv ";
    QSqlQuery query(db);
    if(!query.exec(tmp)){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return ;
    }
    query.next();
    le_deposit_current->setText(QString::number(query.value("current").toFloat()));
    le_deposit_one_year->setText(QString::number(query.value("one_year").toFloat()));
    le_deposit_five_year->setText(QString::number(query.value("five_year").toFloat()));

    le_daikuan_lilv->setText(QString::number(query.value("daikuan").toFloat()));

    le_credit_enchashment_fee->setText(QString::number(query.value("credit_enchashment_fee").toFloat()));
    le_credit_interest->setText(QString::number(query.value("credit_lixi").toFloat()));
    le_credit_overdue_fine->setText(QString::number(query.value("credit_overdue_fine").toFloat()));

    le_waihui_usd->setText(QString::number(query.value("usd").toFloat()));
    le_waihui_yen->setText(QString::number(query.value("yen").toFloat()));
    le_waihui_euro->setText(QString::number(query.value("euro").toFloat()));

    cb_cate->clear();
    cb_cate->addItems({"Deposit","CreditCard","Daikuan","System"});

}

void SystemWidget::user_add()
{
    auto text=QInputDialog::getText(this,tr("Input "),tr("Please Input passwd"));
    //TODO passwd check
    auto ret=ctrl.use_register(cb_cate->currentIndex()+1,text,cb_sys->isChecked());
    if(ret.first){
        QMessageBox::information(this,tr("Success"),tr("ID:")+ret.second+tr("Register Success"));
    }else{
        QMessageBox::warning(this,tr("Error"),ret.second);
    }


}

void SystemWidget::user_delete()
{
    auto id=QInputDialog::getText(this,tr("Input"),tr("Please input ID to delete"));
    auto ret=ctrl.user_delete(id);
    if(ret.first){
        QMessageBox::information(this,tr("Success"),tr("Delete Success"));
    }else{
        QMessageBox::warning(this,tr("ERROR"),ret.second);
    }

}

void SystemWidget::plan_add()
{

    auto date=de_time->dateTime();

    timer.setSingleShot(true);
    timer.setInterval(date.toMSecsSinceEpoch()-QDateTime::currentMSecsSinceEpoch());

    timer_aux.setInterval(1000);
    timer_aux.setSingleShot(false);

    connect(&timer_aux,&QTimer::timeout,this,[this](){
        lb_started->setText("Started:Remained:"+QString::number(timer.remainingTime()/1000));

    });

        QList<float> list;
    list.append(le_deposit_current->text().toFloat());
    list.append(le_deposit_one_year->text().toFloat());
    list.append(le_deposit_five_year->text().toFloat());
    list.append(le_daikuan_lilv->text().toFloat());
    list.append(le_credit_enchashment_fee->text().toFloat());
    list.append(le_credit_interest->text().toFloat());
    list.append(le_credit_overdue_fine->text().toFloat());
    list.append(le_waihui_usd->text().toFloat());
    list.append(le_waihui_yen->text().toFloat());
    list.append(le_waihui_euro->text().toFloat());

    connect(&timer,&QTimer::timeout,this,[this,list](){

    this->update_data(true,list);
        timer.stop();
        timer_aux.stop();
    });

    timer.start();
    timer_aux.start();

    lb_started->setText("Started:No");
    lm_model->insertRow(0);
    lm_model->setData(lm_model->index(0),"On "+date.toString()+"Set Current:"+QString::number(list.at(0))+" etc.");
}

void SystemWidget::plan_delete()
{

    timer.stop();
    timer_aux.stop();
    lm_model->removeRow(0);
}

void SystemWidget::init_ui()
{
    layout_main->addWidget(gb_credit_card,0,0);
    layout_main->addWidget(gb_daikuan,0,1);
    layout_main->addWidget(gb_deposit,1,0);
    layout_main->addWidget(gb_waihui,1,1);
    layout_main->addWidget(gb_user_manage,2,0);;
    layout_main->addWidget(gb_plan,2,1);

    layout_main->addWidget(btn_accept,3,0);
    layout_main->addWidget(btn_reset,3,1);




    gb_credit_card->setLayout(fl_credit_card);
    gb_daikuan->setLayout(fl_daikuan);
    gb_deposit->setLayout(fl_deposit);
    gb_waihui->setLayout(fl_waihui);
    gb_user_manage->setLayout(fl_user);
    gb_plan->setLayout(layout_plan);


    fl_credit_card->addRow(tr("CreditCard Interest"),le_credit_interest);
    fl_credit_card->addRow(tr("Enchashment fee"),le_credit_enchashment_fee);
    fl_credit_card->addRow(("CreditCard Overdur Fine"),le_credit_overdue_fine);

    fl_daikuan->addRow(tr("Daikuan interest"),le_daikuan_lilv);

    fl_deposit->addRow(tr("Current INterest"),le_deposit_current);
    fl_deposit->addRow(tr("One INterest"),le_deposit_one_year);
    fl_deposit->addRow(tr("Five INterest"),le_deposit_five_year);

    fl_waihui->addRow(tr("EURO"),le_waihui_euro);
    fl_waihui->addRow(tr("USD"),le_waihui_usd);
    fl_waihui->addRow(tr("YEN"),le_waihui_yen);


    fl_user->addRow(tr("SystemUser"),cb_sys);
    fl_user->addRow(tr("Categ"),cb_cate);
    fl_user->addRow(tr("ADD USER"),btn_add_user);
    fl_user->addRow(tr("Delete USER"),btn_delete_user);

    layout_plan->addWidget(lv_plan);
    layout_plan->addWidget(lb_started);

    layout_plan->addWidget(de_time);
    layout_plan->addWidget(btn_plan_add);
    layout_plan->addWidget(btn_plan_delete);


}

void SystemWidget::init_res()
{
    layout_main=new QGridLayout(this);

    gb_credit_card=new QGroupBox(tr("Credit Card"));
    gb_daikuan=new QGroupBox(tr("Daikuan"));
    gb_deposit=new QGroupBox(tr("Deposit"));
    gb_waihui=new QGroupBox(tr("Wai hui"));
    gb_user_manage=new QGroupBox(tr("User Manager"));
    gb_plan=new QGroupBox(tr("Modify Plan"));

    fl_credit_card=new QFormLayout();
    fl_daikuan=new QFormLayout();
    fl_deposit=new QFormLayout();
    fl_waihui=new QFormLayout();
    fl_user=new QFormLayout();
    layout_plan=new QVBoxLayout();


    le_daikuan_lilv=new QLineEdit;

    le_credit_interest=new QLineEdit;
    le_credit_enchashment_fee=new QLineEdit;
    le_credit_overdue_fine=new QLineEdit;

    le_deposit_current=new QLineEdit;
    le_deposit_five_year=new QLineEdit;
    le_deposit_one_year=new QLineEdit;

    le_waihui_euro=new QLineEdit;
    le_waihui_usd=new QLineEdit;
    le_waihui_yen=new QLineEdit;


    btn_accept=new QPushButton(tr("Accept"));
    btn_reset=new QPushButton(tr("Reset"));

    btn_add_user=new QPushButton(tr("Add User"));
    btn_delete_user=new QPushButton(tr("DELETE USER"));
    btn_plan_add=new QPushButton(tr("ADD PLAN"));
    btn_plan_delete=new QPushButton(tr("DELETE PLAN"));

    lv_plan=new QListView;
    de_time=new QDateTimeEdit;
    cb_cate=new QComboBox;
    cb_sys=new QCheckBox;

    lb_started=new QLabel("Started:No");

    lm_model=new QStringListModel;

}

