
#include "BankSystem.h"

#include "../databaseutils.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

#define DEBUG_PRE "BankSystem:"


one_card_account::one_card_account(QString idc)
{

    id_card=idc;
}

void one_card_account::set_phone_number() {
}

void one_card_account::set_online_bank_status(bool flag)
{
    if(flag){
        auto db=DataBaseUtils::getInstance();
        if(!db.open()){
            return ;
        }else{
            //WARNING simple handle
            QSqlQuery query(db);
            QString tmp=
            "UPDATE  one_card SET online_bank = 'TRUE' WHERE id_card='%1' ";
            QString stmt=tmp.arg(id_card);
            if(query.exec(stmt)){
                qDebug()<<DEBUG_PRE<<"Open online bank success";
            }else{
                qDebug()<<DEBUG_PRE<<query.lastError();
            }



        }
    }

}

void one_card_account::change_passwd(QString n)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return ;
    }else{
        QSqlQuery query(db);
        QString tmp=
        "UPDATE one_card SET passwd='%1' WHERE id_card='%2'";
        QString stmt=tmp.arg(n).arg(id_card);
        qDebug()<<DEBUG_PRE<<stmt;
        if(query.exec(stmt)){
            qDebug()<<DEBUG_PRE<<"Change Passwd Successed";
        }else{
            qDebug()<<DEBUG_PRE<<query.lastError();
        }

    }

}

void one_card_account::create(QString name, QString idcard, QString address, QString phone, QString passwd)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return ;
    }else{
        QSqlQuery query(db);
        QString stmt="INSERT INTO one_card (owner_name,id_card,address,phone_number,passwd) "
                     " VALUES ('%1','%2','%3','%4','%5')";
        QString pre=stmt.arg(name).arg(idcard).arg(address).arg(phone).arg(passwd);
        qDebug()<<pre;
       // query.prepare("INSERT INTO one_card (owner_name,id_card,address,phone_number,passwd) "
       //               " VALUE (?,?,?,?,?)");
       // query.addBindValue(name);
       // query.addBindValue(idcard);
       // query.addBindValue(address);
       // query.addBindValue(phone);
       // query.addBindValue(passwd);
        if(query.exec(pre)){
            qDebug()<<DEBUG_PRE<<"CREATE SUCCESS";
        }else{
            qDebug()<<DEBUG_PRE<<query.lastError();
            qDebug()<<DEBUG_PRE<< query.executedQuery();
            qDebug()<<DEBUG_PRE<<query.lastQuery();
        }

    }

}

void one_card_account::set_loss(bool flag)
{
    auto db=DataBaseUtils::getInstance();
    QSqlQuery query(db);
    QString tmp=
    "UPDATE one_card SET lost= '%1',lost_time='%2' WHERE id_card='%3'";
    QString stmt=tmp.arg(flag).arg(QDate::currentDate().toString()).arg(id_card);
    if(query.exec(stmt)){
        qDebug()<<DEBUG_PRE<<"set_loss success";
    }else{
        qDebug()<<query.lastError();
    }

}

QPair<bool, QDate> one_card_account::get_loss()
{
    auto db=DataBaseUtils::getInstance();
    QSqlQuery query(db);

    QString tmp=
"SELECT lost,lost_time FROM one_card WHERE id_card='%1'";
    QString stmt=tmp.arg(id_card);
    if(query.exec(stmt)){
        QPair<bool,QDate> ret;
        ret.first=false;
        if(query.next()){
            ret.first=query.value(0).toBool();
            ret.second=QDate::fromString(query.value(1).toString());
        }
        return ret;

    }else{
        qDebug()<<query.lastError();
        return {false,QDate()};
    }

}

bool one_card_account::check_if_exist(QString id)
{

    auto db=DataBaseUtils::getInstance();
    auto query=db.exec("SELECT COUNT(*) FROM one_card WHERE id_card='"+id+"'");

    if(query.next()){
        if(query.value(0).toInt()==0){
            return false;
        }else{
            return true;
        }
    }else{
    return false;
    }

}



