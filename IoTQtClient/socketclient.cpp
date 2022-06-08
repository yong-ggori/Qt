#include <QDebug>
#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
    bool ok;
	pQTcpSocket = new QTcpSocket();

	connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
	connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer()));
	connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
	connect(pQTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
//    slotConnectToServer(ok);
}


void SocketClient::slotConnectToServer(bool& ok){                       // 버튼 이용해서 서버 접속 이용하기 위한 함수
    //서버 연결 요청
    QString strHostIp;
//	tcpSocket.connectToHost(QHostAddress::LocalHost, 5000);
    strHostIp = QInputDialog::getText(this,"HostIP","Input Server IP:",QLineEdit::Normal,SERVERIP,&ok);
    if(ok)
    {
        if(strHostIp.isEmpty())
            pQTcpSocket->connectToHost(SERVERIP, SERVERPOT);            // 비어 있으면 serverpot 이용
        else
            pQTcpSocket->connectToHost(strHostIp, SERVERPOT);           // 입력한게 있으면 그것 사용
    }
}
void SocketClient::slotConnectServer()                                  // 서버에 연결 되면 다음 함수 실행
{
    QString Str = "["+LOGID+":"+LOGPW+"]";                              // ID, PW 입력
    QByteArray byteStr = Str.toLocal8Bit();
    pQTcpSocket->write(byteStr);
}

void SocketClient::slotClosedByServer()
{
	pQTcpSocket->close();
}

void SocketClient::slotSocketReadData(){
//    QList<QString> qList;
    QString strRecvData;
    QByteArray qByteArray;

	if (pQTcpSocket->bytesAvailable() > BLOCK_SIZE)
		return;
    qByteArray = pQTcpSocket->read(BLOCK_SIZE);         // Qstring == 2 바이트 유니코드,
    strRecvData = QString::fromUtf8(qByteArray);        // Tcp == 1 바이트, 변환 해준다.
//    qDebug() <<strRecvData;                           // 디버깅 메세지 보고 싶으면 주석 해제
    emit sigSocketRecv(strRecvData);
//    QMessageBox::information(this,"Socket Recv",strRecvData);
}

void SocketClient::slotSocketError()
{
	QString Str = pQTcpSocket->errorString();
    qDebug() << Str;
}


void SocketClient::slotSocketSendData(QString strSendData)
{	
    if(!strSendData.isEmpty()) {
        strSendData = strSendData+"\n";
        QByteArray bCmd = strSendData.toLocal8Bit();
//        qDebug() << bCmd;
        pQTcpSocket->write(bCmd);
    }
}

SocketClient::~SocketClient()
{
    pQTcpSocket->close();
}
