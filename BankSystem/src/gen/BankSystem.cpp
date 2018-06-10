
#include "BankSystem.h"

#include "../databaseutils.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

#define DEBUG_PRE "BankSystem:"


one_card_account::one_card_account(QString ocd)
{

    one_card=ocd;
    auto db=DataBaseUtils::getInstance();
    db.open();
    QSqlQuery query(db);
    QString tmp="SELECT idcard FROM one_card WHERE iid='%1'";
    query.exec(tmp.arg(ocd));
    query.next();

    id_card=query.value(0).toString();
}

void one_card_account::set_phone_number() {
}

float one_card_account::get_lilv(int t)
{

    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return 0;
    }else{
        QSqlQuery query(db);
        QString tmp="SELECT d FROM lilv WHERE type='%1'";
        QString stmt=tmp.arg(t);
        if(query.exec(stmt)){
            if(query.next()){
            return query.value(0).toFloat();

            }else{
                return -2;
            }

        }else{
            qDebug()<<DEBUG_PRE<<query.lastQuery();
            qDebug()<<DEBUG_PRE<<query.lastError();
            return -1;
        }

    }
}

void one_card_account::set_online_bank_status(bool flag, QString name, QString passwd)
{
    if(flag){
        auto db=DataBaseUtils::getInstance();
        if(!db.open()){
            return ;
        }else{
            //WARNING simple handle
            QSqlQuery query(db);
            QString tmp=
            "UPDATE  id_card SET online_bank = '%1' ,online_name='%2',online_passwd='%3' WHERE id='%4' ";
            QString stmt=tmp.arg(flag?"TRUE":"FALSE").arg(name).arg(passwd).arg(id_card);
            if(query.exec(stmt)){
                qDebug()<<DEBUG_PRE<<"Open online bank success";
            }else{
                qDebug()<<DEBUG_PRE<<query.lastError();
            }



        }
    }

}

QPair<bool, QString> one_card_account::withdrawal_money(int id, int count)
{

    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,"Open DataBase Failed"};
    }else{
        QString tmp="SELECT benjin FROM saving_subaccount WHERE id='%1'";
        QString stmt=tmp.arg(id);
        QSqlQuery query(db);
        if(query.exec(stmt)){
            if(query.next()){
            auto benjin=query.value(0).toDouble();
            if(benjin==count){
               tmp="DELETE FROM card_svaing WHERE cid='%1' AND sid='%2'" ;
               stmt=tmp.arg(one_card).arg(id);
               query.exec(stmt);
               tmp="DELETE FROM saving_subaccount WHERE id='%1'";
               stmt=tmp.arg(id);
               query.exec(stmt);

               return {true,""};
            }else if(benjin>count){
               tmp="UPDATE saving_subaccount SET benjin='%1' WHERE id='%2'";
               stmt=tmp.arg(benjin-count).arg(id);
               query.exec(stmt);

               return {true,""};
            }else{
                return {false,"Your Account don't have such money"};
            }
            }


        }else{
            return {false,query.lastError().text()};
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
        "UPDATE one_card SET passwd='%1' WHERE id='%2'";
        QString stmt=tmp.arg(n).arg(one_card);
        qDebug()<<DEBUG_PRE<<stmt;
        if(query.exec(stmt)){
            qDebug()<<DEBUG_PRE<<"Change Passwd Successed";
        }else{
            qDebug()<<DEBUG_PRE<<query.lastError();
        }

    }

}

QPair<bool, QString> one_card_account::deposit(int mk,int type, int benjin, int cunqi, float lilv, int auto_continue)
{
    //TODO CREATE TRIGGER
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,"Can't open DB"};
    }else{
        QSqlQuery query(db);
        QString tmp="SELECT MAX(sid) FROM card_saving WHERE cid='%1' ";
        QString stmt=tmp.arg(one_card);
        qDebug()<<DEBUG_PRE<<stmt;
        if(query.exec(stmt)){
            QString mid;
            if(query.next()){
                mid=QString::number(query.value(0).toInt()+1001).right(3);
            }else{
                mid="000";
            }
            QString sid=QString::number(mk)+QString::number(type)+mid;
            qDebug()<<DEBUG_PRE<<"sid:"<<sid;
            tmp="INSERT INTO saving_subaccount VALUES('%1','%2','%3','%4','%5','%6','%7','%8')";
            stmt=tmp.arg(sid.toInt()).arg(type).arg(benjin).arg(cunqi).arg(lilv).arg(QDate::currentDate().toString()).arg(auto_continue).arg(0);
        qDebug()<<DEBUG_PRE<<stmt;
        if(query.exec(stmt)){
            tmp="INSERT INTO card_saving VALUES('%1','%2')";
            stmt=tmp.arg(one_card).arg(sid);
            query.exec(stmt);
            return {true,""};
        }else{
            return {false,query.lastError().text()};
        }
        }else{
            return {false,query.lastError().text()};
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
        QString tmp="SELECT COUNT(*) FROM id_card WHERE iid='%1'";
        QString stmt=tmp.arg(idcard);
        if(!query.exec(stmt)){
            qDebug()<<query.lastError();
            return;
        }
        query.next();
        if(query.value(0).toInt()==0){
            tmp="INSERT INTO id_card(iid) VALUES('%1')";
            stmt=tmp.arg(idcard);
            if(!query.exec(stmt)){
                qDebug()<<DEBUG_PRE<<query.lastError();
                return ;
            }

        }
        tmp="SELECT MAX(id) FROM one_card ";
        if(!query.exec(tmp)){
            qDebug()<<query.lastError();
            return ;
        }
        int mid;
       if(!query.next()) {
           mid=1000000000;
       }else{
           mid=(query.value(0).toInt()+1)%1000000000+1000000000;
}


        stmt="INSERT INTO one_card (id,owner_name,idcard,address,phone_number,passwd) "
                     " VALUES ('%1','%2','%3','%4','%5','%6')";
        QString pre=stmt.arg(mid).arg(name).arg(idcard).arg(address).arg(phone).arg(passwd);
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
    "UPDATE one_card SET lost= '%1',lost_time='%2' WHERE id='%3'";
    QString stmt=tmp.arg(flag).arg(QDate::currentDate().toString()).arg(one_card);
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
"SELECT lost,lost_time FROM one_card WHERE id='%1'";
    QString stmt=tmp.arg(one_card);
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
    auto query=db.exec("SELECT COUNT(*) FROM one_card WHERE id='"+id+"'");

    if(query.next()){
        return query.value(0).toInt() != 0;
    }else{
    return false;
    }

}



