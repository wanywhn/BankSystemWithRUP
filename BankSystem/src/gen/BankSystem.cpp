
#include "BankSystem.h"

#include "../common_const.h"
#include "../databaseutils.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define DEBUG_PRE __FILE__ "BankSystem:" TOSTRING(__LINE__)

one_card_account::one_card_account(QString ocd) {

  one_card = ocd;
  auto db = DataBaseUtils::getInstance();
  db.open();
  QSqlQuery query(db);
  QString tmp = "SELECT idcard FROM one_card WHERE id='%1'";
  query.exec(tmp.arg(ocd));
  query.next();

  id_card = query.value(0).toString();
}

void one_card_account::set_phone_number() {}

QString one_card_account::get_idcard() { return id_card; }

float one_card_account::get_lilv(int t) {

  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return 0;
  } else {
    QSqlQuery query(db);
    QString tmp;
    switch (t) {
    case LILV_CURRENT: {
      tmp = "SELECT current FROM lilv ";
      break;
    }
    case LILV_ONE: {
      tmp = "SELECT one_year FROM lilv ";
      break;
    }
    case LILV_FIVE: {
      tmp = "SELECT five_year FROM lilv ";
      break;
    }
    }
    //        QString stmt=tmp.arg(t);
    if (query.exec(tmp)) {
      if (query.next()) {
        return query.value(0).toFloat();

      } else {
        return -2;
      }

    } else {
      qDebug() << DEBUG_PRE << query.lastQuery();
      qDebug() << DEBUG_PRE << query.lastError();
      return -1;
    }
  }
}

void one_card_account::set_online_bank_status(bool flag, QString name,
                                              QString passwd) {
  if (flag) {
    auto db = DataBaseUtils::getInstance();
    if (!db.open()) {
      return;
    } else {
      // WARNING simple handle
      QSqlQuery query(db);
      QString tmp = "UPDATE  id_card SET online_bank = '%1' "
                    ",online_name='%2',passwd='%3' WHERE iid='%4' ";
      QString stmt = tmp.arg(flag ? 1 : 0).arg(name).arg(passwd).arg(id_card);
      qDebug() << DEBUG_PRE << stmt;
      if (query.exec(stmt)) {
        qDebug() << DEBUG_PRE << "Open online bank success";
      } else {
        qDebug() << DEBUG_PRE << query.lastError();
      }
    }
  }
}

QPair<bool, QString> one_card_account::withdrawal_money(int id, int count,
                                                        QString reason,
                                                        QString type) {

  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, "Open DataBase Failed"};
  }
  QString tmp =
      "SELECT benjin FROM saving_subaccount WHERE id='%1' AND cid='%2'";
  QString stmt = tmp.arg(id).arg(one_card);
  QSqlQuery query(db);
  if (!query.exec(stmt)) {
    qDebug() << stmt;
    return {false, "Exec failed " + query.lastError().text()};
  }
  if (!query.next()) {
    qDebug() << stmt;
    return {false, "Next Failed " + query.lastError().text()};
  }

  auto benjin = query.value(0).toDouble();
  // TODO
  if (abs(benjin - count) < 0.001) {
//    tmp = "DELETE FROM card_saving WHERE cid='%1' AND sid='%2'";
//    stmt = tmp.arg(one_card).arg(id);
//    if (!query.exec(stmt)) {
//      return {false, query.lastError().text()};
//    }
    tmp = "DELETE FROM saving_subaccount WHERE id='%1'";
    stmt = tmp.arg(id);
    if (!query.exec(stmt)) {
      return {false, query.lastError().text()};
    }

    log(reason, count, one_card, id_card, type);
    return {true, ""};
  } else if (benjin > count) {
    tmp = "UPDATE saving_subaccount SET benjin='%1' WHERE id='%2'";
    stmt = tmp.arg(benjin - count).arg(id);
    query.exec(stmt);

    log(reason, count, one_card, id_card, type);
    return {true, ""};
  } else {
    return {false, "Your Account don't have such money"};
  }
}

void one_card_account::log(QString reason, int count, QString id, QString cid,
                           QString type) {
  QString tmp = "INSERT INTO consume_log (figure,reason,date,cid,cardid,type) "
                "VALUES('%1','%2','%3','%4','%5','%6')";
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << db.lastError();
    return;
  }
  QSqlQuery query(db);
  QString stmt = tmp.arg(count)
                     .arg(reason)
                     .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                     .arg(cid)
                     .arg(id)
                     .arg(type);
  if (!query.exec(stmt)) {
    qDebug() << DEBUG_PRE << "stmt:" << stmt;
    qDebug() << DEBUG_PRE << query.lastError();
    return;
  }
  qDebug() << DEBUG_PRE << "LOG SUCCESSED";
}

