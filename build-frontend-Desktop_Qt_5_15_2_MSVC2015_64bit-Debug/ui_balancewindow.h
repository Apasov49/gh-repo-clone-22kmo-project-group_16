/********************************************************************************
** Form generated from reading UI file 'balancewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEWINDOW_H
#define UI_BALANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BalanceWindow
{
public:
    QPushButton *Btn_Exit;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_client_name;
    QLabel *label_balance;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *label_transactions;

    void setupUi(QDialog *BalanceWindow)
    {
        if (BalanceWindow->objectName().isEmpty())
            BalanceWindow->setObjectName(QString::fromUtf8("BalanceWindow"));
        BalanceWindow->resize(838, 523);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        BalanceWindow->setFont(font);
        Btn_Exit = new QPushButton(BalanceWindow);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(650, 440, 151, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(15);
        font1.setBold(true);
        Btn_Exit->setFont(font1);
        Btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Exit->setStyleSheet(QString::fromUtf8("background: brown;\n"
"color: black;"));
        frame = new QFrame(BalanceWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(400, 30, 381, 121));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        font2.setPointSize(18);
        font2.setBold(true);
        label->setFont(font2);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 151, 61));
        label_2->setFont(font2);
        label_client_name = new QLabel(frame);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(130, 10, 231, 41));
        label_client_name->setFont(font2);
        label_balance = new QLabel(frame);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(110, 60, 231, 41));
        label_balance->setFont(font2);
        frame_2 = new QFrame(BalanceWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 30, 361, 461));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 321, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Courier New"));
        font3.setPointSize(16);
        font3.setBold(true);
        label_3->setFont(font3);
        label_transactions = new QLabel(frame_2);
        label_transactions->setObjectName(QString::fromUtf8("label_transactions"));
        label_transactions->setGeometry(QRect(0, 60, 361, 401));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Courier New"));
        font4.setPointSize(12);
        font4.setBold(true);
        label_transactions->setFont(font4);
        label_transactions->setCursor(QCursor(Qt::IBeamCursor));
        label_transactions->setStyleSheet(QString::fromUtf8("background:gray;\n"
"color: black;"));

        retranslateUi(BalanceWindow);

        QMetaObject::connectSlotsByName(BalanceWindow);
    } // setupUi

    void retranslateUi(QDialog *BalanceWindow)
    {
        BalanceWindow->setWindowTitle(QCoreApplication::translate("BalanceWindow", "Balance", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("BalanceWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("BalanceWindow", "Client:", nullptr));
        label_2->setText(QCoreApplication::translate("BalanceWindow", "Balance:", nullptr));
        label_client_name->setText(QString());
        label_balance->setText(QString());
        label_3->setText(QCoreApplication::translate("BalanceWindow", "Transaction history: ", nullptr));
        label_transactions->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BalanceWindow: public Ui_BalanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEWINDOW_H
