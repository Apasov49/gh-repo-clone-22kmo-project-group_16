#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~TransactionWindow();
    const QString &GetWebToken() const;
private slots:
    void TransSlot(QNetworkReply *Reply);
    void on_Btn_Exit_clicked();
    void TransBalanceSlot (QNetworkReply *Reply);
    void HandleTimeOut();

private:
    Ui::TransactionWindow*ui;
    QNetworkAccessManager *TransManager;
    QNetworkAccessManager *TransBalanceManager;
    QNetworkReply *Reply;
    QByteArray WebToken;
    QByteArray ResponseData;
    int id_card;
    QString ClientName;
    QString Balance;
    QString CardId;
    QTimer *TransactionTimer;
    short S_;

};

#endif // TRANSACTIONWINDOW_H
