/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter_principal;
    QSplitter *splitter_2;
    QFrame *frame_up_left;
    QFrame *frame_up_right;
    QSplitter *splitter;
    QFrame *frame_left;
    QFrame *frame_center;
    QFrame *frame_right;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(738, 544);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PlayerItem/icons/radit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        splitter_principal = new QSplitter(centralwidget);
        splitter_principal->setObjectName(QString::fromUtf8("splitter_principal"));
        splitter_principal->setGeometry(QRect(80, 60, 561, 391));
        splitter_principal->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_principal);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame_up_left = new QFrame(splitter_2);
        frame_up_left->setObjectName(QString::fromUtf8("frame_up_left"));
        frame_up_left->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        frame_up_left->setFrameShape(QFrame::StyledPanel);
        frame_up_left->setFrameShadow(QFrame::Raised);
        splitter_2->addWidget(frame_up_left);
        frame_up_right = new QFrame(splitter_2);
        frame_up_right->setObjectName(QString::fromUtf8("frame_up_right"));
        frame_up_right->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        frame_up_right->setFrameShape(QFrame::StyledPanel);
        frame_up_right->setFrameShadow(QFrame::Raised);
        splitter_2->addWidget(frame_up_right);
        splitter_principal->addWidget(splitter_2);
        splitter = new QSplitter(splitter_principal);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame_left = new QFrame(splitter);
        frame_left->setObjectName(QString::fromUtf8("frame_left"));
        frame_left->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        frame_left->setFrameShape(QFrame::StyledPanel);
        frame_left->setFrameShadow(QFrame::Raised);
        splitter->addWidget(frame_left);
        frame_center = new QFrame(splitter);
        frame_center->setObjectName(QString::fromUtf8("frame_center"));
        frame_center->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        frame_center->setFrameShape(QFrame::StyledPanel);
        frame_center->setFrameShadow(QFrame::Raised);
        splitter->addWidget(frame_center);
        frame_right = new QFrame(splitter);
        frame_right->setObjectName(QString::fromUtf8("frame_right"));
        frame_right->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        frame_right->setFrameShape(QFrame::StyledPanel);
        frame_right->setFrameShadow(QFrame::Raised);
        splitter->addWidget(frame_right);
        splitter_principal->addWidget(splitter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vimar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