void one_card_account::change_passwd(QString n) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return;
  } else {
    QSqlQuery query(db);
    QString tmp = "UPDATE one_card SET passwd='%1' WHERE id='%2'";
    QString stmt = tmp.arg(n).arg(one_card);
    qDebug() << DEBUG_PRE << stmt;
    if (query.exec(stmt)) {
      qDebug() << DEBUG_PRE << "Change Passwd Successed";
    } else {
      qDebug() << DEBUG_PRE << query.lastError();
    }
  }
}

QPair<bool, QString> one_card_account::deposit(int mk, int type, int benjin,
                                               int cunqi, float lilv,
                                               int auto_continue,
                                               QString reason) {
    if(type==1){
        cunqi=0;
    }
    if(type==2&&benjin<100){
        return {false,"should above 100"};
    }
    if(type==3&&benjin<50){
        return {false,"should above 50"};
    }
  // TODO CREATE TRIGGER
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, "Can't open DB"};
  }
  QSqlQuery query(db);
  QString tmp = "SELECT id FROM saving_subaccount WHERE cid='%1' ";
  QString stmt = tmp.arg(one_card);
  qDebug() << DEBUG_PRE << stmt;
  if (!query.exec(stmt)) {
    return {false, query.lastError().text()};
  }
  QString mid;
  QList<int> list;
  while (query.next()) {
      list.append(query.value(0).toInt()%1000+1000);
  }
  if(list.isEmpty()){
      mid="000";
  }else{

    mid = QString::number(*std::max_element(list.begin(),list.end())+1).right(3);
  }
  QString sid = QString::number(mk) + QString::number(type) + mid;
  qDebug() << DEBUG_PRE << "sid:" << sid;
  tmp = "INSERT INTO saving_subaccount "
        "VALUES('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')";
  stmt = tmp.arg(sid.toInt())
             .arg(type)
             .arg(benjin)
             .arg(cunqi)
             .arg(lilv)
             .arg(QDate::currentDate().toString("yyyy-MM-dd"))
             .arg(auto_continue)
             .arg(0)
             .arg(sid.left(1))
             .arg(one_card);
  qDebug() << DEBUG_PRE << stmt;
  if (!query.exec(stmt)) {

    return {false, query.lastError().text()};
  }
  //            tmp="INSERT INTO card_saving VALUES('%1','%2')";
  //            stmt=tmp.arg(one_card).arg(sid);
  //            query.exec(stmt);
  log(reason, benjin, one_card, id_card, "DEPOSIT");
  return {true, ""};
}

QString one_card_account::create(QString name, QString idcard, QString address,
                              QString phone, QString passwd) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return "";
  } else {
    QSqlQuery query(db);
    QString tmp = "SELECT COUNT(*) FROM id_card WHERE iid='%1'";
    QString stmt = tmp.arg(idcard);
    if (!query.exec(stmt)) {
      qDebug() << DEBUG_PRE << query.lastError();
      return "";
    }
    query.next();
    if (query.value(0).toInt() == 0) {
      tmp = "INSERT INTO id_card(iid) VALUES('%1')";
      stmt = tmp.arg(idcard);
      if (!query.exec(stmt)) {
        qDebug() << DEBUG_PRE << query.lastError();
        return "";
      }
    }
    tmp = "SELECT MAX(id) FROM one_card ";
    if (!query.exec(tmp)) {
      qDebug() << query.lastError();
      return "";
    }
    int mid;
    if (!query.next()) {
      mid = 1000000000;
    } else {
      mid = (query.value(0).toInt() + 1) % 1000000000 + 1000000000;
    }

    stmt = "INSERT INTO one_card "
           "(id,owner_name,idcard,address,phone_number,passwd) "
           " VALUES ('%1','%2','%3','%4','%5','%6')";
    QString pre =
        stmt.arg(mid).arg(name).arg(idcard).arg(address).arg(phone).arg(passwd);
    qDebug() << pre;
    // query.prepare("INSERT INTO one_card
    // (owner_name,id_card,address,phone_number,passwd) "
    //               " VALUE (?,?,?,?,?)");
    // query.addBindValue(name);
    // query.addBindValue(idcard);
    // query.addBindValue(address);
    // query.addBindValue(phone);
    // query.addBindValue(passwd);
    if (query.exec(pre)) {
      qDebug() << DEBUG_PRE << "CREATE SUCCESS";
    } else {
      qDebug() << DEBUG_PRE << query.lastError();
      qDebug() << DEBUG_PRE << query.executedQuery();
      qDebug() << DEBUG_PRE << query.lastQuery();
    }
    return QString::number(mid);
  }
}

