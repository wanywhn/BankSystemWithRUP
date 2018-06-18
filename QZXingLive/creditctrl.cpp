#include "creditctrl.h"
#include <QDate>
#include <QDebug>
#include "databaseutils.h"
#include <QSqlQuery>

#define DEBUG_PRE "CREDITCTRL"
CreditCtrl::CreditCtrl(QObject *parent) : QObject(parent)
{

}

void CreditCtrl::pay(QString creditid, int value, QString type)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QSqlQuery query(db);
    QString tmp="SELECT cid FROM credit_card WHERE id='%1'";
    if(!query.exec(tmp.arg(creditid))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return;
    }
    query.next();
    QString cid=query.value(0).toString();
    credit_crtl ctrl(cid);
    ctrl.pay(creditid,value,"",type);


}

void
    CreditCtrl::log(QString reason, int count, QString id, QString cid,QString type){
        QString tmp="INSERT INTO consume_log (figure,reason,date,cid,cardid,type) VALUES('%1','%2','%3','%4','%5','%6')";
        auto db=DataBaseUtils::getInstance();
        if(!db.open()){
            qDebug()<<DEBUG_PRE<<db.lastError();
            return ;
        }
        QSqlQuery query(db);
        QString stmt=
        tmp.arg(count).arg(reason).arg(QDate::currentDate().toString("yyyy-MM-dd")).arg(cid).arg(id).arg(type);
        if(!query.exec(stmt)){
        qDebug()<<DEBUG_PRE<<"stmt:"<<stmt;
                qDebug()<<DEBUG_PRE<<query.lastError();
                return ;
    }
        qDebug()<<DEBUG_PRE<<"LOG SUCCESSED";

}
credit_crtl::credit_crtl(QString id)
{
   id_card=id;
}

QPair<bool, QString> credit_crtl::pay(QString credit_id, float value, QString reason, QString type)
{
    if(credit_id.isEmpty()){
        return {false,QObject::tr("Please Input CreditCard ID")};
    }
    if(value<=0){
        return {false,QObject::tr("pay Count ERROR:")+QString::number(value)};
    }
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,QObject::tr("DB Open Failed:")+db.lastError().text()};
    }

    QSqlQuery query(db);
    if(!checkifexists(credit_id)){
        return {false,"Can't find the Credit Card"};
    }

    //Check if credit gt value
    if(!checkifenough(value,credit_id)){
        return {false,"You don't have enough credit"};
    }
    //UPDATE credit_card
    QString
    tmp="UPDATE credit_card SET interest_free_money=interest_free_money-'%1',used=used+'%2' WHERE id='%3' ";
    if(!query.exec(tmp.arg(value).arg(value).arg(credit_id))){
        return {false,query.lastError().text()};
    }
    //UPDATE credit_consume
    tmp="UPDATE credit_consume SET total=total+'%1' WHERE id='%2'";
    if(!query.exec(tmp.arg(value).arg(credit_id))){
        return {false,query.lastError().text()};
    }
    //UPDATE consume_log
    CreditCtrl::log(reason,value,credit_id,id_card,type);
//    tmp="INSERT INTO  consume_log(figure,reason,date,cid,cardid) VALUES ('%1','%2','%3','%4','%5')";
//    if(!query.exec(tmp.arg(value).arg(reason).arg(QDate::currentDate().toString()).arg(credit_id).ar(id_card))){
//        return {false,query.lastError().text()};
//    }


}

bool credit_crtl::checkifexists(QString id)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<"Open DB ERROR";
    }
    QSqlQuery query(db);
    QString tmp="SELECT COUNT(*) FROM credit_card WHERE id='%1' ";
    if(!query.exec(tmp.arg(id))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return false;
    }
    if(query.size()==0){
        return false;
    }
    return true;

}

bool credit_crtl::checkifenough(float value, QString credit_id)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<"Open DB failed"<<db.lastError();
        return false;
    }
    QSqlQuery query(db);
    QString tmp="SELECT interest_free_money FROM credit_card WHERE id='%1'";
    if(!query.exec(tmp.arg(credit_id))){
        return false;
    }
    auto curr_credit=query.value(0).toFloat();
    if((value-curr_credit)<0){
        return false;
    }
    return true;
}
