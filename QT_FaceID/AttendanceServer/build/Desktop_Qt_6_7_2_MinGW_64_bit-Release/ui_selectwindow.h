/********************************************************************************
** Form generated from reading UI file 'selectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWINDOW_H
#define UI_SELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectwindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *btn_employee;
    QRadioButton *btn_attend;
    QPushButton *btn_check;
    QTableView *tv_message;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *selectwindow)
    {
        if (selectwindow->objectName().isEmpty())
            selectwindow->setObjectName("selectwindow");
        selectwindow->resize(800, 480);
        gridLayout = new QGridLayout(selectwindow);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btn_employee = new QRadioButton(selectwindow);
        buttonGroup = new QButtonGroup(selectwindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btn_employee);
        btn_employee->setObjectName("btn_employee");
        btn_employee->setChecked(true);

        horizontalLayout->addWidget(btn_employee);

        btn_attend = new QRadioButton(selectwindow);
        buttonGroup->addButton(btn_attend);
        btn_attend->setObjectName("btn_attend");

        horizontalLayout->addWidget(btn_attend);

        btn_check = new QPushButton(selectwindow);
        btn_check->setObjectName("btn_check");

        horizontalLayout->addWidget(btn_check);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tv_message = new QTableView(selectwindow);
        tv_message->setObjectName("tv_message");

        gridLayout->addWidget(tv_message, 1, 0, 1, 1);


        retranslateUi(selectwindow);

        QMetaObject::connectSlotsByName(selectwindow);
    } // setupUi

    void retranslateUi(QWidget *selectwindow)
    {
        selectwindow->setWindowTitle(QCoreApplication::translate("selectwindow", "Form", nullptr));
        btn_employee->setText(QCoreApplication::translate("selectwindow", "\345\221\230\345\267\245\344\277\241\346\201\257\350\241\250", nullptr));
        btn_attend->setText(QCoreApplication::translate("selectwindow", "\350\200\203\345\213\244\350\241\250", nullptr));
        btn_check->setText(QCoreApplication::translate("selectwindow", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectwindow: public Ui_selectwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWINDOW_H
