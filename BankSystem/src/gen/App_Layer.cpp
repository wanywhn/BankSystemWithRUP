
#include "App_Layer.h"
#include "BankSystem.h"
#include <QMessageBox>


bool one_card_control::set_onecard(QString id)
{
    if(one_card_account::check_if_exist(id)){


    onecard=id;
        exists=true;
        return true;
    }else{
        exists=false;
        return false;
    }
}

QString one_card_control::get_onecard()
{

    return onecard;
}





QPair<bool, QString> one_card_control::register_user(QString name,
             QString idcard, QString address, QString phone, QString passwd) {


    if(name.isEmpty()||idcard.isEmpty()||address.isEmpty()||phone.isEmpty()||passwd.isEmpty()){
        return {false,QObject::tr("Please fill the form")};
    }
    //TODO check the param;

    //haven't have one_card;
    one_card_account tmp("");

//    if(exists){
//        return {false,QObject::tr("You had open an One Card")};
//    }else{
        return {true,
        tmp.create(name,idcard,address,phone,passwd)};
//    }

}

QPair<bool, QString> one_card_control::open_online_bank_system_of(QString name,QString passwd) {
    if(exists){
        one_card_account tmp(onecard);
        tmp.set_online_bank_status(true,name,passwd);
        return {true,""};
    }else{
        return {false,QObject::tr("You hadn't open the one card")};
    }
}

void one_card_control::delete_account_of() {
}

QPair<bool, QString> one_card_control::change_passwd(QString orig, QString npasswd) {
    one_card_account tmp(onecard);
    tmp.change_passwd(npasswd);
    return {true,""};
}

void  one_card_control::transfer_money() {
}
bool one_card_control::set_loss() {
    one_card_account tmp(onecard);
    return tmp.set_loss(true);
}

bool one_card_control::is_lost()
{
    one_card_account tmp(onecard);
    return tmp.get_loss().first;
}

float one_card_control::get_lilv(int t)
{
    one_card_account tmp(onecard);
    return tmp.get_lilv(t);
}

QPair<bool, QString> one_card_control::deposit(int mk, int type, int benjin, int cunqi, float lilv, bool auto_continue, QString reason)
{

    one_card_account tmp(onecard);
    return tmp.deposit(mk,type,benjin,cunqi,lilv,auto_continue,reason);


}

QPair<bool, QString> one_card_control::withdraw(int id, int count, QString reason, QString type)
{
    one_card_account tmp(onecard);
    return tmp.withdrawal_money(id,count,reason,type);

}
QPair<bool, QString> one_card_control::cancel_loss() {
    one_card_account tmp(onecard);
    auto ret=tmp.get_loss();
    if(ret.first){
        tmp.set_loss(false);
        return {true,""};
        }else{
            return {false,"the one card havn't been lost"};
            }


}
QPair<bool, QString> one_card_control::reapply_one_card() {
    one_card_account tmp(onecard);
    auto ret=tmp.get_loss();
    if(ret.first){
        if(ret.second.daysTo(QDate::currentDate())>7){
        tmp.set_loss(false);
        return {true,""};
        }else{
            return {false,"Please wait till "+ret.second.addDays(7).toString()};
        }
    }else{
        return {false,"the One Card havn't been lost"};
    }
}

QString one_card_control::get_idcard()
{
   one_card_account tmp(onecard);
   return tmp.get_idcard();

}

