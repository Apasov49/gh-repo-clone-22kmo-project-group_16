#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~BalanceWindow();
    const QString &GetWebToken() const;

private slots:
    void on_Btn_Exit_clicked();
    void BalanceSlot (QNetworkReply *Reply);
    void ClientSlot (QNetworkReply *Reply);
    void HandleTimeOut();

private:
    Ui::BalanceWindow *ui;
    QByteArray WebToken;
    QString CardId;
    QNetworkAccessManager *BalanceManager;
    QNetworkAccessManager *ClientManager;
    QNetworkReply *Reply;
    QByteArray ResponseData;
    QString ClientName;
    QString Balance;
    double BalanceValue;
    QString ClientId;
    QTimer *BalanceTimer;
    short S_;
};

#endif // BALANCEWINDOW_H
