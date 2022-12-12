/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QPushButton *Btn_Exit;
    QFrame *frame;
    QPushButton *Btn_Transfer;
    QPushButton *Btn_Trans;
    QPushButton *Btn_Deposit;
    QPushButton *Btn_Balance;
    QPushButton *Btn_Withdraw;
    QLabel *label_id_card;

    void setupUi(QDialog *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(504, 401);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        ClientWindow->setFont(font);
        Btn_Exit = new QPushButton(ClientWindow);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(330, 340, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(15);
        font1.setBold(true);
        Btn_Exit->setFont(font1);
        Btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Exit->setStyleSheet(QString::fromUtf8("background: brown;\n"
"color: black;"));
        frame = new QFrame(ClientWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 50, 441, 231));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Btn_Transfer = new QPushButton(frame);
        Btn_Transfer->setObjectName(QString::fromUtf8("Btn_Transfer"));
        Btn_Transfer->setGeometry(QRect(20, 110, 151, 31));
        Btn_Transfer->setFont(font);
        Btn_Trans = new QPushButton(frame);
        Btn_Trans->setObjectName(QString::fromUtf8("Btn_Trans"));
        Btn_Trans->setGeometry(QRect(150, 170, 151, 29));
        Btn_Trans->setFont(font);
        Btn_Deposit = new QPushButton(frame);
        Btn_Deposit->setObjectName(QString::fromUtf8("Btn_Deposit"));
        Btn_Deposit->setGeometry(QRect(20, 60, 151, 31));
        Btn_Deposit->setFont(font);
        Btn_Balance = new QPushButton(frame);
        Btn_Balance->setObjectName(QString::fromUtf8("Btn_Balance"));
        Btn_Balance->setGeometry(QRect(270, 110, 151, 31));
        Btn_Balance->setFont(font);
        Btn_Withdraw = new QPushButton(frame);
        Btn_Withdraw->setObjectName(QString::fromUtf8("Btn_Withdraw"));
        Btn_Withdraw->setGeometry(QRect(270, 60, 151, 31));
        Btn_Withdraw->setFont(font);
        label_id_card = new QLabel(frame);
        label_id_card->setObjectName(QString::fromUtf8("label_id_card"));
        label_id_card->setGeometry(QRect(0, 10, 431, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(20);
        font2.setBold(true);
        label_id_card->setFont(font2);

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QDialog *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "Dialog", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("ClientWindow", "Exit", nullptr));
        Btn_Transfer->setText(QCoreApplication::translate("ClientWindow", "Transfer", nullptr));
        Btn_Trans->setText(QCoreApplication::translate("ClientWindow", "Transactions", nullptr));
        Btn_Deposit->setText(QCoreApplication::translate("ClientWindow", "Deposit", nullptr));
        Btn_Balance->setText(QCoreApplication::translate("ClientWindow", "Balance", nullptr));
        Btn_Withdraw->setText(QCoreApplication::translate("ClientWindow", "Withdraw", nullptr));
        label_id_card->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
