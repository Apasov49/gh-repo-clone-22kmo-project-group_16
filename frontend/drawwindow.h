#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT


public:
    explicit DrawWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~DrawWindow();
    //const QString &GetWebToken() const;

private slots:
    void DrawSlot (QNetworkReply *Reply);
    void UpdateBalanceSlot (QNetworkReply *Reply);
    void PostTransactionSlot (QNetworkReply *Reply);
    void on_Btn_20e_clicked();
    void on_Btn_40e_clicked();
    void on_Btn_60e_clicked();
    void on_Btn_90e_clicked();
    void on_Btn_120e_clicked();
    void on_Btn_140e_clicked();
    void on_Btn_Ok_clicked();
    void on_Btn_Exit_clicked();
    void CheckMoney(double bal, double am);
    void HandleTimeOut();

private:
    Ui::DrawWindow *ui;
    QByteArray WebToken;
    QString CardId;
    QString ClientId;
    QString AccountId;
    QTimer *DrawTimer;
    short S_;
    QNetworkReply *Reply;
    QNetworkReply *ReplyPost;
    QByteArray ResponseData;
    QString ClientName;
    QString Balance;
    QString Amount;
    double BalanceValue;
    QNetworkAccessManager *DrawManager;
    QNetworkAccessManager *UpdateManager;
    QNetworkAccessManager *PostManager;
};

#endif // DRAWWINDOW_H
