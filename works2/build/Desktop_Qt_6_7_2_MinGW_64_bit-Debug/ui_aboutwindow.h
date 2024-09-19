/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aboutwindow
{
public:

    void setupUi(QWidget *Aboutwindow)
    {
        if (Aboutwindow->objectName().isEmpty())
            Aboutwindow->setObjectName("Aboutwindow");
        Aboutwindow->resize(400, 300);

        retranslateUi(Aboutwindow);

        QMetaObject::connectSlotsByName(Aboutwindow);
    } // setupUi

    void retranslateUi(QWidget *Aboutwindow)
    {
        Aboutwindow->setWindowTitle(QCoreApplication::translate("Aboutwindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Aboutwindow: public Ui_Aboutwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
