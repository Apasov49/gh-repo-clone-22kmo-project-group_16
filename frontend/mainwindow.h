#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clientwindow.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <myurl.h>
#include <QStyle>
#include <QDesktopWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void LogInSlot (QNetworkReply *Reply);
    void LockingSlot (QNetworkReply *Reply);
    void on_Btn_Ok_clicked();
    void on_Btn_Clear_clicked();
    void on_Btn_Exit_clicked();
    void HandleTimeOut();

private:
    Ui::MainWindow *ui;
    int EnterCount;
    int PinCount;
    bool LockCheck;
    ClientWindow *ObjectClientWindow;
    QNetworkAccessManager *LogInManager;
    QNetworkAccessManager *LockManager;
    QNetworkReply *Reply;
    QByteArray ResponseData;
    QString id_card;
    QString Pin_;
    QTimer * Timer_;
    short S_;
    QString CheckId;

};
#endif // MAINWINDOW_H
