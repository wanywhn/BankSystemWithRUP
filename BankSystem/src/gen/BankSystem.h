#ifndef _BANKSYSTEM_H
#define _BANKSYSTEM_H


#include "db_utils.h"

#include <vector>
#include <string>
#include <QDate>
using namespace std;

class current_saving;
class fixed_deposit;

class saving_subaccount {
  private:
    /**
     * @brief id 第一位表示币种，第二位表示储蓄种类
     */
    char id[6];

    uchar type;

    union{
        current_saving *current;
        fixed_deposit *fixed;
    }body;



  public:
    void  add_huoqi();

    void  add_dingqi();

    void  add_dinghuo();

    void  deposit();

    void  withdrawal();

    void  transfer_money();

};
class fixed_deposit {
  private:

    QDate dingqi_shijian;



};
class current_saving {
  private:
//    int tianshu;


};
//class kehu {
//  private:
//    one_card_account * ;

//};
class one_card_account {

public:
    one_card_account(QString ocd);
  private:
//    kehu * ;

    QString id_card;
    QString one_card;
    vector<saving_subaccount *> subaccount;

public:
    void set_phone_number();

    void  set_passwd();

    saving_subaccount *get_sub_account();

    float get_lilv(int t);

    void  set_online_bank_status(bool flag,QString name="",QString passwd="");

    QPair<bool,QString> withdrawal_money(int id,int count);

    void  change_passwd(QString n);

    QPair<bool,QString> deposit(int mk, int type, int benjin, int cunqi, float lilv, int auto_continue);

    void create(QString name ,QString idcard,QString address,QString phone ,QString passwd);

    void set_loss(bool flag);
    QPair<bool,QDate> get_loss();

    // DB interface

    // one_card_account_db interface
public:
    static bool check_if_exist(QString id);
};
class sys_ctrl{

public:
    QPair<bool,QString> login(QString name ,QString passwd);
        QPair<bool,QString> change_passwd(QString name, QString origin, QString n);



};
class credit_crtl{

public:
    QPair<bool,QString> pay(QString credit_id,float value,QString reason);
    QPair<bool,QString> enchashmen(QString credit_id,QString passwd,float value);
};
#endif
