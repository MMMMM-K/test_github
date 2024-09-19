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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aboutwindow
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *Aboutwindow)
    {
        if (Aboutwindow->objectName().isEmpty())
            Aboutwindow->setObjectName("Aboutwindow");
        Aboutwindow->resize(367, 193);
        pushButton = new QPushButton(Aboutwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 150, 101, 31));
        textEdit = new QTextEdit(Aboutwindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(80, 40, 191, 91));

        retranslateUi(Aboutwindow);
        QObject::connect(pushButton, &QPushButton::clicked, Aboutwindow, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Aboutwindow);
    } // setupUi

    void retranslateUi(QWidget *Aboutwindow)
    {
        Aboutwindow->setWindowTitle(QCoreApplication::translate("Aboutwindow", "About message", nullptr));
        pushButton->setText(QCoreApplication::translate("Aboutwindow", "OK", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Aboutwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; text-decoration: underline;\">\345\274\200\345\217\221\344\272\272\345\221\230\344\277\241\346\201\257\357\274\232</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; text-decorati"
                        "on: underline;\">\351\251\254\347\245\216\346\230\216/2022413210232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Aboutwindow: public Ui_Aboutwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
