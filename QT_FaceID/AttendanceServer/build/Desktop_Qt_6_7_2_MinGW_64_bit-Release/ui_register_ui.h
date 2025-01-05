/********************************************************************************
** Form generated from reading UI file 'register_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_UI_H
#define UI_REGISTER_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register_ui
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_nickname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_sex;
    QRadioButton *btn_man;
    QRadioButton *btn_girl;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *le_birthday;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *le_adress;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *le_phone;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_register;
    QPushButton *btn_clear;
    QVBoxLayout *verticalLayout_2;
    QLabel *lb_pic;
    QLineEdit *le_path;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_addhead;
    QPushButton *btn_opencamera;
    QPushButton *btn_shoot;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *register_ui)
    {
        if (register_ui->objectName().isEmpty())
            register_ui->setObjectName("register_ui");
        register_ui->resize(800, 480);
        layoutWidget = new QWidget(register_ui);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(11, 1, 781, 481));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        le_nickname = new QLineEdit(layoutWidget);
        le_nickname->setObjectName("le_nickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_nickname->sizePolicy().hasHeightForWidth());
        le_nickname->setSizePolicy(sizePolicy);
        le_nickname->setFont(font);

        horizontalLayout->addWidget(le_nickname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_sex = new QLabel(layoutWidget);
        lb_sex->setObjectName("lb_sex");
        lb_sex->setFont(font);

        horizontalLayout_2->addWidget(lb_sex);

        btn_man = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(register_ui);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btn_man);
        btn_man->setObjectName("btn_man");
        btn_man->setFont(font);
        btn_man->setChecked(true);

        horizontalLayout_2->addWidget(btn_man);

        btn_girl = new QRadioButton(layoutWidget);
        buttonGroup->addButton(btn_girl);
        btn_girl->setObjectName("btn_girl");
        btn_girl->setFont(font);

        horizontalLayout_2->addWidget(btn_girl);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        le_birthday = new QDateEdit(layoutWidget);
        le_birthday->setObjectName("le_birthday");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_birthday->sizePolicy().hasHeightForWidth());
        le_birthday->setSizePolicy(sizePolicy1);
        le_birthday->setFont(font);

        horizontalLayout_3->addWidget(le_birthday);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        le_adress = new QLineEdit(layoutWidget);
        le_adress->setObjectName("le_adress");
        sizePolicy.setHeightForWidth(le_adress->sizePolicy().hasHeightForWidth());
        le_adress->setSizePolicy(sizePolicy);
        le_adress->setFont(font);

        horizontalLayout_4->addWidget(le_adress);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        le_phone = new QLineEdit(layoutWidget);
        le_phone->setObjectName("le_phone");
        sizePolicy.setHeightForWidth(le_phone->sizePolicy().hasHeightForWidth());
        le_phone->setSizePolicy(sizePolicy);
        le_phone->setFont(font);

        horizontalLayout_5->addWidget(le_phone);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btn_register = new QPushButton(layoutWidget);
        btn_register->setObjectName("btn_register");
        btn_register->setMinimumSize(QSize(0, 60));

        horizontalLayout_6->addWidget(btn_register);

        btn_clear = new QPushButton(layoutWidget);
        btn_clear->setObjectName("btn_clear");
        btn_clear->setMinimumSize(QSize(0, 60));

        horizontalLayout_6->addWidget(btn_clear);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lb_pic = new QLabel(layoutWidget);
        lb_pic->setObjectName("lb_pic");
        lb_pic->setMinimumSize(QSize(0, 300));
        lb_pic->setMaximumSize(QSize(16777215, 167777));
        lb_pic->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));

        verticalLayout_2->addWidget(lb_pic);

        le_path = new QLineEdit(layoutWidget);
        le_path->setObjectName("le_path");

        verticalLayout_2->addWidget(le_path);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btn_addhead = new QPushButton(layoutWidget);
        btn_addhead->setObjectName("btn_addhead");
        sizePolicy1.setHeightForWidth(btn_addhead->sizePolicy().hasHeightForWidth());
        btn_addhead->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(btn_addhead);

        btn_opencamera = new QPushButton(layoutWidget);
        btn_opencamera->setObjectName("btn_opencamera");
        sizePolicy1.setHeightForWidth(btn_opencamera->sizePolicy().hasHeightForWidth());
        btn_opencamera->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(btn_opencamera);

        btn_shoot = new QPushButton(layoutWidget);
        btn_shoot->setObjectName("btn_shoot");
        sizePolicy1.setHeightForWidth(btn_shoot->sizePolicy().hasHeightForWidth());
        btn_shoot->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(btn_shoot);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_2);


        retranslateUi(register_ui);

        QMetaObject::connectSlotsByName(register_ui);
    } // setupUi

    void retranslateUi(QWidget *register_ui)
    {
        register_ui->setWindowTitle(QCoreApplication::translate("register_ui", "Form", nullptr));
        label->setText(QCoreApplication::translate("register_ui", "\345\247\223\345\220\215\357\274\232", nullptr));
        lb_sex->setText(QCoreApplication::translate("register_ui", "\346\200\247\345\210\253 \357\274\232", nullptr));
        btn_man->setText(QCoreApplication::translate("register_ui", "\347\224\267", nullptr));
        btn_girl->setText(QCoreApplication::translate("register_ui", "\345\245\263", nullptr));
        label_3->setText(QCoreApplication::translate("register_ui", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("register_ui", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("register_ui", "\347\224\265\350\257\235\357\274\232", nullptr));
        btn_register->setText(QCoreApplication::translate("register_ui", "\346\263\250\345\206\214", nullptr));
        btn_clear->setText(QCoreApplication::translate("register_ui", "\351\207\215\347\275\256", nullptr));
        lb_pic->setText(QString());
        btn_addhead->setText(QCoreApplication::translate("register_ui", "\346\267\273\345\212\240\345\244\264\345\203\217", nullptr));
        btn_opencamera->setText(QCoreApplication::translate("register_ui", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        btn_shoot->setText(QCoreApplication::translate("register_ui", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_ui: public Ui_register_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_UI_H
