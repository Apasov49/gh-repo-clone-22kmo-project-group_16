#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DepositWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~DepositWindow();

private slots:
    void DepositSlot (QNetworkReply *Reply);
    void UpdateBalanceSlot (QNetworkReply *Reply);
    void PostTransactionSlot (QNetworkReply *Reply);
    void on_Btn_Ok_clicked();
    void on_Btn_Exit_clicked();
    void on_Btn_20e_clicked();
    void on_Btn_40e_clicked();
    void on_Btn_60e_clicked();
    void on_Btn_90e_clicked();
    void on_Btn_120e_clicked();
    void on_Btn_140e_clicked();
    void on_Btn_160e_clicked();
    void on_Btn_180e_clicked();
    void HandleTimeOut();

private:
    Ui::DepositWindow *ui;
    QByteArray WebToken;
    QString CardId;
    QString ClientId;
    QString AccountId;
    QTimer *DepositTimer;
    short S_;
    QNetworkReply *Reply;
    QNetworkReply *ReplyPost;
    QByteArray ResponseData;
    QString ClientName;
    QString Balance;
    QString Amount;
    double AmountValue;
    double BalanceValue;
    QNetworkAccessManager *DepositManager;
    QNetworkAccessManager *UpdateManager;
    QNetworkAccessManager *PostManager;

};

#endif // DEPOSITWINDOW_H
