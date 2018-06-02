#ifndef _CHUXU_YEWU_H
#define _CHUXU_YEWU_H


#include <vector>
using namespace std;
#include <string>
using namespace std;

class saving_info {
  private:
    vector<current_saving *> current;

    vector<fixed_deposit *> fixed;

    vector<dinghuo_liangbian *> ;

    vector<fixed_deposit *> fixed_current;

};
class saving_subaccount {
  private:
    char[6] id;

    saving_info ;


  public:
     add_huoqi();

     add_dingqi();

     add_dinghuo();

};
class dinghuo_liangbian {
};
class fixed_deposit {
  private:
    float dingqi_lilv;

    int dingqi_nianxian;

    Date dingqi_shijian;

    int benjin;

};
class current_saving {
  private:
    int tianshu;

    float benjin;

};
class kehu {
};
class one_card_account {
  private:
    vector<saving_subaccount *> subaccount;

    char[11] id;

    string owner_name;

    string id_card;

    string address;

    string phone_number;

    string passwd;

    bool online_bank = false;

    string online_name;

    string online_passwd;

    bool lost = false;


  public:
    string set_name();

    string set_idcard();

    string set_address();

    string set_phone_number();

     set_passwd();

     get_sub_account();

};
class bank_assistant {
};
#endif
