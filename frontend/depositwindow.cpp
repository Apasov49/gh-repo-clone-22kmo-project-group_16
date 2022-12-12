#include "depositwindow.h"
#include "ui_depositwindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>

DepositWindow::DepositWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Deposit");

    S_=0;
    DepositTimer = new QTimer;
    connect(DepositTimer,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    DepositTimer->start(1024);

    WebToken=wt;
    CardId=id_card;
    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+CardId;
    QNetworkRequest request((site_url));
    //Start Webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken
    DepositManager = new QNetworkAccessManager(this);
    connect(DepositManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(DepositSlot(QNetworkReply*)));
    Reply = DepositManager->get(request);
}

DepositWindow::~DepositWindow()
{
    delete ui;
}

void DepositWindow::DepositSlot(QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();

    ClientId=QString::number(json_obj["id_client"].toInt());
    AccountId=QString::number(json_obj["id_account"].toInt());

    ClientName=json_obj["client_name"].toString();
    Balance=QString::number(json_obj["balance"].toDouble());
    BalanceValue=QString(Balance).toDouble();

    ui->label_client_name->setText(ClientName);
    ui->label_balance->setText(Balance);

    Reply->deleteLater();
    DepositManager->deleteLater();

}

void DepositWindow::UpdateBalanceSlot(QNetworkReply *Reply)
{
    ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    Reply->deleteLater();
    UpdateManager->deleteLater();
    this->close();

}

void DepositWindow::PostTransactionSlot(QNetworkReply *ReplyPost)
{
    ResponseData=ReplyPost->readAll();
    qDebug()<<ResponseData;
    ReplyPost->deleteLater();
    PostManager->deleteLater();
    this->close();
}

void DepositWindow::on_Btn_Ok_clicked()
{
    DepositTimer->stop();
    //Update account table
    AmountValue=QString(Amount).toDouble();
    BalanceValue=BalanceValue+AmountValue;
    Balance=QString::number(BalanceValue);

    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("id_client",ClientId);
    jsonObjUpdate.insert("balance",Balance);

    QString site_url=MyURL::getBaseUrl()+"/account/"+AccountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //Start Webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken

    UpdateManager = new QNetworkAccessManager(this);
    connect(UpdateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(UpdateBalanceSlot(QNetworkReply*)));

    Reply = UpdateManager->put(request, QJsonDocument(jsonObjUpdate).toJson());

    //Add new transaction to transactin table
    QJsonObject jsonObjPost;
    jsonObjPost.insert("id_account",AccountId);
    jsonObjPost.insert("id_card",CardId);
    jsonObjPost.insert("transaction_date",QDate::currentDate().toString(Qt::ISODate));
    jsonObjPost.insert("transaction","Deposit");
    jsonObjPost.insert("amount",Amount);
    QString site_urlPost=MyURL::getBaseUrl()+"/transaction/";
    QNetworkRequest requestPost((site_urlPost));
    requestPost.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //Start WEBTOKEN
    requestPost.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End WEBTOKEN

    PostManager=new QNetworkAccessManager(this);
    connect(PostManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(PostTransactionSlot(QNetworkReply*)));

    ReplyPost=PostManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());
}

void DepositWindow::on_Btn_20e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="20";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_40e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="40";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_60e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="60";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_90e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="90";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_120e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="120";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_140e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="140";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_160e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="160";
    DepositTimer->start(1024);
}


void DepositWindow::on_Btn_180e_clicked()
{
    DepositTimer->stop();
    S_=0;
    ui->label_info->setText("To confirm the deposit, press OK or Cancel press close!");
    Amount="180";
    DepositTimer->start(1024);
}

void DepositWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10)
    {
        DepositTimer->stop();
         close();
    }

}



void DepositWindow::on_Btn_Exit_clicked()
{
    DepositTimer->stop();
    close();
}


