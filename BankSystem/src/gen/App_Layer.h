#ifndef _APP_LAYER_H
#define _APP_LAYER_H

#include <QPair>
#include <QString>



class one_card_control {
  public:

    bool set_onecard(QString id);
    QString get_onecard();




    QPair<bool,QString> register_user(QString name,QString idcard,QString address,QString phone,QString passwd);

    QPair<bool,QString> open_online_bank_system_of(QString name,QString passwd);

    void delete_account_of();

    QPair<bool,QString> change_passwd(QString orig,QString npasswd);


    void  transfer_money();

    bool set_loss();

    bool is_lost();

    float get_lilv(int t);

    QPair<bool,QString> deposit(int mk, int type, int benjin, int cunqi, float lilv, bool auto_continue,QString reason="DEPOSIT");

    QPair<bool,QString> withdraw(int id,int count,QString reason,QString type);

    QPair<bool,QString> cancel_loss();

    QPair<bool,QString> reapply_one_card();
    QString get_idcard();

    QString onecard;
private:
    bool exists;

};
#endif
