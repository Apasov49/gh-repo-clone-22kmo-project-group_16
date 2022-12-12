/********************************************************************************
** Form generated from reading UI file 'transferwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERWINDOW_H
#define UI_TRANSFERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TransferWindow
{
public:
    QPushButton *Btn_Exit;
    QFrame *frame;
    QLabel *label_info;
    QPushButton *Btn_Ok;
    QPushButton *Btn_clear;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TransferWindow)
    {
        if (TransferWindow->objectName().isEmpty())
            TransferWindow->setObjectName(QString::fromUtf8("TransferWindow"));
        TransferWindow->resize(696, 334);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        TransferWindow->setFont(font);
        Btn_Exit = new QPushButton(TransferWindow);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(530, 270, 141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(12);
        font1.setBold(true);
        Btn_Exit->setFont(font1);
        Btn_Exit->setStyleSheet(QString::fromUtf8("background:brown;\n"
"color: black"));
        frame = new QFrame(TransferWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(50, 40, 591, 181));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_info = new QLabel(frame);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(0, 0, 591, 151));
        label_info->setFont(font1);
        label_info->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: black"));
        label_info->setFrameShape(QFrame::NoFrame);
        label_info->setFrameShadow(QFrame::Plain);
        label_info->setAlignment(Qt::AlignCenter);
        Btn_Ok = new QPushButton(frame);
        Btn_Ok->setObjectName(QString::fromUtf8("Btn_Ok"));
        Btn_Ok->setGeometry(QRect(470, 150, 121, 31));
        Btn_Ok->setFont(font1);
        Btn_Ok->setStyleSheet(QString::fromUtf8("background: darkgreen;\n"
"color: black"));
        Btn_clear = new QPushButton(frame);
        Btn_clear->setObjectName(QString::fromUtf8("Btn_clear"));
        Btn_clear->setGeometry(QRect(0, 150, 121, 31));
        Btn_clear->setFont(font1);
        Btn_clear->setStyleSheet(QString::fromUtf8("background: darkgreen;\n"
"color: black"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 150, 351, 31));
        lineEdit->setFont(font);

        retranslateUi(TransferWindow);

        QMetaObject::connectSlotsByName(TransferWindow);
    } // setupUi

    void retranslateUi(QDialog *TransferWindow)
    {
        TransferWindow->setWindowTitle(QCoreApplication::translate("TransferWindow", "Dialog", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("TransferWindow", "Exit", nullptr));
        label_info->setText(QString());
        Btn_Ok->setText(QCoreApplication::translate("TransferWindow", "OK", nullptr));
        Btn_clear->setText(QCoreApplication::translate("TransferWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferWindow: public Ui_TransferWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERWINDOW_H
