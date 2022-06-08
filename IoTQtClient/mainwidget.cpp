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
    ui->pTab2->setLayout(pTab2SocketClient->layout());       // pTab2 layout에 pTab2SocketClient layout (push button)이
                                                             // 화면에 출력 되는 것을 볼 수 있다.
}

MainWidget::~MainWidget()
{
    delete ui;
}
