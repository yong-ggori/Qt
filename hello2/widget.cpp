#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    hello = new QLabel("hello crystal", this);  // 실행 창 여러개 뜨는 것 방지하기 위해 this 사용
                                                // 부모 위도우 이용해서 "hello crystal" 출력해라. 라는 의미
    hello->show();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
