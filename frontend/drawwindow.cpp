#include "drawwindow.h"
#include "ui_drawwindow.h"
#include <myurl.h>
#include <QDebug>
#include <QTimer>
#include <windows.h>

DrawWindow::DrawWindow(QByteArray wt,QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Withdraw");

    S_=0;
    DrawTimer = new QTimer;
    connect(DrawTimer,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    DrawTimer->start(1024);

    WebToken=wt;
    CardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+CardId;
    QNetworkRequest request((site_url));
    //Start Webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken
    DrawManager = new QNetworkAccessManager(this);
    connect(DrawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(DrawSlot(QNetworkReply*)));
    Reply = DrawManager->get(request);

}

DrawWindow::~DrawWindow()
{
    delete ui;
}

void DrawWindow::DrawSlot(QNetworkReply *Reply)
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
    DrawManager->deleteLater();
}

void DrawWindow::CheckMoney(double bal, double am)
{
    if(bal<am){
        ui->label_info->setText("There is not enough money in the account, select a new amount or close the window.");
    }
    else{
        bal=bal-am;
        Balance=QString::number(bal);
        ui->label_info->setText("Please, confirm the withdoraw by pressing OK!\n Balance after the withdraw "+Balance+" euros.");
    }
}

void DrawWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10)
    {
        DrawTimer->stop();
         close();
    }

}

void DrawWindow::on_Btn_20e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,20);
    Amount="-20";
    DrawTimer->start(1024);
}


void DrawWindow::on_Btn_40e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,40);
    Amount="-40";
    DrawTimer->start(1024);
}


void DrawWindow::on_Btn_60e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,60);
    Amount="-60";
    DrawTimer->start(1024);
}


void DrawWindow::on_Btn_90e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,90);
    Amount="-90";
    DrawTimer->start(1024);
}


void DrawWindow::on_Btn_120e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,120);
    Amount="-120";
    DrawTimer->start(1024);
}


void DrawWindow::on_Btn_140e_clicked()
{
    DrawTimer->stop();
    S_=0;
    CheckMoney(BalanceValue,140);
    Amount="-140";
    DrawTimer->start(1024);
}

void DrawWindow::on_Btn_Ok_clicked()
{
    DrawTimer->stop();
    //Update account table
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
    jsonObjPost.insert("transaction","Withdraw");
    jsonObjPost.insert("amount",Amount);

    QString site_urlPost=MyURL::getBaseUrl()+"/transaction/";
    QNetworkRequest requestPost((site_urlPost));
    requestPost.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //Start Webtoken
    requestPost.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken

    PostManager=new QNetworkAccessManager(this);
    connect(PostManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(PostTransactionSlot(QNetworkReply*)));

    ReplyPost=PostManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());

}

void DrawWindow::on_Btn_Exit_clicked()
{
    DrawTimer->stop();
    close();
}

void DrawWindow::UpdateBalanceSlot(QNetworkReply *Reply)
{
    ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    Reply->deleteLater();
    UpdateManager->deleteLater();
    this->close();
}

void DrawWindow::PostTransactionSlot(QNetworkReply *ReplyPost)
{
    ResponseData=ReplyPost->readAll();
    qDebug()<<ResponseData;
    ReplyPost->deleteLater();
    PostManager->deleteLater();
    this->close();
}





