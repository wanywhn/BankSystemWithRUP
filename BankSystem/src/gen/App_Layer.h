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

    void open_online_bank_system_of();

    void delete_account_of();

    QPair<bool,QString> change_passwd(QString orig,QString npasswd);

    void  set_target_idcard();

    void  transfer_money();

    void  set_loss();

    void  is_lost();

    void  deposit();

    void  cancel_loss();

    void  reapply_one_card();

private:
    QString idcard;

};
#endif