bool one_card_account::set_loss(bool flag) {
  auto db = DataBaseUtils::getInstance();
  QSqlQuery query(db);
  QString tmp = "UPDATE one_card SET lost= '%1',lost_time='%2' WHERE id='%3'";
  QString stmt =
      tmp.arg(flag).arg(QDate::currentDate().toString("yyyy-MM-dd")).arg(one_card);
  if (query.exec(stmt)) {
    qDebug() << DEBUG_PRE << "set_loss success";
    return true;
  } else {
    qDebug() << query.lastError();
    return false;
  }
}

QPair<bool, QDate> one_card_account::get_loss() {
  auto db = DataBaseUtils::getInstance();
  QSqlQuery query(db);

  QString tmp = "SELECT lost,lost_time FROM one_card WHERE id='%1'";
  QString stmt = tmp.arg(one_card);
  if (query.exec(stmt)) {
    QPair<bool, QDate> ret;
    ret.first = false;
    if (query.next()) {
      ret.first = query.value(0).toBool();
      ret.second = QDate::fromString(query.value(1).toString(),"yyyy-MM-dd");
    }
    return ret;

  } else {
    qDebug() << query.lastError();
    return {false, QDate()};
  }
}

bool one_card_account::check_if_exist(QString id) {

  auto db = DataBaseUtils::getInstance();
  auto query = db.exec("SELECT COUNT(*) FROM one_card WHERE id='" + id + "'");

  if (query.next()) {
    return query.value(0).toInt() != 0;
  } else {
    return false;
  }
}

QPair<bool, QString> sys_ctrl::login(QString name, QString passwd) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }
  QString tmp = "SELECT passwd FROM sys_acc_tb WHERE id='%1'";
  QSqlQuery query(db);
  if (!query.exec(tmp.arg(name))) {
    return {false, query.lastError().text()};
  }
  query.next();
  auto spasswd = query.value(0).toString();
  if (spasswd == passwd) {
    return {true, ""};
  } else {
    return {false, "Passwd Wrong"};
  }
}
QPair<bool, QString> online_ctrl::login(QString name, QString passwd) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }

  QString tmp = "SELECT passwd,iid FROM id_card WHERE online_name='%1'";
  QSqlQuery query(db);
  if (!query.exec(tmp.arg(name))) {
    return {false, query.lastError().text()};
  }
  if (query.size() == 0) {
    return {false, "It seems that you haven't open the online bank"};
  }
  query.next();
  if (passwd.compare(query.value(0).toString()) != 0) {
    return {false, "you may enter a wrong passwd"};
  }

  this->idcard = query.value(1).toString();
  return {true, ""};
}

QPair<bool, QString> online_ctrl::change_passwd(QString name, QString origin,
                                                QString n) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }
  QSqlQuery query(db);
  QString tmp = "SELECT passwd FROM id_card WHERE online_name='%1'";
  if (!query.exec(tmp.arg(name))) {
    return {false, query.lastError().text()};
  }
  query.next();
  if (query.size() == 0) {
    return {false, "you haven't open the online bank"};
  }
  if (origin.compare(query.value(0).toString()) != 0) {
    return {false, "Origin passwd Wrong"};
  }
  tmp = "UPDATE id_card SET passwd = '%1' WHERE online_name='%2'";
  if (!query.exec(tmp.arg(n).arg(name))) {
    return {false, query.lastError().text()};
  }
  return {true, ""};
}

bool online_ctrl::set_idcard(QString id) { this->idcard = id; }

QString online_ctrl::get_idcard() { return idcard; }

QPair<bool, QString> sys_ctrl::change_passwd(QString name, QString origin,
                                             QString n) {
  auto db = DataBaseUtils::getInstance();
  QString tmp = "SELECT passwd FROM sys_acc_tb WHERE id='%1";
  if (!db.open()) {
    return {false, "Can't open DB"};
  }
  QSqlQuery query(db);
  if (!query.exec(tmp.arg(name))) {
    return {false, query.lastError().text()};
  }
  query.next();
  QString spasswd = query.value(0).toString();
  if (spasswd != origin) {
    return {false, "Origin Passwd Wrong"};
  }
  tmp = "UPDATE sys_acc_tb SET passwd = '%1' WHERE id='%2'";
  if (!query.exec(tmp.arg(n).arg(name))) {
    return {false, query.lastError().text()};
  }
  return {true, ""};
}

