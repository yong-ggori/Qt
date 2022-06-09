#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "tab2socketclient.h"               // tab2 ui 사용하기 위한,
                                            // mainwidget에서 tab2 객체를 생성하기 위한 선언

#include "tab3controlpannel.h"
#include "tab4sensordisplay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    Tab2SocketClient *pTab2SocketClient;    // Tab2SocketClient 포인터 변수 선언
    Tab3ControlPannel *pTab3ControlPannel;
    Tab4SensorDisplay *pTab4SensorDisplay;
};
#endif // MAINWIDGET_H
