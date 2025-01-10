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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *serveEdit;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *login;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QWidget *chatPage;
    QGridLayout *gridLayout_3;
    QTextEdit *chatRecord;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *privateTargetComboBox;
    QPushButton *privateSayButton;
    QListWidget *userList;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *messageEdit;
    QPushButton *sent;
    QPushButton *quit;
    QPushButton *kickButton;
    QPushButton *muteButton;
    QPushButton *ummuteButton;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        gridLayout = new QGridLayout(loginPage);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 142, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        frame = new QFrame(loginPage);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        serveEdit = new QLineEdit(frame);
        serveEdit->setObjectName("serveEdit");

        verticalLayout_3->addWidget(serveEdit);

        nameEdit = new QLineEdit(frame);
        nameEdit->setObjectName("nameEdit");

        verticalLayout_3->addWidget(nameEdit);

        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout_3->addWidget(passwordEdit);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        login = new QPushButton(frame);
        login->setObjectName("login");
        login->setFont(font);

        verticalLayout_4->addWidget(login);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(147, 150, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 142, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(182, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        stackedWidget->addWidget(loginPage);
        chatPage = new QWidget();
        chatPage->setObjectName("chatPage");
        gridLayout_3 = new QGridLayout(chatPage);
        gridLayout_3->setObjectName("gridLayout_3");
        chatRecord = new QTextEdit(chatPage);
        chatRecord->setObjectName("chatRecord");
        chatRecord->setMinimumSize(QSize(391, 0));

        gridLayout_3->addWidget(chatRecord, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        privateTargetComboBox = new QComboBox(chatPage);
        privateTargetComboBox->setObjectName("privateTargetComboBox");
        privateTargetComboBox->setMinimumSize(QSize(90, 0));

        horizontalLayout_5->addWidget(privateTargetComboBox);

        privateSayButton = new QPushButton(chatPage);
        privateSayButton->setObjectName("privateSayButton");
        privateSayButton->setMinimumSize(QSize(50, 0));
        privateSayButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(privateSayButton);


        verticalLayout->addLayout(horizontalLayout_5);

        userList = new QListWidget(chatPage);
        userList->setObjectName("userList");
        userList->setMaximumSize(QSize(6666, 16777215));

        verticalLayout->addWidget(userList);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        messageEdit = new QLineEdit(chatPage);
        messageEdit->setObjectName("messageEdit");

        horizontalLayout_3->addWidget(messageEdit);

        sent = new QPushButton(chatPage);
        sent->setObjectName("sent");

        horizontalLayout_3->addWidget(sent);

        quit = new QPushButton(chatPage);
        quit->setObjectName("quit");

        horizontalLayout_3->addWidget(quit);

        kickButton = new QPushButton(chatPage);
        kickButton->setObjectName("kickButton");
        kickButton->setMinimumSize(QSize(50, 0));
        kickButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(kickButton);

        muteButton = new QPushButton(chatPage);
        muteButton->setObjectName("muteButton");
        muteButton->setMinimumSize(QSize(50, 0));
        muteButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(muteButton);

        ummuteButton = new QPushButton(chatPage);
        ummuteButton->setObjectName("ummuteButton");
        ummuteButton->setMinimumSize(QSize(70, 0));
        ummuteButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(ummuteButton);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        stackedWidget->addWidget(chatPage);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 100));
        label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        serveEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        nameEdit->setText(QCoreApplication::translate("MainWindow", "mym", nullptr));
        passwordEdit->setText(QCoreApplication::translate("MainWindow", "123456", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        privateTargetComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\224\250\346\210\267", nullptr));
        privateSayButton->setText(QCoreApplication::translate("MainWindow", "\347\247\201\350\201\212", nullptr));
        sent->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        kickButton->setText(QCoreApplication::translate("MainWindow", "\350\270\242\345\207\272", nullptr));
        muteButton->setText(QCoreApplication::translate("MainWindow", "\347\246\201\350\250\200", nullptr));
        ummuteButton->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\231\244\347\246\201\350\250\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome to my chatroom!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
