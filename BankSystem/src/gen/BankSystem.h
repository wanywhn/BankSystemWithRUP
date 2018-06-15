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

    QString get_idcard();
    void  set_passwd();

    saving_subaccount *get_sub_account();

    float get_lilv(int t);

    void  set_online_bank_status(bool flag,QString name="",QString passwd="");

    QPair<bool,QString> withdrawal_money(int id,int count,QPair<QString,QString> type={"",""});

    /**
     * @brief log  记录某人（cid）在某账户（id）上花费的金额及理由
     * @param reason 理由
     * @param count	金额
     * @param id	该类型对应的ID
     * @param cid	IDCARD
     * @param type	话费类型
     */
    static void log(QString reason,int count,QString id,QString cid,QString type);

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
class interface_ctrl{
public:
    virtual QPair<bool,QString>login(QString name,QString passwd)=0;
    virtual QPair<bool,QString>change_passwd(QString name,QString origin,QString n)=0;
    virtual ~interface_ctrl(){}

    virtual bool set_idcard(QString id)=0;
    virtual QString get_idcard()=0;

};
class sys_ctrl :public interface_ctrl{

public:
    QPair<bool,QString> login(QString name ,QString passwd) override;
        QPair<bool,QString> change_passwd(QString name, QString origin, QString n)override;

private:
        QString idcard;


        // interface_ctrl interface
public:
        bool set_idcard(QString id) override;

        // interface_ctrl interface
public:
        QString get_idcard() override;

private:
};

class online_ctrl :public interface_ctrl{


    // interface_ctrl interface
public:
    QPair<bool, QString> login(QString name, QString passwd) override;
    QPair<bool, QString> change_passwd(QString name, QString origin, QString n) override;

    // interface_ctrl interface
public:
    bool set_idcard(QString id) override;
    QString get_idcard() override;
private:
    QString idcard;
};
class credit_crtl{
public:
    credit_crtl(QString id);


public:
    QPair<bool,QString> pay(QString credit_id,float value,QString reason);
    QPair<bool,QString> enchashmen(QString credit_id,QString passwd,float value);
private:
    bool checkifexists(QString id);
    bool checkifenough(float value,QString credit_id);
    QString id_card;
};
#endif
