/********************************************************************************
** Form generated from reading UI file 'tab2socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2SOCKETCLIENT_H
#define UI_TAB2SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2SocketClient
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *pLabel;
    QPushButton *pPBRecieveDataClear;
    QPushButton *pPBServerConnect;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *pTERecieveData;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pLERecieveID;
    QLineEdit *pLESendData;
    QPushButton *pPBSendButton;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName(QString::fromUtf8("Tab2SocketClient"));
        Tab2SocketClient->resize(580, 380);
        verticalLayout = new QVBoxLayout(Tab2SocketClient);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pLabel = new QLabel(Tab2SocketClient);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));

        horizontalLayout->addWidget(pLabel);

        pPBRecieveDataClear = new QPushButton(Tab2SocketClient);
        pPBRecieveDataClear->setObjectName(QString::fromUtf8("pPBRecieveDataClear"));
        pPBRecieveDataClear->setAutoRepeatDelay(300);

        horizontalLayout->addWidget(pPBRecieveDataClear);

        pPBServerConnect = new QPushButton(Tab2SocketClient);
        pPBServerConnect->setObjectName(QString::fromUtf8("pPBServerConnect"));
        pPBServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPBServerConnect);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pTERecieveData = new QTextEdit(Tab2SocketClient);
        pTERecieveData->setObjectName(QString::fromUtf8("pTERecieveData"));

        horizontalLayout_2->addWidget(pTERecieveData);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pLERecieveID = new QLineEdit(Tab2SocketClient);
        pLERecieveID->setObjectName(QString::fromUtf8("pLERecieveID"));

        horizontalLayout_3->addWidget(pLERecieveID);

        pLESendData = new QLineEdit(Tab2SocketClient);
        pLESendData->setObjectName(QString::fromUtf8("pLESendData"));

        horizontalLayout_3->addWidget(pLESendData);

        pPBSendButton = new QPushButton(Tab2SocketClient);
        pPBSendButton->setObjectName(QString::fromUtf8("pPBSendButton"));

        horizontalLayout_3->addWidget(pPBSendButton);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Tab2SocketClient);

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        pLabel->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \353\215\260\354\235\264\355\204\260", nullptr));
        pPBRecieveDataClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \354\202\255\354\240\234", nullptr));
        pPBServerConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPBSendButton->setText(QCoreApplication::translate("Tab2SocketClient", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
