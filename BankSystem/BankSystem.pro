#-------------------------------------------------
#
# Project created by QtCreator 2018-06-02T12:30:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(qzxing/QZXing.pri)
TARGET = BankSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
       src/main.cpp \
       src/mainwindow.cpp \
    src/depositwidget.cpp \
    src/databaseutils.cpp \
    src/gen/BankSystem.cpp \
    src/gen/db_utils.cpp \
    src/gen/Presentation_Layer.cpp \
    src/gen/App_Layer.cpp \
    src/openaccount.cpp \
    src/DIalogChangePasswd.cpp \
    src/dialogadddeposit.cpp \
    src/systemwidget.cpp \
    src/dialogsyslogin.cpp \
    src/widgetcreditcard.cpp \
    src/widgetonlinebank.cpp \
    src/dialogtransfer.cpp \
    src/dialogrecord.cpp \
    src/dialogpeople.cpp \
    src/dialoganaly.cpp \
    src/analy/pieview.cpp \
    src/dialogpaycreditcard.cpp

HEADERS += \
       src/mainwindow.h \
    src/depositwidget.h \
    src/databaseutils.h \
    src/gen/BankSystem.h \
    src/gen/db_utils.h \
    src/gen/Presentation_Layer.h \
    src/gen/App_Layer.h \
    src/openaccount.h \
    src/DIalogChangePasswd.h \
    src/dialogadddeposit.h \
    src/systemwidget.h \
    src/dialogsyslogin.h \
    src/widgetcreditcard.h \
    src/widgetonlinebank.h \
    src/common_const.h \
    src/dialogtransfer.h \
    src/dialogrecord.h \
    src/dialogpeople.h \
    src/dialoganaly.h \
    src/analy/pieview.h \
    src/dialogpaycreditcard.h

FORMS += \
        src/mainwindow.ui
