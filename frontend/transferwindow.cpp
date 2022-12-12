#include "transferwindow.h"
#include "ui_transferwindow.h"

TransferWindow::TransferWindow(QByteArray wt,QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Transfer");

    WebToken=wt;
    CardId=id_card;

    S_=0;
    TransferTimer = new QTimer;
    connect(TransferTimer,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    TransferTimer->start(1024);

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+CardId;
    QNetworkRequest request((site_url));
    //Start Webtoken
    request.setRawHeader(QByteArray("Authorization"),(WebToken));
    //End Webtoken

    GetIdManager = new QNetworkAccessManager(this);
    connect(GetIdManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(GetIdSlot(QNetworkReply*)));
    Reply=GetIdManager->get(request);
    ui->label_info->setText("Please, enter recipient account number and press 'OK'.");
    IdCount=1;

}

TransferWindow::~TransferWindow()
{
    delete ui;
}

void TransferWindow::on_Btn_Ok_clicked()
{
    switch(IdCount) {
    case 1:
        TransferTimer->stop();
        S_=0;
        AccountIdReceiver=ui->lineEdit->text();
        AccountIdReceiverInt=AccountIdReceiver.toInt();
        ui->lineEdit->clear();
        ui->label_info->setText("Please, enter the amount of money \nto be transferred and press OK.");
        IdCount++;
        TransferTimer->start(1024);
        break;

    case 2:
        TransferTimer->stop();
        S_=0;
        Amount=ui->lineEdit->text();
        AmountValue=Amount.toDouble();
        ui->lineEdit->clear();
        ui->label_info->setText("Recipient's account number: "
                                +AccountIdReceiver+"\nAmount to be transferred: "
                                +Amount+"\nPlease, confirm the transfer by pressing OK.");
        IdCount++;
        TransferTimer->start(1024);
        break;

    default:
        TransferTimer->stop();
        S_=0;
        //Get account info from the database
        QJsonObject jsonObjTransfer;
        jsonObjTransfer.insert("id_account1", AccountId);
        jsonObjTransfer.insert("id_account2", AccountIdReceiverInt);
        jsonObjTransfer.insert("amount", AmountValue);

        //Transfer the money
        QString site_url=MyURL::getBaseUrl()+"/accounttransfer/";
        QNetworkRequest requestTransfer((site_url));
        requestTransfer.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //Start Webtoken
        requestTransfer.setRawHeader(QByteArray("Authorization"),(WebToken));
        //End Webtoken

        TransferManager = new QNetworkAccessManager(this);
        connect(TransferManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransferSlot(QNetworkReply*)));
        ReplyTransfer=TransferManager->post(requestTransfer, QJsonDocument(jsonObjTransfer).toJson());
    }
}


void TransferWindow::GetIdSlot(QNetworkReply *Reply)
{
    QByteArray ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();

    AccountId=QString::number(json_obj["id_account"].toInt());
    Reply->deleteLater();
    GetIdManager->deleteLater();
}

void TransferWindow::TransferSlot(QNetworkReply *ReplyTransfer)
{
    ResponseData=ReplyTransfer->readAll();
    qDebug()<<ResponseData;
    QJsonDocument json_doc = QJsonDocument::fromJson(ResponseData);
    QJsonObject json_obj = json_doc.object();

    QString TransferCheck=QString::number(json_obj["affectedRows"].toInt());
    int TransferCheckInt=TransferCheck.toInt();

    if(TransferCheckInt==0) {
        ui->lineEdit->clear();
        ui->label_info->setText("Something went wrong, please check recipient's\n"
                                "info and retry again!\n"
                                "Press 'Back' to go back to previous window \n");
        TransferTimer->start(1024);
    }

    else{
    ui->label_info->clear();
    ui->label_info->setText("Transfer successful.\n"
                            "if you wish to continue\n"
                            "Please, press 'Back' to go back to previous window\n");
    TransferTimer->start(1024);
    }

    ReplyTransfer->deleteLater();
    TransferManager->deleteLater();

}

void TransferWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10)
    {
        TransferTimer->stop();
         close();
    }

}

void TransferWindow::BtnClearClicked()
{
    TransferTimer->stop();
    close();
}

void TransferWindow::on_Btn_Exit_clicked()
{
    TransferTimer->stop();
    QApplication::closeAllWindows();
}




