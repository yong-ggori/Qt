#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);     // SocketClient 객체 생성
    ui->pPBSendButton->setEnabled(false);
    connect(ui->pPBServerConnect, SIGNAL(clicked(bool)), this, SLOT(slotConnectToServer(bool)));            // connect 시 slot 함수 실행, 버튼 클릭 시 서버 연결
    connect(ui->pPBSendButton, SIGNAL(clicked()), this, SLOT(slotSocketSendData()));                        // send button 클릭 시 데이터 송신
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(slotSocketRecvUpdate(QString)));      // server에서의 메시지 text line에 출력
    connect(ui->pPBRecieveDataClear, SIGNAL(clicked()), ui->pTERecieveData, SLOT(clear()));                 // clear button 클릭 시 TE의 수신내용 삭제
}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}

void Tab2SocketClient::slotConnectToServer(bool check)
{
    bool bOk;
    if(check) {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk) {
            ui->pPBServerConnect->setText("서버 해제");          // 버튼 텍스트 "서버 해제"로 변경
            ui->pPBSendButton->setEnabled(true);                // button 활성화
        }
    }
    else {
        pSocketClient->slotClosedByServer();                    // 서버 종료
        ui->pPBServerConnect->setText("서버 연결");              // 버튼 텍스트 "서버 연결"로 변경
        ui->pPBSendButton->setEnabled(false);                   // button 비활성화
    }
}
void Tab2SocketClient::slotSocketSendData()
{
    QString strRecvID;
    QString strSendData;

    strRecvID = ui->pLERecieveID->text();                        // LE(Line Edit)에 입력된 데이터 저장
    strSendData = ui->pLESendData->text();                       // 위와 동일
    if(strRecvID.isEmpty())
        strSendData = "[ALLMSG]"+strSendData;                    // 지정 ID가 없을 시 모든 사람한테 메시지 전송
    else
        strSendData = "["+strRecvID+"]"+strSendData;             // 지정 ID가 있을 시에는 해당 하는 ID 에만 메시지 전송
    pSocketClient->slotSocketSendData(strSendData);              // 서버에 데이터 전송
    ui->pLESendData->clear();                                    // LE의 값 비움
}
void Tab2SocketClient::slotSocketSendData(QString strData)       // 위의 slotSocketSendData 중복 정의
{
    if(ui->pPBServerConnect->isChecked())                        // 서버에 연결유무 확인, 서버 연결 안되어 있을 때 버튼 실행 못하게 막음
        pSocketClient->slotSocketSendData(strData);              // socketclient.cpp 내의 함수 slotSocketSendData 사용
    else
        QMessageBox::information(this, "socket", "서버 연결 확인");// socket(서버) 연결되지 않았다면 메세지 박스 팝업
}
void Tab2SocketClient::slotSocketRecvUpdate(QString strRecvData)
{
    QTime time = QTime::currentTime();                                         // 현재 시간 호출 위한 함수, 싱글톤 함수(단 한 번만 만들어 지는 객체)
    QString strTime = time.toString();                                         // 현재 시간 string형에 저장
    //qDebug() << strTime;

    strRecvData.chop(1);                                                       // 가장 끝에 있는 문자 1개 삭제, '\n' 문자 지워 공백 없애준다.
                                                                               // '\n' : 데이터 송신 시 반드시 넣고, 수신 시 반드시 지워주자
    if((strRecvData.indexOf("LAMP") != -1) || strRecvData.indexOf("GAS")) {    // indexOf -> 특정 문자열을 찾는 함수, 없으면 -1 반환
        emit sigTab3RecvData(strRecvData);
    }

    strRecvData = strTime + " " + strRecvData;
    ui->pTERecieveData->append(strRecvData);                    // TE(Text edit)에 strRecvData 띄우기
    ui->pTERecieveData->moveCursor(QTextCursor::End);           // TE의 커서를 가장 마지막으로 이동
}
