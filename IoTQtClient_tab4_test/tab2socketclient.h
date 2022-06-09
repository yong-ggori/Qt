#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>                        // log 시간 작성 위한 QTime 클래스 사용하기 위한 헤더파일 선언
#include <QDebug>                       // QDebug 함수 사용 위한 헤더 파일 선언
#include <QMessageBox>
#include "socketclient.h"

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();

private:
    Ui::Tab2SocketClient *ui;
    SocketClient *pSocketClient;
private slots:                          // slot 함수 정의
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);
    void slotSocketSendData();
    void slotSocketSendData(QString);   // slotSocketSendData 중복 정의, 매개 변수 달리 함
signals:                                // signal 함수 정의, 발생 시키고 싶은 이벤트, 이벤트 발생 시 원하는 함수 실행
    void sigSocketRecv(QString);
    void sigTab3RecvData(QString);
    void sigTab4RecvData(QString);      // tab4 sig
};

#endif // TAB2SOCKETCLIENT_H
