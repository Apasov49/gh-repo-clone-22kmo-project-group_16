#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <myurl.h>
#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class TransferWindow;
}

class TransferWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransferWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~TransferWindow();

private slots:
    void GetIdSlot(QNetworkReply *Reply);
    void TransferSlot (QNetworkReply *Reply);
    void HandleTimeOut();

    void on_Btn_Ok_clicked();
    void BtnClearClicked();
    void on_Btn_Exit_clicked();


private:
    Ui::TransferWindow *ui;
    QByteArray WebToken;
    QString CardId;
    QString AccountId;
    QString AccountIdReceiver;
    int AccountIdReceiverInt;
    int IdCount;
    QString id_account;
    QNetworkReply *Reply;
    QNetworkReply *ReplyTransfer;
    QByteArray ResponseData;
    QString Amount;
    double AmountValue;
    QNetworkAccessManager *GetIdManager;
    QNetworkAccessManager *TransferManager;
    QTimer *TransferTimer;
    short S_;
};

#endif // TRANSFERWINDOW_H
