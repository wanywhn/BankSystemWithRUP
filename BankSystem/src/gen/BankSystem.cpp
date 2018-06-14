
#include "BankSystem.h"

#include "../databaseutils.h"
#include "../common_const.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>


#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define DEBUG_PRE __FILE__ "BankSystem:" TOSTRING(__LINE__)

one_card_account::one_card_account(QString ocd)
{

    one_card=ocd;
    auto db=DataBaseUtils::getInstance();
    db.open();
    QSqlQuery query(db);
    QString tmp="SELECT idcard FROM one_card WHERE id='%1'";
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
        QString tmp;
        switch (t) {
        case LILV_CURRENT:{
            tmp="SELECT current FROM lilv ";
            break;
        }
        case LILV_ONE:{
            tmp="SELECT one_year FROM lilv ";
            break;
        }
        case LILV_FIVE:{
            tmp="SELECT five_year FROM lilv ";
            break;
        }
        }
//        QString stmt=tmp.arg(t);
        if(query.exec(tmp)){
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
            "UPDATE  id_card SET online_bank = '%1' ,online_name='%2',passwd='%3' WHERE iid='%4' ";
            QString stmt=tmp.arg(flag?1:0).arg(name).arg(passwd).arg(id_card);
            qDebug()<<DEBUG_PRE<<stmt;
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
            if(abs(benjin-count)<0.001){
               tmp="DELETE FROM card_saving WHERE cid='%1' AND sid='%2'" ;
               stmt=tmp.arg(one_card).arg(id);
               if(!query.exec(stmt)){
                   return {false,query.lastError().text()};
               }
               tmp="DELETE FROM saving_subaccount WHERE id='%1'";
               stmt=tmp.arg(id);
               if(!query.exec(stmt)){
                   return {false,query.lastError().text()};
               }

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
        QString tmp="SELECT MAX(id) FROM saving_subaccount WHERE cid='%1' ";
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
            tmp="INSERT INTO saving_subaccount VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')";
            stmt=tmp.arg(sid.toInt()).arg(type).arg(benjin).arg(cunqi).arg(lilv).arg(QDate::currentDate().toString("yyyy-MM-dd")).arg(auto_continue).arg(0).arg(sid.left(1)).arg(one_card);
        qDebug()<<DEBUG_PRE<<stmt;
        if(query.exec(stmt)){
//            tmp="INSERT INTO card_saving VALUES('%1','%2')";
//            stmt=tmp.arg(one_card).arg(sid);
//            query.exec(stmt);
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
            qDebug()<<DEBUG_PRE<<query.lastError();
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




QPair<bool, QString> sys_ctrl::login(QString name, QString passwd)
{
   auto db=DataBaseUtils::getInstance();
   if(!db.open()){
       return {false,db.lastError().text()};
   }
   QString tmp="SELECT passwd FROM sys_acc_tb WHERE id='%1'";
   QSqlQuery query(db);
   if(!query.exec(tmp.arg(name))){
       return {false,query.lastError().text()};
   }
   query.next();
   auto spasswd=query.value(0).toString();
   if(spasswd==passwd){
       return {true,""};
   }else{
       return{false,"Passwd Wrong"};
   }
}
QPair<bool, QString> online_ctrl::login(QString name, QString passwd)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,db.lastError().text()};
    }

    QString tmp="SELECT passwd,iid FROM id_card WHERE online_name='%1'";
    QSqlQuery query(db);
    if(!query.exec(tmp.arg(name))){
        return {false,query.lastError().text()};
    }
    if(query.size()==0){
        return {false,"It seems that you haven't open the online bank"};
    }
    query.next();
    if(passwd.compare(query.value(0).toString())!=0){
        return {false,"you may enter a wrong passwd"};
    }

    this->idcard=query.value(1).toString();
        return {true,""};

}

QPair<bool, QString> online_ctrl::change_passwd(QString name, QString origin, QString n)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,db.lastError().text()};
    }
    QSqlQuery query(db);
    QString tmp="SELECT passwd FROM id_card WHERE online_name='%1'";
    if(!query.exec(tmp.arg(name))){
        return {false,query.lastError().text()};
    }
    query.next();
    if(query.size()==0){
        return {false,"you haven't open the online bank"};
    }
    if(origin.compare(query.value(0).toString())!=0){
        return {false,"Origin passwd Wrong"} ;
    }
    tmp="UPDATE id_card SET passwd = '%1' WHERE online_name='%2'";
    if(!query.exec(tmp.arg(n).arg(name))){
        return {false,query.lastError().text()};
    }
    return {true,""};



}

