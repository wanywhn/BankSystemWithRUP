
#include "App_Layer.h"
#include "BankSystem.h"
#include <QObject>

void one_card_control::set_name() {
}

void one_card_control::set_idcard(QString id)
{
    if(true==one_card_account::check_if_exist(id))
        exists=true;

    idcard=id;
}


void one_card_control::set_address() {
}

void one_card_control::set_phone_number() {
}

void one_card_control::set_passwd() {
}

QPair<bool, QString> one_card_control::register_user(QString name,
             QString idcard, QString address, QString phone, QString passwd) {


    if(name.isEmpty()||idcard.isEmpty()||address.isEmpty()||phone.isEmpty()||passwd.isEmpty()){
        return {false,QObject::tr("Please fill the form")};
    }
    //TODO check the param;

    one_card_account tmp(idcard);

    if(exists){
        return {false,QObject::tr("You had open an One Card")};
    }else{
        tmp.create(name,idcard,address,phone,passwd);
        return {true,""};
    }

}

QPair<bool, QString> one_card_control::open_online_bank_system_of() {
    if(exists){
        one_card_account tmp(idcard);
        tmp.set_online_bank_status(true);
        return {true,""};
    }else{
        return {false,QObject::tr("You hadn't open the one card")};
    }
}

void one_card_control::delete_account_of() {
}

QPair<bool, QString> one_card_control::change_passwd(QString orig, QString npasswd) {
    one_card_account tmp(idcard);
    tmp.change_passwd(npasswd);
    return {true,""};
}

void  one_card_control::set_target_idcard() {
}
void  one_card_control::transfer_money() {
}
void  one_card_control::set_loss() {
    one_card_account tmp(idcard);
    tmp.set_loss(true);
}
void  one_card_control::deposit() {
}
QPair<bool, QString> one_card_control::cancel_loss() {
    one_card_account tmp(idcard);
    auto ret=tmp.get_loss();
    if(ret.first){
        tmp.set_loss(false);
        return {true,""};
        }else{
            return {false,"the one card havn't been lost"};
            }


}
QPair<bool, QString> one_card_control::reapply_one_card() {
    one_card_account tmp(idcard);
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

