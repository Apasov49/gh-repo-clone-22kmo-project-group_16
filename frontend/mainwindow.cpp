#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Group_16 ATM");
    PinCount=0;
    S_=0;
    EnterCount=0;
    LockCheck=false;
    Timer_ = new QTimer;
    connect(Timer_,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    ui->label_info->setText("Please, enter you card number and press 'OK'");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_Ok_clicked()
{
    EnterCount++;
    if(EnterCount == 1) {
        id_card=ui->lineEdit->text();
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        ui->label_info->setText("Please, enter PIN code and press 'OK'.");
        EnterCount++;
        LockCheck=false;
    }
    else {
        Pin_=ui->lineEdit->text();
        QJsonObject jsonObj;
        jsonObj.insert("id_card", id_card);
        jsonObj.insert("pin", Pin_);

        ui->lineEdit->clear();

        QString site_url=MyURL::getBaseUrl()+"/login";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        LogInManager = new QNetworkAccessManager(this);
        connect(LogInManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(LogInSlot(QNetworkReply*)));

        Reply = LogInManager->post(request, QJsonDocument(jsonObj).toJson());
            }
}

void MainWindow::LogInSlot(QNetworkReply *Reply)
{
    ResponseData=Reply->readAll();
    qDebug()<<ResponseData;

    int test=QString::compare(ResponseData, "false");
    qDebug()<<test;

    if(ResponseData.length()==0){
        ui->lineEdit->clear();
        ui->label_info->setText("Error: service does not response!");
        Timer_->start(1024);
    }
    else{

        if(QString::compare(ResponseData,"-4078")==0){
        ui->lineEdit->clear();
        ui->label_info->setText("Error: can not connect to the database!");
        Timer_->start(1024);
    }

    else{

        if(test==0){
            ui->lineEdit->clear();
            ui->label_info->setText("Card Number or/and Pin Code don't match!\n Notice: Card will be locked if the pin code was entered wrong 5 times!");
            PinCount++;
            Timer_->start(1024);
        }

        else {
            ui->lineEdit->clear();
            EnterCount=0;
            ui->label_info->setText("Please, enter you card number and press 'OK'.");
            ObjectClientWindow = new ClientWindow(id_card, this);
            ObjectClientWindow->SetWebToken("Bearer "+ResponseData);
            ObjectClientWindow->setModal(true);
            int a=ObjectClientWindow->exec();
            if(a==0){
                PinCount=0;
                S_=0;
                id_card="";
                Pin_="";
                ObjectClientWindow->SetWebToken("");

            }
        }
    }
    }

    Reply->deleteLater();
    LogInManager->deleteLater();


}

void MainWindow::LockingSlot(QNetworkReply *Reply)
{
    ResponseData=Reply->readAll();
    qDebug()<<ResponseData;
    int test=QString::compare(ResponseData, "false");
    qDebug()<<test;
}

void MainWindow::on_Btn_Clear_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_Btn_Exit_clicked()
{
    QApplication::closeAllWindows();
    qApp->quit();
}


void MainWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==10 && PinCount<5 && LockCheck==false)
    {
        Timer_->stop();
        S_=0;
        ui->lineEdit->clear();

        ui->label_info->setText("Please, enter you PIN code and press OK.");
        EnterCount=1;
    }

    else if(S_==10 && PinCount==5 && LockCheck==false){
        Timer_->stop();
        S_=0;
        ui->lineEdit->clear();
        ui->label_info->setText("PIN code eas enter 5 times wrong, the card is blocked\n Please, contact you costumer service");
        QJsonObject jsonObj;
        ui->lineEdit->clear();

        QString site_url_lock=MyURL::getBaseUrl()+"/cardlocked/"+id_card;
        QNetworkRequest request((site_url_lock));

        LockManager = new QNetworkAccessManager(this);
        connect(LockManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(LockingSlot(QNetworkReply*)));

        Reply = LockManager->put(request, QJsonDocument().toJson());
        PinCount=0;
        LockCheck=true;
        Timer_->start(1024);
    }
    else if(S_==10 && PinCount<5 && LockCheck==true){
        Timer_->stop();
        PinCount=0;
         S_=0;
         id_card="";
         Pin_="";
         EnterCount=0;
         ui->label_info->setText("Please, enter you card number and press OK.");

    }
}