bool online_ctrl::set_idcard(QString id)
{
    this->idcard=id;

}

QString online_ctrl::get_idcard()
{
    return idcard;
}

QPair<bool, QString> sys_ctrl::change_passwd(QString name,QString origin, QString n)
{
    auto db=DataBaseUtils::getInstance();
    QString tmp="SELECT passwd FROM sys_acc_tb WHERE id='%1";
    if(!db.open()){
        return {false,"Can't open DB"};
    }
    QSqlQuery query(db);
    if(!query.exec(tmp.arg(name))){
        return {false ,query.lastError().text()};
    }
    query.next();
    QString spasswd=query.value(0).toString();
    if(spasswd!=origin){
        return {false,"Origin Passwd Wrong"};
    }
    tmp="UPDATE sys_acc_tb SET passwd = '%1' WHERE id='%2'";
    if(!query.exec(tmp.arg(n).arg(name))){
        return {false,query.lastError().text()};
    }
    return {true,""};





}

bool sys_ctrl::set_idcard(QString id)
{
    this->idcard=id;


}

QString sys_ctrl::get_idcard()
{
    return idcard;
}

QPair<bool, QString> credit_crtl::pay(QString credit_id, float value, QString reason)
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
    tmp="UPDATE credit_card SET interest_free_money=interest_free_money-%1,used=used+%2 WHERE id='%3' ";
    if(!query.exec(tmp.arg(value).arg(value).arg(credit_id))){
        return {false,query.lastError().text()};
    }
    //UPDATE credit_consume
    tmp="UPDATE credit_consume SET total=total+'%1' WHERE id='%2'";
    if(!query.exec(tmp.arg(value).arg(credit_id))){
        return {false,query.lastError().text()};
    }
    //UPDATE consume_log
    tmp="INSERT INTO  consume_log(figure,reason,date,cid) VALUES ('%1','%2','%3','%4')";
    if(!query.exec(tmp.arg(value).arg(reason).arg(QDate::currentDate().toString()).arg(credit_id))){
        return {false,query.lastError().text()};
    }


}

QPair<bool, QString> credit_crtl::enchashmen(QString credit_id, QString passwd, float value)
{
    if(!checkifexists(credit_id)){
        return {false,"Can't find your Credit Card"};
    }
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,db.lastError().text()};
    }
    QSqlQuery query(db);
    //Check if > 0.7
    QString tmp="SELECT credit FROM credit_card WHERE id='%1'";
    if(!query.exec(tmp.arg(credit_id))){
        return {false,query.lastError().text()};
    }
    query.next();
    auto max=query.value(0).toFloat();
    if(value>max*0.7){
        return {false,"Sorry You can only enchashment "+QString::number(max*0.7)};
    }
    //Check if enough
    if(!checkifenough(value,credit_id)){
        return {false,"You don't have enough money"};
    }
    //UPDATE enchashment
    tmp="INSERT INTO ehchashment (figure,server_charge,enchashment_interest) VALUES ('%1','%2',0)";
    //TODO server_charge
    if(!query.exec(tmp.arg(value).arg(value*0.05))){
        return {false,query.lastError().text()};
    }
    //TODO CREATE TRIGGER
    //UPDATE consume_log
    tmp="INSERT INTO consume_log (figure ,reason,date,cid) VALUES ('%1','%2','%3','%4')";
    if(!query.exec(tmp.arg(value).arg("ENCHASHMENT").arg(QDate::currentDate().toString()).arg(credit_id)));{
        return {false,query.lastError().text()};
    }
    //UPDATE credit_card
    tmp="UPDATE credit_card SET interest_free_money=interest_freemoney-%1,used=used+'%2'";
    if(!query.exec(tmp.arg(value*1.05).arg(value*1.05))){
        return {false,query.lastError().text()};
    }





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

