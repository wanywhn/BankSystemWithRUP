
#include "BankSystem.h"

#include "../databaseutils.h"



one_card_account::one_card_account():one_card_account_db()
{

}

void one_card_account::set_phone_number() {
}

void one_card_account::create(QString name, QString idcard, QString address, QString phone, QString passwd)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return ;
    }else{
        //TODO create sql table row
    }

}

bool one_card_account::check_if_exist(QString id)
{

}



