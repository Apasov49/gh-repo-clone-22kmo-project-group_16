/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Btn_Exit;
    QFrame *frame;
    QLabel *label_info;
    QLineEdit *lineEdit;
    QPushButton *Btn_Ok;
    QPushButton *Btn_Clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(658, 359);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        MainWindow->setFont(font);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("0");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Btn_Exit = new QPushButton(centralwidget);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(510, 280, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(12);
        font1.setBold(true);
        Btn_Exit->setFont(font1);
        Btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Exit->setStyleSheet(QString::fromUtf8("background: brown;\n"
"color: black"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(80, 70, 501, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_info = new QLabel(frame);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(0, 0, 501, 111));
        label_info->setFont(font1);
        label_info->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: black"));
        label_info->setFrameShape(QFrame::NoFrame);
        label_info->setFrameShadow(QFrame::Plain);
        label_info->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 110, 261, 31));
        lineEdit->setFont(font);
        Btn_Ok = new QPushButton(frame);
        Btn_Ok->setObjectName(QString::fromUtf8("Btn_Ok"));
        Btn_Ok->setGeometry(QRect(380, 110, 121, 31));
        Btn_Ok->setFont(font1);
        Btn_Ok->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Ok->setAutoFillBackground(false);
        Btn_Ok->setStyleSheet(QString::fromUtf8("background: darkgreen;\n"
"color: black"));
        Btn_Clear = new QPushButton(frame);
        Btn_Clear->setObjectName(QString::fromUtf8("Btn_Clear"));
        Btn_Clear->setGeometry(QRect(0, 110, 121, 31));
        Btn_Clear->setFont(font1);
        Btn_Clear->setCursor(QCursor(Qt::PointingHandCursor));
        Btn_Clear->setStyleSheet(QString::fromUtf8("background: darkgreen;\n"
"color: black"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 658, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Btn_Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_info->setText(QString());
        Btn_Ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        Btn_Clear->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
