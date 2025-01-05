/********************************************************************************
** Form generated from reading UI file 'attendancewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCEWINDOW_H
#define UI_ATTENDANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttendanceWindow
{
public:
    QWidget *centralwidget;
    QLabel *lb_pic;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_register;
    QPushButton *btn_query;

    void setupUi(QMainWindow *AttendanceWindow)
    {
        if (AttendanceWindow->objectName().isEmpty())
            AttendanceWindow->setObjectName("AttendanceWindow");
        AttendanceWindow->resize(800, 480);
        AttendanceWindow->setStyleSheet(QString::fromUtf8("QLabel#lb_pic\n"
"{\n"
"	background-color: rgb(255, 85, 255);\n"
"}"));
        centralwidget = new QWidget(AttendanceWindow);
        centralwidget->setObjectName("centralwidget");
        lb_pic = new QLabel(centralwidget);
        lb_pic->setObjectName("lb_pic");
        lb_pic->setGeometry(QRect(0, 0, 480, 480));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(480, 300, 311, 121));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_register = new QPushButton(widget);
        btn_register->setObjectName("btn_register");

        horizontalLayout->addWidget(btn_register);

        btn_query = new QPushButton(widget);
        btn_query->setObjectName("btn_query");

        horizontalLayout->addWidget(btn_query);

        AttendanceWindow->setCentralWidget(centralwidget);

        retranslateUi(AttendanceWindow);

        QMetaObject::connectSlotsByName(AttendanceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttendanceWindow)
    {
        AttendanceWindow->setWindowTitle(QCoreApplication::translate("AttendanceWindow", "AttendanceWindow", nullptr));
        lb_pic->setText(QString());
        btn_register->setText(QCoreApplication::translate("AttendanceWindow", "\346\263\250\345\206\214\347\224\250\346\210\267", nullptr));
        btn_query->setText(QCoreApplication::translate("AttendanceWindow", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttendanceWindow: public Ui_AttendanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCEWINDOW_H
