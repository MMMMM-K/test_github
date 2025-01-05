/********************************************************************************
** Form generated from reading UI file 'faceattendence.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEATTENDENCE_H
#define UI_FACEATTENDENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceAttendence
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *wg_success;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_1;
    QLabel *lb_2;
    QLabel *lb_traceFace;
    QLabel *lb_camera;
    QWidget *widget_3;
    QLabel *lb_headpic;
    QLabel *lb_title;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *lb_employeeID;
    QLabel *label_10;
    QLabel *lb_time;
    QLabel *lb_nickname;
    QLabel *label_6;
    QLabel *lb_address;
    QLabel *label_8;

    void setupUi(QMainWindow *FaceAttendence)
    {
        if (FaceAttendence->objectName().isEmpty())
            FaceAttendence->setObjectName("FaceAttendence");
        FaceAttendence->resize(800, 480);
        FaceAttendence->setStyleSheet(QString::fromUtf8("QWidget#widget_3\n"
"{\n"
"	\n"
"	background-color: rgb(94, 94, 94);\n"
"}\n"
"\n"
"QWidget#widget_2\n"
"{\n"
"	background-color: rgba(180, 180, 180, 63);\n"
"}\n"
"\n"
"QLabel#lb_2\n"
"{\n"
"	font:25 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"}\n"
"/*\350\256\276\347\275\256\345\247\223\345\220\215\347\255\211*/\n"
"QLabel[name = \"key\"]\n"
"{\n"
"	background-color:#20232A;\n"
"	font:20 12pt\"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"	color:#808183;\n"
"}\n"
"/*\350\256\276\347\275\256\345\247\223\345\220\215\347\232\204\345\200\274\347\255\211*/\n"
"QLabel[name = \"value\"]\n"
"{\n"
"	background-color:#20232A;\n"
"	font:20 12pt\"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"	color:#ffffff;\n"
"}\n"
"/*\350\256\276\347\275\256\350\257\206\345\210\253\346\210\220\345\212\237\344\272\272\350\204\270\347\232\204\345\234\206\345\275\242*/\n"
"QLabel#lb_headpic\n"
"{\n"
"	background-color:#20232A;\n"
"	bor"
                        "der-radius:70px;\n"
"}\n"
"/*\350\256\276\347\275\256\346\240\207\351\242\230*/\n"
"QLabel#lb_title\n"
"{\n"
"	font:20 20pt\"\345\276\256\350\275\257\351\233\205\351\273\221 Bold\";\n"
"	color:#ffffff;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(FaceAttendence);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 480, 480));
        wg_success = new QWidget(widget);
        wg_success->setObjectName("wg_success");
        wg_success->setGeometry(QRect(150, 350, 181, 60));
        horizontalLayout = new QHBoxLayout(wg_success);
        horizontalLayout->setObjectName("horizontalLayout");
        lb_1 = new QLabel(wg_success);
        lb_1->setObjectName("lb_1");
        lb_1->setEnabled(true);
        lb_1->setPixmap(QPixmap(QString::fromUtf8(":/res/yes.png")));
        lb_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lb_1);

        lb_2 = new QLabel(wg_success);
        lb_2->setObjectName("lb_2");

        horizontalLayout->addWidget(lb_2);

        lb_traceFace = new QLabel(widget);
        lb_traceFace->setObjectName("lb_traceFace");
        lb_traceFace->setGeometry(QRect(100, 50, 271, 271));
        lb_traceFace->setPixmap(QPixmap(QString::fromUtf8(":/res/crc.png")));
        lb_camera = new QLabel(widget);
        lb_camera->setObjectName("lb_camera");
        lb_camera->setGeometry(QRect(0, 0, 480, 480));
        lb_camera->raise();
        wg_success->raise();
        lb_traceFace->raise();
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(480, 0, 320, 480));
        lb_headpic = new QLabel(widget_3);
        lb_headpic->setObjectName("lb_headpic");
        lb_headpic->setGeometry(QRect(80, 70, 160, 160));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_headpic->sizePolicy().hasHeightForWidth());
        lb_headpic->setSizePolicy(sizePolicy);
        lb_headpic->setMaximumSize(QSize(160, 166));
        lb_title = new QLabel(widget_3);
        lb_title->setObjectName("lb_title");
        lb_title->setGeometry(QRect(20, 10, 281, 51));
        lb_title->setMaximumSize(QSize(16777215, 80));
        lb_title->setAlignment(Qt::AlignCenter);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(1, 242, 321, 241));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(60, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lb_employeeID = new QLabel(widget_4);
        lb_employeeID->setObjectName("lb_employeeID");

        gridLayout->addWidget(lb_employeeID, 0, 1, 1, 1);

        label_10 = new QLabel(widget_4);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(60, 16777215));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        lb_time = new QLabel(widget_4);
        lb_time->setObjectName("lb_time");

        gridLayout->addWidget(lb_time, 3, 1, 1, 1);

        lb_nickname = new QLabel(widget_4);
        lb_nickname->setObjectName("lb_nickname");

        gridLayout->addWidget(lb_nickname, 1, 1, 1, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(60, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lb_address = new QLabel(widget_4);
        lb_address->setObjectName("lb_address");

        gridLayout->addWidget(lb_address, 2, 1, 1, 1);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(60, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        FaceAttendence->setCentralWidget(centralwidget);

        retranslateUi(FaceAttendence);

        QMetaObject::connectSlotsByName(FaceAttendence);
    } // setupUi

    void retranslateUi(QMainWindow *FaceAttendence)
    {
        FaceAttendence->setWindowTitle(QCoreApplication::translate("FaceAttendence", "FaceAttendence", nullptr));
        lb_1->setText(QString());
        lb_2->setText(QCoreApplication::translate("FaceAttendence", "\350\256\244\350\257\201\346\210\220\345\212\237", nullptr));
        lb_traceFace->setText(QString());
        lb_camera->setText(QString());
        lb_headpic->setText(QString());
        lb_title->setText(QCoreApplication::translate("FaceAttendence", "\344\272\272\350\204\270\350\257\206\345\210\253\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        label_4->setText(QCoreApplication::translate("FaceAttendence", "\345\267\245\345\217\267", nullptr));
        label_4->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "key", nullptr)));
        lb_employeeID->setText(QString());
        lb_employeeID->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "value", nullptr)));
        label_10->setText(QCoreApplication::translate("FaceAttendence", "\346\227\266\351\227\264", nullptr));
        label_10->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "key", nullptr)));
        lb_time->setText(QString());
        lb_time->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "value", nullptr)));
        lb_nickname->setText(QString());
        lb_nickname->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "value", nullptr)));
        label_6->setText(QCoreApplication::translate("FaceAttendence", "\345\247\223\345\220\215", nullptr));
        label_6->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "key", nullptr)));
        lb_address->setText(QString());
        lb_address->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "value", nullptr)));
        label_8->setText(QCoreApplication::translate("FaceAttendence", "\345\234\260\345\235\200", nullptr));
        label_8->setProperty("name", QVariant(QCoreApplication::translate("FaceAttendence", "key", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class FaceAttendence: public Ui_FaceAttendence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEATTENDENCE_H
