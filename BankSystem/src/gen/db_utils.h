#ifndef _DB_UTILS_H
#define _DB_UTILS_H

#include <QString>



class DB {
  public:
    DB();
     void virtual  create()=0;

     void virtual  delete_item()=0;

     void virtual  query()=0;

     void virtual  update()=0;
     virtual ~DB();


};
class one_card_account_db :public DB {
  public:
    one_card_account_db();
//     bool virtual check_if_exist(QString id)=0;
     virtual ~one_card_account_db();


};
#endif
