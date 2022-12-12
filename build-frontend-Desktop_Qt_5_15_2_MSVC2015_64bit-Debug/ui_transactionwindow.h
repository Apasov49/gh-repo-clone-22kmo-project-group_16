/********************************************************************************
** Form generated from reading UI file 'transactionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONWINDOW_H
#define UI_TRANSACTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TransactionWindow
{
public:
    QPushButton *Btn_Exit;
    QTableView *tableView;
    QLabel *label_3;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_balance;
    QLabel *label_client_name;

    void setupUi(QDialog *TransactionWindow)
    {
        if (TransactionWindow->objectName().isEmpty())
            TransactionWindow->setObjectName(QString::fromUtf8("TransactionWindow"));
        TransactionWindow->resize(800, 503);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        TransactionWindow->setFont(font);
        Btn_Exit = new QPushButton(TransactionWindow);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(610, 440, 141, 41));
        Btn_Exit->setFont(font);
        Btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Exit->setStyleSheet(QString::fromUtf8("background: brown; color: Black;"));
        tableView = new QTableView(TransactionWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 381, 421));
        tableView->setFont(font);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        label_3 = new QLabel(TransactionWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 321, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(18);
        font1.setBold(true);
        label_3->setFont(font1);
        frame = new QFrame(TransactionWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(420, 60, 371, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 131, 51));
        label->setFont(font1);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 141, 51));
        label_2->setFont(font1);
        label_balance = new QLabel(frame);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(170, 50, 201, 51));
        label_balance->setFont(font1);
        label_client_name = new QLabel(frame);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(160, 0, 201, 51));
        label_client_name->setFont(font1);

        retranslateUi(TransactionWindow);

        QMetaObject::connectSlotsByName(TransactionWindow);
    } // setupUi

    void retranslateUi(QDialog *TransactionWindow)
    {
        TransactionWindow->setWindowTitle(QCoreApplication::translate("TransactionWindow", "Dialog", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("TransactionWindow", "Exit", nullptr));
        label_3->setText(QCoreApplication::translate("TransactionWindow", "Transactions:", nullptr));
        label->setText(QCoreApplication::translate("TransactionWindow", "Client:", nullptr));
        label_2->setText(QCoreApplication::translate("TransactionWindow", "Balance:", nullptr));
        label_balance->setText(QString());
        label_client_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransactionWindow: public Ui_TransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONWINDOW_H
