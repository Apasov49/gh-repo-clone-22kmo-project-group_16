#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "drawwindow.h"
#include "balancewindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "transferwindow.h"
#include <QTimer>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QString id_card, QWidget *parent = nullptr);
    ~ClientWindow();

    const QString &GetWebToken() const;
    void SetWebToken(const QByteArray &newWebToken);

private slots:
    void on_Btn_Balance_clicked();
    void on_Btn_Trans_clicked();
    void on_Btn_Withdraw_clicked();
    void on_Btn_Deposit_clicked();
    void on_Btn_Exit_clicked();
    void on_Btn_Transfer_clicked();
    void HandleTimeOut();
private:
    Ui::ClientWindow *ui;
    QByteArray WebToken;
    QString CardId;
    DrawWindow *ObjectDrawWindow;
    QByteArray ResponseData;
    BalanceWindow *ObjectBalanceWindow;
    TransactionWindow *ObjectTransactionWindow;
    DepositWindow *ObjectDepositWindow;
    TransferWindow *ObjectTransferWindow;
    QTimer * QTimer_;
    short S_;
};

#endif // CLIENTWINDOW_H
