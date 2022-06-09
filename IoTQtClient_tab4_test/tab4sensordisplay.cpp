#include "tab4sensordisplay.h"
#include "ui_tab4sensordisplay.h"

Tab4SensorDisplay::Tab4SensorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4SensorDisplay)
{
    ui->setupUi(this);
}

Tab4SensorDisplay::~Tab4SensorDisplay()
{
    delete ui;
}
void Tab4SensorDisplay::slotTab4RecvData(QString recvData)
{
    recvData.replace("[", "@");                               // replace() -> 특정 문자로 치환하기 위한 함수
    recvData.replace("]", "@");                               // [19]LAMPON -> @19@LAMPON 으로 변환
    QStringList qlist = recvData.split("@");                  // qlist[3] -> 조도, qlist[4] -> 온도, qlist[5] -> 습도
    //qDebug() << "조도 : "+qlist[3] << " 온도 : " + qlist[4] << " 습도 : " + qlist[5];

    ui->pTEIlluminance->clear();
    ui->pTETemp->clear();
    ui->pTEHumi->clear();

    ui->pTEIlluminance->append(qlist[3]);
    //ui->pTEIlluminance->moveCursor(QTextCursor::End);
    ui->pTETemp->append(qlist[4]);
    //ui->pTETemp->moveCursor(QTextCursor::End);
    ui->pTEHumi->append(qlist[5]);
    //ui->pTEHumi->moveCursor(QTextCursor::End);
}
