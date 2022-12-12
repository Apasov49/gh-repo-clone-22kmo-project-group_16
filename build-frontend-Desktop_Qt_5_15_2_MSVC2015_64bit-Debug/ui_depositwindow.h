/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QPushButton *Btn_20e;
    QPushButton *Btn_Ok;
    QPushButton *Btn_40e;
    QPushButton *Btn_90e;
    QPushButton *Btn_120e;
    QPushButton *Btn_180e;
    QPushButton *Btn_60e;
    QPushButton *Btn_Exit;
    QPushButton *Btn_140e;
    QPushButton *Btn_160e;
    QFrame *frame;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_client_name;
    QLabel *label_balance;
    QFrame *frame_2;
    QLabel *label_info;
    QLabel *label_3;

    void setupUi(QDialog *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(786, 520);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        DepositWindow->setFont(font);
        Btn_20e = new QPushButton(DepositWindow);
        Btn_20e->setObjectName(QString::fromUtf8("Btn_20e"));
        Btn_20e->setGeometry(QRect(20, 170, 131, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(15);
        font1.setBold(true);
        Btn_20e->setFont(font1);
        Btn_Ok = new QPushButton(DepositWindow);
        Btn_Ok->setObjectName(QString::fromUtf8("Btn_Ok"));
        Btn_Ok->setGeometry(QRect(600, 400, 161, 41));
        Btn_Ok->setFont(font1);
        Btn_Ok->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Ok->setStyleSheet(QString::fromUtf8("background: brown;\n"
"color: black;"));
        Btn_40e = new QPushButton(DepositWindow);
        Btn_40e->setObjectName(QString::fromUtf8("Btn_40e"));
        Btn_40e->setGeometry(QRect(20, 220, 131, 41));
        Btn_40e->setFont(font1);
        Btn_90e = new QPushButton(DepositWindow);
        Btn_90e->setObjectName(QString::fromUtf8("Btn_90e"));
        Btn_90e->setGeometry(QRect(20, 320, 131, 41));
        Btn_90e->setFont(font1);
        Btn_120e = new QPushButton(DepositWindow);
        Btn_120e->setObjectName(QString::fromUtf8("Btn_120e"));
        Btn_120e->setGeometry(QRect(630, 170, 131, 41));
        Btn_120e->setFont(font1);
        Btn_180e = new QPushButton(DepositWindow);
        Btn_180e->setObjectName(QString::fromUtf8("Btn_180e"));
        Btn_180e->setGeometry(QRect(630, 320, 131, 41));
        Btn_180e->setFont(font1);
        Btn_60e = new QPushButton(DepositWindow);
        Btn_60e->setObjectName(QString::fromUtf8("Btn_60e"));
        Btn_60e->setGeometry(QRect(20, 270, 131, 41));
        Btn_60e->setFont(font1);
        Btn_Exit = new QPushButton(DepositWindow);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(600, 460, 161, 41));
        Btn_Exit->setFont(font1);
        Btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Exit->setStyleSheet(QString::fromUtf8("background: brown;\n"
"color: black;"));
        Btn_140e = new QPushButton(DepositWindow);
        Btn_140e->setObjectName(QString::fromUtf8("Btn_140e"));
        Btn_140e->setGeometry(QRect(630, 220, 131, 41));
        Btn_140e->setFont(font1);
        Btn_160e = new QPushButton(DepositWindow);
        Btn_160e->setObjectName(QString::fromUtf8("Btn_160e"));
        Btn_160e->setGeometry(QRect(630, 270, 131, 41));
        Btn_160e->setFont(font1);
        frame = new QFrame(DepositWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(170, 30, 441, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_1 = new QLabel(frame);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 10, 141, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(20);
        font2.setBold(true);
        label_1->setFont(font2);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 161, 61));
        label_2->setFont(font2);
        label_client_name = new QLabel(frame);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(160, 10, 261, 61));
        label_client_name->setFont(font2);
        label_balance = new QLabel(frame);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(170, 60, 251, 61));
        label_balance->setFont(font2);
        frame_2 = new QFrame(DepositWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(170, 170, 441, 191));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_info = new QLabel(frame_2);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 40, 411, 151));
        label_info->setFont(font1);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 421, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Courier New"));
        font3.setPointSize(12);
        font3.setBold(true);
        label_3->setFont(font3);

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QDialog *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Dialog", nullptr));
        Btn_20e->setText(QCoreApplication::translate("DepositWindow", "20 \342\202\254", nullptr));
        Btn_Ok->setText(QCoreApplication::translate("DepositWindow", "OK", nullptr));
        Btn_40e->setText(QCoreApplication::translate("DepositWindow", "40 \342\202\254", nullptr));
        Btn_90e->setText(QCoreApplication::translate("DepositWindow", "90 \342\202\254", nullptr));
        Btn_120e->setText(QCoreApplication::translate("DepositWindow", "120 \342\202\254", nullptr));
        Btn_180e->setText(QCoreApplication::translate("DepositWindow", "180 \342\202\254", nullptr));
        Btn_60e->setText(QCoreApplication::translate("DepositWindow", "60 \342\202\254", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("DepositWindow", "Exit", nullptr));
        Btn_140e->setText(QCoreApplication::translate("DepositWindow", "140 \342\202\254", nullptr));
        Btn_160e->setText(QCoreApplication::translate("DepositWindow", "160 \342\202\254", nullptr));
        label_1->setText(QCoreApplication::translate("DepositWindow", "Client:", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "Balance:", nullptr));
        label_client_name->setText(QString());
        label_balance->setText(QString());
        label_info->setText(QString());
        label_3->setText(QCoreApplication::translate("DepositWindow", "Please, chose amount to deposit!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
