#include "clientwindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "transferwindow.h"
#include "ui_clientwindow.h"
#include <myurl.h>
#include <QDebug>



ClientWindow::ClientWindow(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:/icon/arc.jpg)");
    this->setWindowTitle("Main");
    S_=0;
    QTimer_ = new QTimer;
    ui->label_id_card->setText(id_card);
    CardId=id_card;

    connect(QTimer_,SIGNAL(timeout()),this,SLOT(HandleTimeOut()));
    QTimer_->start(1024);

}

ClientWindow::~ClientWindow()
{
    delete ui;

}

void ClientWindow::SetWebToken(const QByteArray &newWebToken)
{
    WebToken = newWebToken;
}

void ClientWindow::on_Btn_Balance_clicked()
{

    QTimer_->stop();
    ObjectBalanceWindow = new BalanceWindow(WebToken,CardId, this);
    ObjectBalanceWindow->setModal(true);
    int a=ObjectBalanceWindow->exec();
    if(a==0){
        S_=0;
        QTimer_->start(1024);
    }
}

void ClientWindow::on_Btn_Trans_clicked()
{
    QTimer_->stop();
    ObjectTransactionWindow = new TransactionWindow (WebToken,CardId, this);
    ObjectTransactionWindow->setModal(true);
    int a=ObjectTransactionWindow->exec();
    if(a==0){
        S_=0;
        QTimer_->start(1024);
    }


}


void ClientWindow::on_Btn_Withdraw_clicked()
{

    QTimer_->stop();
    ObjectDrawWindow = new DrawWindow(WebToken,CardId, this);
    ObjectDrawWindow->setModal(true);
    int a=ObjectDrawWindow->exec();
    if(a==0){
        S_=0;
        QTimer_->start(1024);
    }
}


void ClientWindow::on_Btn_Deposit_clicked()
{
    QTimer_->stop();
    ObjectDepositWindow = new DepositWindow(WebToken,CardId, this);
    ObjectDepositWindow->setModal(true);
    int a=ObjectDepositWindow->exec();
    if(a==0){
        S_=0;
        QTimer_->start(1024);
    }
}

void ClientWindow::on_Btn_Exit_clicked()
{
    QTimer_->stop();
    close();
}

void ClientWindow::HandleTimeOut()
{
    S_++;
    qDebug()<<S_;
    if (S_==30)
    {
        QTimer_->stop();
        close();

    }

}

void ClientWindow::on_Btn_Transfer_clicked()
{
    QTimer_->stop();
    ObjectTransferWindow = new TransferWindow(WebToken,CardId, this);
    ObjectTransferWindow->setModal(true);
    int a=ObjectTransferWindow->exec();
    if(a==0){
        S_=0;
        QTimer_->start(1024);
    }
}

