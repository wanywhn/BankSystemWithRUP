#ifndef _APP_LAYER_H
#define _APP_LAYER_H

#include <QPair>
#include <QString>



class one_card_control {
  public:
    void set_name();

    void set_idcard(QString id);

    void set_address();

    void set_phone_number();

    void set_passwd();

    QPair<bool,QString> register_user(QString name,QString idcard,QString address,QString phone,QString passwd);

    QPair<bool,QString> open_online_bank_system_of();

    void delete_account_of();

    QPair<bool,QString> change_passwd(QString orig,QString npasswd);

    void  set_target_idcard();

    void  transfer_money();

    void  set_loss();

    bool is_lost();

    QPair<bool,QString> deposit(int mk, int type, int benjin, int cunqi, float lilv, bool auto_continue);

    QPair<bool,QString> cancel_loss();

    QPair<bool,QString> reapply_one_card();

    QString idcard;
private:
    bool exists;

};
#endif
