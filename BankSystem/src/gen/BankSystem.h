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
    float dingqi_lilv;

    int dingqi_nianxian;

    QDate dingqi_shijian;


    float benjin;

};
class current_saving {
  private:
//    int tianshu;

    float benjin;

};
//class kehu {
//  private:
//    one_card_account * ;

//};
class one_card_account {

  private:
//    kehu * ;

    vector<saving_subaccount *> subaccount;

    /**
     * @brief id 以1开头的10位数字
     */
    char id[11];


    string owner_name;

    QString id_card;

    string address;

    string phone_number;

    string passwd;

    bool online_bank = false;

    string online_name;

    string online_passwd;

    bool lost = false;


  public:
    one_card_account(QString idc);

    void set_name();

    void set_idcard();

    void set_address();

    void set_phone_number();

    void  set_passwd();

    saving_subaccount *get_sub_account();


    void  set_online_bank_status(bool flag);

    void  withdrawal_money();

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
class interest_table {
  private:
    float current_interest;

    float fixed_interest_1;

    float fixed_interest_5;

};
#endif