QPair<bool, QString> sys_ctrl::use_register(int type, QString passwd,
                                            bool sys) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }
  QSqlQuery query(db);
  QString tmp = "SELECT id as iid FROM sys_acc_tb ";
  if (!query.exec(tmp)) {
    return {false, query.lastError().text()};
  }
  QVector<int> idlist;
  while (query.next()) {
      idlist.append(query.value(0).toInt()%10000);
  }
  auto maxtmp=*std::max_element(idlist.begin(),idlist.end());
  auto t = maxtmp % 10000 + 10001;
  auto id = QString::number(type) + QString::number(t).right(4);
  tmp = "INSERT INTO sys_acc_tb VALUES('%1','%2','%3')";
  if (!query.exec(tmp.arg(id).arg(passwd).arg(sys))) {
    return {false, query.lastError().text()};
  }
  return {true, id};
}

QPair<bool, QString> sys_ctrl::user_delete(QString id) {
  if (id.isEmpty()) {
    return {false, "id Empty"};
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }
  QString tmp = "DELETE FROM sys_acc_tb WHERE id='%1'";
  QSqlQuery query(db);
  if (!query.exec(tmp.arg(id))) {
    return {false, query.lastError().text()};
  } else {
    return {true, "Delete Success"};
  }
}

bool sys_ctrl::set_idcard(QString id) {
  this->idcard = id;
  return true;
}

QString sys_ctrl::get_idcard() { return idcard; }

credit_crtl::credit_crtl(QString id) { id_card = id; }

QPair<bool, QString> credit_crtl::pay(QString credit_id, float value,
                                      QString reason, QString type) {
  if (credit_id.isEmpty()) {
    return {false, QObject::tr("Please Input CreditCard ID")};
  }
  if (value <= 0) {
    return {false, QObject::tr("pay Count ERROR:") + QString::number(value)};
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, QObject::tr("DB Open Failed:") + db.lastError().text()};
  }

  QSqlQuery query(db);
  if (!checkifexists(credit_id)) {
    return {false, "Can't find the Credit Card"};
  }

  // Check if credit gt value
  if (!checkifenough(value, credit_id)) {
    return {false, "You don't have enough credit"};
  }
  // UPDATE credit_card
  QString tmp = "UPDATE credit_card SET "
                "interest_free_money=interest_free_money-'%1',used=used+'%2 WHERE "
                "id='%3' ";
  if (!query.exec(tmp.arg(value).arg(value).arg(credit_id))) {
    return {false, query.lastError().text()};
  }
  // UPDATE credit_consume
  tmp = "UPDATE credit_consume SET total=total+'%1' WHERE id='%2'";
  if (!query.exec(tmp.arg(value).arg(credit_id))) {
    return {false, query.lastError().text()};
  }
  // UPDATE consume_log
  one_card_account::log(reason, value, credit_id, id_card, type);
  //    tmp="INSERT INTO  consume_log(figure,reason,date,cid,cardid) VALUES
  //    ('%1','%2','%3','%4','%5')";
  //    if(!query.exec(tmp.arg(value).arg(reason).arg(QDate::currentDate().toString()).arg(credit_id).ar(id_card))){
  //        return {false,query.lastError().text()};
  //    }
}

QPair<bool, QString> credit_crtl::enchashmen(QString credit_id, QString passwd,
                                             float value) {
  if (!checkifexists(credit_id)) {
    return {false, "Can't find your Credit Card"};
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    return {false, db.lastError().text()};
  }
  QSqlQuery query(db);
  QString tmp =
      "SELECT credit_enchashment_fee,credit_lixi FROM lilv WHERE id=1 ";
  if (!query.exec(tmp)) {
    return {false, query.lastError().text() + " Can't read lixi"};
  }
  float fee = (query.value(0).toFloat() + 1)/100;
  float lixi = (query.value(1).toFloat() + 1)/100;
  // Check if > 0.7
  tmp = "SELECT credit FROM credit_card WHERE id='%1'";
  if (!query.exec(tmp.arg(credit_id))) {
    return {false, query.lastError().text()};
  }
  query.next();
  auto max = query.value(0).toFloat();
  if (value > max * 0.7) {
    return {false,
            "Sorry You can only enchashment " + QString::number(max * 0.7)};
  }
  // Check if enough
  if (!checkifenough(value, credit_id)) {
    return {false, "You don't have enough money"};
  }
  // UPDATE enchashment_tb
  tmp = "INSERT INTO enchashment_tb "
        "(figure,server_charge,enchashment_interest,credit_id) VALUES ('%1','%2',0,'%3')";
  if (!query.exec(tmp.arg(value).arg(value * fee).arg(credit_id))) {
    return {false, query.lastError().text()};
  }
  // UPDATE consume_log
  one_card_account::log("ENCHASHMENT", value, credit_id, id_card,
                        "ENCHASHMENT");
  //    tmp="INSERT INTO consume_log (figure ,reason,date,cid) VALUES
  //    ('%1','%2','%3','%4')";
  //    if(!query.exec(tmp.arg(value).arg("ENCHASHMENT").arg(QDate::currentDate().toString()).ar(credit_id)));{
  //        return {false,query.lastError().text()};
  //    }
  // UPDATE credit_card
  tmp = "UPDATE credit_card SET "
        "interest_free_money=interest_free_money-'%1',used=used+'%1' ";
  if (!query.exec(tmp.arg(value * fee))) {
    return {false, query.lastError().text()};
  }
  return {true, "success"};
  // TODO CREATE EVENT
}

