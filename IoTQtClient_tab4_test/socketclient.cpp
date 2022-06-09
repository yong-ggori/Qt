#include <QDebug>
#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
//    bool ok;                      // 버튼을 이용해서 서버 접속하기 때문에 필요없는 문항
//    slotConnectToServer(ok);      // 버튼을 이용해서 서버 접속하기 때문에 필요없는 문항
    pQTcpSocket = new QTcpSocket(); // Qt lib 에서 제공하는 클래스, 헤더 파일에서 선언

	connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
	connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer()));
	connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
	connect(pQTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
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
    QByteArray byteStr = Str.toLocal8Bit();                             // byte로 바꿔서 문자 송신
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

    if (pQTcpSocket->bytesAvailable() > BLOCK_SIZE)     // 수신 할 수 있는 데이터 사이즈인지 확인
		return;
    qByteArray = pQTcpSocket->read(BLOCK_SIZE);         // Qstring == 2 바이트 유니코드, Tcp == 1 바이트
    strRecvData = QString::fromUtf8(qByteArray);        // 수신 데이터 유니코드로 변환 해준다.
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
        strSendData = strSendData+"\n";                 // 하나의 명령어가 종료 되었다고 명시 되게 개행문자 꼭 추가 해 주어야함
        QByteArray bCmd = strSendData.toLocal8Bit();
//        qDebug() << bCmd;
        pQTcpSocket->write(bCmd);
    }
}

SocketClient::~SocketClient()
{
    pQTcpSocket->close();
}
