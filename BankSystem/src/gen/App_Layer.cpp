
#include "App_Layer.h"
#include "BankSystem.h"
#include <QObject>

void one_card_control::set_name() {
}

void one_card_control::set_idcard(QString id)
{
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

    one_card_account tmp;

    if(true==one_card_account::check_if_exist(idcard)){
        return {false,QObject::tr("You had open an One Card")};
    }else{
        tmp.create(name,idcard,address,phone,passwd);
        return {true,""};
    }

}

void one_card_control::open_online_bank_system_of() {
}

void one_card_control::delete_account_of() {
}

QPair<bool, QString> one_card_control::change_passwd(QString orig, QString npasswd) {
}

void  one_card_control::set_target_idcard() {
}
void  one_card_control::transfer_money() {
}
void  one_card_control::set_loss() {
}
void  one_card_control::is_lost() {
}
void  one_card_control::deposit() {
}
void  one_card_control::cancel_loss() {
}
void  one_card_control::reapply_one_card() {
}

