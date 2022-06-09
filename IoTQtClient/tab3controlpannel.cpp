#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    connect(ui->pPBLamp, SIGNAL(clicked(bool)), this, SLOT(slotLampOnOff(bool)));
    connect(ui->pPBPlug, SIGNAL(clicked(bool)), this, SLOT(slotPlugOnOff(bool)));
}

Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}
void Tab3ControlPannel::slotLampOnOff(bool check)
{
    if(check) {
        ui->pPBLamp->setChecked(false);         // setChecked() button on/off 선택하는 함수
        emit sigSocketSendData("[19]LAMPON");   // emit -> 시그널 생성 함수
    }
    else {
        ui->pPBLamp->setChecked(true);
        emit sigSocketSendData("[19]LAMPOFF");
    }
}
void Tab3ControlPannel::slotPlugOnOff(bool check)
{
    if(check) {
        ui->pPBPlug->setChecked(false);         // setChecked() button on/off 선택하는 함수
        emit sigSocketSendData("[19]GASON");    // emit -> 시그널 생성 함수
    }
    else {
        ui->pPBPlug->setChecked(true);
        emit sigSocketSendData("[19]GASOFF");
    }
}
void Tab3ControlPannel::slotTab3RecvData(QString recvData)
{
    //QMessageBox::information(this, "socket", recvData);     // 시그널 정상적으로 전달 됬는지 확인하는 메세지 박스
    recvData.replace("[", "@");                               // replace() -> 특정 문자로 치환하기 위한 함수
    recvData.replace("]", "@");                               // [19]LAMPON -> @19@LAMPON 으로 변환
    QStringList qlist = recvData.split("@");                  // split -> strtok와 유사한 기능, 자른 문자열을 QStringList에 배열처럼 저장
                                                              // qlist[0] = NULL, qlist[1] = "19", qlist[2] = "LAMPON"
    //qDebug() << qlist[2];
    if(qlist[2] == "LAMPON")
        ui->pPBLamp->setChecked(true);
    else if(qlist[2] == "LAMPOFF")
        ui->pPBLamp->setChecked(false);
    else if(qlist[2] == "GASON")
        ui->pPBPlug->setChecked(true);
    else if(qlist[2] == "GASOFF")
        ui->pPBPlug->setChecked(false);
}

