#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);     // SocketClient 객체 생성
    connect(ui->pPBServerConnect, SIGNAL(clicked(bool)), this, SLOT(slotConnectToServer(bool)));            // connect 시 slot 함수 실행
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(slotSocketRecvUpdate(QString)));      // 위와 동일
}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}

void Tab2SocketClient::slotConnectToServer(bool check)
{
    bool bOk;
    if(check){
        pSocketClient->slotConnectToServer(bOk);
        if(bOk){

        }
    }
}
void Tab2SocketClient::slotSocketRecvUpdate(QString strRecvData)
{
    ui->pTERecieveData->append(strRecvData);
}
