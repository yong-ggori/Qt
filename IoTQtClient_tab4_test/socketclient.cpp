#include <QDebug>
#include "socketclient.h"
#define Kor(str)  QString::fromLocal8Bit(str)

SocketClient::SocketClient(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
//    bool ok;                      // ��ư�� �̿��ؼ� ���� �����ϱ� ������ �ʿ���� ����
//    slotConnectToServer(ok);      // ��ư�� �̿��ؼ� ���� �����ϱ� ������ �ʿ���� ����
    pQTcpSocket = new QTcpSocket(); // Qt lib ���� �����ϴ� Ŭ����, ��� ���Ͽ��� ����

	connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(slotConnectServer()));
	connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(slotClosedByServer()));
	connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadData()));
	connect(pQTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError()));
}


void SocketClient::slotConnectToServer(bool& ok){                       // ��ư �̿��ؼ� ���� ���� �̿��ϱ� ���� �Լ�
    //���� ���� ��û
    QString strHostIp;
//	tcpSocket.connectToHost(QHostAddress::LocalHost, 5000);
    strHostIp = QInputDialog::getText(this,"HostIP","Input Server IP:",QLineEdit::Normal,SERVERIP,&ok);
    if(ok)
    {
        if(strHostIp.isEmpty())
            pQTcpSocket->connectToHost(SERVERIP, SERVERPOT);            // ��� ������ serverpot �̿�
        else
            pQTcpSocket->connectToHost(strHostIp, SERVERPOT);           // �Է��Ѱ� ������ �װ� ���
    }
}
void SocketClient::slotConnectServer()                                  // ������ ���� �Ǹ� ���� �Լ� ����
{
    QString Str = "["+LOGID+":"+LOGPW+"]";                              // ID, PW �Է�
    QByteArray byteStr = Str.toLocal8Bit();                             // byte�� �ٲ㼭 ���� �۽�
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

    if (pQTcpSocket->bytesAvailable() > BLOCK_SIZE)     // ���� �� �� �ִ� ������ ���������� Ȯ��
		return;
    qByteArray = pQTcpSocket->read(BLOCK_SIZE);         // Qstring == 2 ����Ʈ �����ڵ�, Tcp == 1 ����Ʈ
    strRecvData = QString::fromUtf8(qByteArray);        // ���� ������ �����ڵ�� ��ȯ ���ش�.
//    qDebug() <<strRecvData;                           // ����� �޼��� ���� ������ �ּ� ����
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
        strSendData = strSendData+"\n";                 // �ϳ��� ��ɾ ���� �Ǿ��ٰ� ��� �ǰ� ���๮�� �� �߰� �� �־����
        QByteArray bCmd = strSendData.toLocal8Bit();
//        qDebug() << bCmd;
        pQTcpSocket->write(bCmd);
    }
}

SocketClient::~SocketClient()
{
    pQTcpSocket->close();
}
