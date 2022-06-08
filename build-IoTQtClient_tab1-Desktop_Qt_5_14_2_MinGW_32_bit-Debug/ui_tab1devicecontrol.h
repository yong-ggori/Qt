/********************************************************************************
** Form generated from reading UI file 'tab1devicecontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1DEVICECONTROL_H
#define UI_TAB1DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1DeviceControl
{
public:

    void setupUi(QWidget *Tab1DeviceControl)
    {
        if (Tab1DeviceControl->objectName().isEmpty())
            Tab1DeviceControl->setObjectName(QString::fromUtf8("Tab1DeviceControl"));
        Tab1DeviceControl->resize(800, 600);

        retranslateUi(Tab1DeviceControl);

        QMetaObject::connectSlotsByName(Tab1DeviceControl);
    } // setupUi

    void retranslateUi(QWidget *Tab1DeviceControl)
    {
        Tab1DeviceControl->setWindowTitle(QCoreApplication::translate("Tab1DeviceControl", "Tab1DeviceControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1DeviceControl: public Ui_Tab1DeviceControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1DEVICECONTROL_H
