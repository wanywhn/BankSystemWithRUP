#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>


#include "gen/App_Layer.h"
#include "gen/BankSystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init_ui();
    QStackedWidget *stacked_widget;

    one_card_control card_ctrl;
    sys_ctrl sctrl;
    online_ctrl octrl;



    bool logined;


};

#endif // MAINWINDOW_H
