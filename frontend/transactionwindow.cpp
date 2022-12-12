#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>
#include <QStandardItemModel>


TransactionWindow::TransactionWindow(QByteArray wt, QString id_card, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Transactions");

    S_=0;
    TransactionTimer = new QTimer;
    connect(TransactionTimer,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    TransactionTimer->start(1024);

    WebToken=wt;
    CardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/clienttransaction/"+CardId;
    QNetworkRequest request((site_url));
    //Start webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End webtoken
    TransManager = new QNetworkAccessManager(this);
    connect(TransManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransSlot(QNetworkReply*)));
    Reply = TransManager->get(request);
}
TransactionWindow::~TransactionWindow()
{
    delete ui;
    ui=nullptr;
}

void TransactionWindow::TransSlot (QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();
    QJsonArray json_array = json_doc.array();

    QStandardItemModel *model = new QStandardItemModel(0,3);
    int row = 0;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Transaction"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Amount"));

    foreach (const QJsonValue &value, json_array) {
        QJsonObject itemObj = value.toObject();
        QStandardItem *trType = new QStandardItem(itemObj.value("Transaction Type").toString());
        model->setItem(row, 0, trType);
        QStandardItem *trDate = new QStandardItem(itemObj.value("Date").toString());
        model->setItem(row, 1, trDate);
        QStandardItem *trAmount = new QStandardItem(QString::number(itemObj.value("Amount").toInt()));
        model->setItem(row, 2, trAmount);
        row++;
    }

    ui->tableView->setModel(model);

    Reply->deleteLater();
    TransManager->deleteLater();

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+CardId;
    QNetworkRequest request((site_url));
    //Start webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End webtoken
    TransBalanceManager = new QNetworkAccessManager(this);
    connect(TransBalanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransBalanceSlot(QNetworkReply*)));
    Reply = TransBalanceManager->get(request);
}

void TransactionWindow::TransBalanceSlot(QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();

    ClientName=json_obj["client_name"].toString();
    Balance=QString::number(json_obj["balance"].toDouble());

    ui->label_client_name->setText(ClientName);
    ui->label_balance->setText(Balance);

    Reply->deleteLater();
    TransBalanceManager->deleteLater();
}

void TransactionWindow::on_Btn_Exit_clicked()
{
    close();
}
void TransactionWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10)
    {
        TransactionTimer->stop();
         close();
    }

}


