#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);                       // 프로그램 실행 시 tab1 화면이 항상 출력되게 하기 위함.
    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);     // Tab2SocketClient 객체 생성,
                                                             // pTab2 누르게 되면 Tab2SocketCleint 객체 생성된다.
    ui->pTab2->setLayout(pTab2SocketClient->layout());       // pTab2 layout에 pTab2SocketClient layout이
                                                             // 화면에 출력 되는 것을 볼 수 있다.
    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());      // tab3 에 화면 출력
    pTab4SensorDisplay = new Tab4SensorDisplay(ui->pTab4);
    ui->pTab4->setLayout(pTab4SensorDisplay->layout());
    connect(pTab2SocketClient, SIGNAL(sigTab3RecvData(QString)), pTab3ControlPannel, SLOT(slotTab3RecvData(QString)));
    // Tab 2 TE 에 출력된 데이터 중 Tab 3에서 필요한 데이터들만 가져오기 위한 시그널
    // LAMP와 GAS가 들어간 문자열만 TAB3로 가져와서 사용한다.
    connect(pTab3ControlPannel, SIGNAL(sigSocketSendData(QString)), pTab2SocketClient, SLOT(slotSocketSendData(QString)));
    // pTab2SocketClient->socketclient 안의 private함수 slotSocketSendData
    // 사용하기 위함, tab2 tab3 모두 접근 가능한
    // main widgets에서 접근한다.
    connect(pTab2SocketClient, SIGNAL(sigTab4RecvData(QString)), pTab4SensorDisplay, SLOT(slotTab4RecvData(QString)));
}

MainWidget::~MainWidget()
{
    delete ui;
}
