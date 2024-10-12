/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *eight;
    QPushButton *two;
    QPushButton *negate;
    QPushButton *minus;
    QPushButton *seven;
    QPushButton *divide;
    QPushButton *equal;
    QPushButton *clear;
    QPushButton *six;
    QPushButton *Reciprocal;
    QPushButton *multiply;
    QPushButton *nine;
    QPushButton *CE;
    QPushButton *square;
    QLineEdit *Display;
    QPushButton *five;
    QPushButton *zero;
    QPushButton *add;
    QPushButton *four;
    QPushButton *root;
    QPushButton *one;
    QPushButton *point;
    QPushButton *Delete;
    QPushButton *three;
    QPushButton *Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(365, 430);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 12pt \"Mongolian Baiti\";\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(1, 1, 1, 2);
        eight = new QPushButton(centralwidget);
        eight->setObjectName("eight");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eight->sizePolicy().hasHeightForWidth());
        eight->setSizePolicy(sizePolicy);

        gridLayout->addWidget(eight, 3, 1, 1, 1);

        two = new QPushButton(centralwidget);
        two->setObjectName("two");
        sizePolicy.setHeightForWidth(two->sizePolicy().hasHeightForWidth());
        two->setSizePolicy(sizePolicy);

        gridLayout->addWidget(two, 5, 1, 1, 1);

        negate = new QPushButton(centralwidget);
        negate->setObjectName("negate");
        sizePolicy.setHeightForWidth(negate->sizePolicy().hasHeightForWidth());
        negate->setSizePolicy(sizePolicy);

        gridLayout->addWidget(negate, 6, 0, 1, 1);

        minus = new QPushButton(centralwidget);
        minus->setObjectName("minus");
        sizePolicy.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy);

        gridLayout->addWidget(minus, 4, 3, 1, 1);

        seven = new QPushButton(centralwidget);
        seven->setObjectName("seven");
        sizePolicy.setHeightForWidth(seven->sizePolicy().hasHeightForWidth());
        seven->setSizePolicy(sizePolicy);

        gridLayout->addWidget(seven, 3, 0, 1, 1);

        divide = new QPushButton(centralwidget);
        divide->setObjectName("divide");
        sizePolicy.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy);

        gridLayout->addWidget(divide, 2, 3, 1, 1);

        equal = new QPushButton(centralwidget);
        equal->setObjectName("equal");
        sizePolicy.setHeightForWidth(equal->sizePolicy().hasHeightForWidth());
        equal->setSizePolicy(sizePolicy);

        gridLayout->addWidget(equal, 6, 3, 1, 1);

        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);

        gridLayout->addWidget(clear, 1, 2, 1, 1);

        six = new QPushButton(centralwidget);
        six->setObjectName("six");
        sizePolicy.setHeightForWidth(six->sizePolicy().hasHeightForWidth());
        six->setSizePolicy(sizePolicy);

        gridLayout->addWidget(six, 4, 2, 1, 1);

        Reciprocal = new QPushButton(centralwidget);
        Reciprocal->setObjectName("Reciprocal");
        sizePolicy.setHeightForWidth(Reciprocal->sizePolicy().hasHeightForWidth());
        Reciprocal->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Reciprocal, 2, 0, 1, 1);

        multiply = new QPushButton(centralwidget);
        multiply->setObjectName("multiply");
        sizePolicy.setHeightForWidth(multiply->sizePolicy().hasHeightForWidth());
        multiply->setSizePolicy(sizePolicy);

        gridLayout->addWidget(multiply, 3, 3, 1, 1);

        nine = new QPushButton(centralwidget);
        nine->setObjectName("nine");
        sizePolicy.setHeightForWidth(nine->sizePolicy().hasHeightForWidth());
        nine->setSizePolicy(sizePolicy);

        gridLayout->addWidget(nine, 3, 2, 1, 1);

        CE = new QPushButton(centralwidget);
        CE->setObjectName("CE");
        sizePolicy.setHeightForWidth(CE->sizePolicy().hasHeightForWidth());
        CE->setSizePolicy(sizePolicy);

        gridLayout->addWidget(CE, 1, 1, 1, 1);

        square = new QPushButton(centralwidget);
        square->setObjectName("square");
        sizePolicy.setHeightForWidth(square->sizePolicy().hasHeightForWidth());
        square->setSizePolicy(sizePolicy);

        gridLayout->addWidget(square, 2, 1, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName("Display");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(false);
        Display->setFont(font);
        Display->setCursorPosition(0);
        Display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 1, 4);

        five = new QPushButton(centralwidget);
        five->setObjectName("five");
        sizePolicy.setHeightForWidth(five->sizePolicy().hasHeightForWidth());
        five->setSizePolicy(sizePolicy);

        gridLayout->addWidget(five, 4, 1, 1, 1);

        zero = new QPushButton(centralwidget);
        zero->setObjectName("zero");
        sizePolicy.setHeightForWidth(zero->sizePolicy().hasHeightForWidth());
        zero->setSizePolicy(sizePolicy);

        gridLayout->addWidget(zero, 6, 1, 1, 1);

        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        sizePolicy.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy);

        gridLayout->addWidget(add, 5, 3, 1, 1);

        four = new QPushButton(centralwidget);
        four->setObjectName("four");
        sizePolicy.setHeightForWidth(four->sizePolicy().hasHeightForWidth());
        four->setSizePolicy(sizePolicy);

        gridLayout->addWidget(four, 4, 0, 1, 1);

        root = new QPushButton(centralwidget);
        root->setObjectName("root");
        sizePolicy.setHeightForWidth(root->sizePolicy().hasHeightForWidth());
        root->setSizePolicy(sizePolicy);

        gridLayout->addWidget(root, 2, 2, 1, 1);

        one = new QPushButton(centralwidget);
        one->setObjectName("one");
        sizePolicy.setHeightForWidth(one->sizePolicy().hasHeightForWidth());
        one->setSizePolicy(sizePolicy);

        gridLayout->addWidget(one, 5, 0, 1, 1);

        point = new QPushButton(centralwidget);
        point->setObjectName("point");
        sizePolicy.setHeightForWidth(point->sizePolicy().hasHeightForWidth());
        point->setSizePolicy(sizePolicy);

        gridLayout->addWidget(point, 6, 2, 1, 1);

        Delete = new QPushButton(centralwidget);
        Delete->setObjectName("Delete");
        sizePolicy.setHeightForWidth(Delete->sizePolicy().hasHeightForWidth());
        Delete->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Delete, 1, 3, 1, 1);

        three = new QPushButton(centralwidget);
        three->setObjectName("three");
        sizePolicy.setHeightForWidth(three->sizePolicy().hasHeightForWidth());
        three->setSizePolicy(sizePolicy);

        gridLayout->addWidget(three, 5, 2, 1, 1);

        Button = new QPushButton(centralwidget);
        Button->setObjectName("Button");
        sizePolicy.setHeightForWidth(Button->sizePolicy().hasHeightForWidth());
        Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 365, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        negate->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        divide->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Reciprocal->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        multiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        CE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        square->setText(QCoreApplication::translate("MainWindow", "x\302\262", nullptr));
        Display->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        root->setText(QCoreApplication::translate("MainWindow", "\342\210\232x", nullptr));
        one->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        three->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