float credit_crtl::GetTotalLimit(QString credit_id) {
  if (!checkifexists(credit_id)) {
    return -1;
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << "Open DB ERROR";
  }
  QSqlQuery query(db);
  QString tmp = "SELECT credit FROM credit_card WHERE id='%1'";
  if (!query.exec(tmp.arg(credit_id))) {
    return -1;
  }
  query.next();
  auto curr_credit = query.value(0).toFloat();
  return curr_credit;
}

float credit_crtl::GetnowLimit(QString credit_id) {
  if (!checkifexists(credit_id)) {
    return -1;
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << "Open DB ERROR";
  }
  QSqlQuery query(db);
  QString tmp = "SELECT interest_free_money FROM credit_card WHERE id='%1'";
  if (!query.exec(tmp.arg(credit_id))) {
    return -1;
  }
  query.next();
  return query.value(0).toFloat();
}

float credit_crtl::Getminvalue(QString credit_id) {
  if (!checkifexists(credit_id)) {
    return -1;
  }
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << "Open DB ERROR";
  }
  QSqlQuery query(db);
  QString tmp =
      "SELECT used FROM credit_card WHERE id='%1'"; // weigaichengxianyoudezuidihuankuan
  if (!query.exec(tmp.arg(credit_id))) {
    return -1;
  }
  query.next();
  auto curr_credit = query.value(0).toFloat()*0.1;
  tmp="SELECT server_charge,enchashment_interest FROM enchashment_tb WHERE credit_id='%1'";
  if(!query.exec(tmp.arg(credit_id))){
      return -1;
  }
  while (query.next()) {
  curr_credit+=query.value(0).toFloat()+query.value(1).toFloat();
  }
  return curr_credit;
}

QStringList credit_crtl::getCreditCards(QString idcard) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << db.lastError();
    return {};
  }
  QSqlQuery query(db);
  QString tmp = "SELECT id FROM credit_card WHERE cid='%1'";
  if (!query.exec(tmp.arg(idcard))) {
    qDebug() << DEBUG_PRE << query.lastError();
    return {};
  }
  QStringList list;
  while (query.next()) {
    list << query.value(0).toString();
  }
  return list;
}

bool credit_crtl::pay_own(QString credi_id, float value) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << db.lastError();
    return false;
  }
  QSqlQuery query(db);
  QString tmp = "UPDATE credit_card SET "
                "interest_free_money=interest_free_money+ "
                "'%1',paid=paid-'%1',used=used-'%1' WHERE id='%2'";
  if (!query.exec(tmp.arg(value).arg(credi_id))) {
    qDebug() << DEBUG_PRE << query.lastError();
    return false;
  }
  return true;
}

bool credit_crtl::checkifexists(QString id) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << "Open DB ERROR";
  }
  QSqlQuery query(db);
  QString tmp = "SELECT COUNT(*) FROM credit_card WHERE id='%1' ";
  if (!query.exec(tmp.arg(id))) {
    qDebug() << DEBUG_PRE << query.lastError();
    return false;
  }
  return query.size() != 0;
}

bool credit_crtl::checkifenough(float value, QString credit_id) {
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << "Open DB failed" << db.lastError();
    return false;
  }
  QSqlQuery query(db);
  QString tmp = "SELECT interest_free_money FROM credit_card WHERE id='%1'";
  if (!query.exec(tmp.arg(credit_id))) {
    return false;
  }
  query.next();
  auto curr_credit = query.value(0).toFloat();
  return value - curr_credit <= 0;
}
