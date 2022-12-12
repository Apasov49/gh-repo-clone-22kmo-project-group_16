#include "balancewindow.h"
#include "ui_balancewindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>

BalanceWindow::BalanceWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Balance");

    S_=0;
    BalanceTimer = new QTimer;
    connect(BalanceTimer,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    BalanceTimer->start(1024);

    WebToken=wt;
    CardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/clientfivetransaction/"+CardId;
    QNetworkRequest request((site_url));
    //Start webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End wbetoken
    BalanceManager = new QNetworkAccessManager(this);
    connect(BalanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(BalanceSlot(QNetworkReply*)));
    Reply = BalanceManager->get(request);
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::on_Btn_Exit_clicked()
{
    BalanceTimer->stop();
    close();
}

void BalanceWindow::BalanceSlot(QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonArray json_array = json_doc.array();
    QString transaction;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       transaction+="Transaction Type:"+json_obj["Transaction Type"].toString()+", Date:"+json_obj["Date"].toString()+", Amount:"+QString::number(json_obj["Amount"].toInt())+"\n";
    }

    ui->label_transactions->setText(transaction);

    Reply->deleteLater();
    BalanceManager->deleteLater();

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+CardId;
    QNetworkRequest request((site_url));
    //Start Webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken
    ClientManager = new QNetworkAccessManager(this);
    connect(ClientManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(ClientSlot(QNetworkReply*)));
    Reply = ClientManager->get(request);

}

void BalanceWindow::ClientSlot(QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();


    QString ClientName=json_obj["client_name"].toString();
    QString Balance=QString::number(json_obj["balance"].toDouble());

    ui->label_client_name->setText(ClientName);
    ui->label_balance->setText(Balance);

    Reply->deleteLater();
    ClientManager->deleteLater();

}

void BalanceWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10)
    {
        BalanceTimer->stop();
         close();
    }

}

