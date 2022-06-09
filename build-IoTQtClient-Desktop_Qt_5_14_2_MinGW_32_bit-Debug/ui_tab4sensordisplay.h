/********************************************************************************
** Form generated from reading UI file 'tab4sensordisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB4SENSORDISPLAY_H
#define UI_TAB4SENSORDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab4SensorDisplay
{
public:
    QTextEdit *pTEIlluminance;
    QLabel *label;
    QTextEdit *pTETemp;
    QTextEdit *pTEHumi;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Tab4SensorDisplay)
    {
        if (Tab4SensorDisplay->objectName().isEmpty())
            Tab4SensorDisplay->setObjectName(QString::fromUtf8("Tab4SensorDisplay"));
        Tab4SensorDisplay->resize(580, 380);
        pTEIlluminance = new QTextEdit(Tab4SensorDisplay);
        pTEIlluminance->setObjectName(QString::fromUtf8("pTEIlluminance"));
        pTEIlluminance->setGeometry(QRect(230, 70, 110, 50));
        pTEIlluminance->setLineWidth(0);
        pTEIlluminance->setMidLineWidth(0);
        pTEIlluminance->setLineWrapMode(QTextEdit::WidgetWidth);
        label = new QLabel(Tab4SensorDisplay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 70, 110, 50));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        pTETemp = new QTextEdit(Tab4SensorDisplay);
        pTETemp->setObjectName(QString::fromUtf8("pTETemp"));
        pTETemp->setGeometry(QRect(230, 140, 110, 50));
        pTEHumi = new QTextEdit(Tab4SensorDisplay);
        pTEHumi->setObjectName(QString::fromUtf8("pTEHumi"));
        pTEHumi->setGeometry(QRect(230, 210, 110, 50));
        label_2 = new QLabel(Tab4SensorDisplay);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 140, 110, 50));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Tab4SensorDisplay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 210, 110, 50));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Tab4SensorDisplay);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 140, 110, 50));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(Tab4SensorDisplay);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 70, 110, 50));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(Tab4SensorDisplay);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 210, 110, 50));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(Tab4SensorDisplay);

        QMetaObject::connectSlotsByName(Tab4SensorDisplay);
    } // setupUi

    void retranslateUi(QWidget *Tab4SensorDisplay)
    {
        Tab4SensorDisplay->setWindowTitle(QCoreApplication::translate("Tab4SensorDisplay", "Form", nullptr));
        pTEIlluminance->setHtml(QCoreApplication::translate("Tab4SensorDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\241\260\353\217\204", nullptr));
        pTETemp->setHtml(QCoreApplication::translate("Tab4SensorDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pTEHumi->setHtml(QCoreApplication::translate("Tab4SensorDisplay", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\230\250\353\217\204", nullptr));
        label_3->setText(QCoreApplication::translate("Tab4SensorDisplay", "\354\212\265\353\217\204", nullptr));
        label_4->setText(QCoreApplication::translate("Tab4SensorDisplay", "C", nullptr));
        label_5->setText(QCoreApplication::translate("Tab4SensorDisplay", "%", nullptr));
        label_6->setText(QCoreApplication::translate("Tab4SensorDisplay", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab4SensorDisplay: public Ui_Tab4SensorDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB4SENSORDISPLAY_H
