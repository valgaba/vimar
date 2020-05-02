/********************************************************************************
** Form generated from reading UI file 'AudioItem.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOITEM_H
#define UI_AUDIOITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Base
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_left;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QSlider *slider;
    QFrame *frame_right;
    QVBoxLayout *verticalLayout;
    QFrame *frame_tool;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QFrame *frame_info;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_titulo;
    QLabel *label_tiempo;

    void setupUi(QWidget *Base)
    {
        if (Base->objectName().isEmpty())
            Base->setObjectName(QString::fromUtf8("Base"));
        Base->resize(511, 127);
        Base->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 37, 49);"));
        verticalLayout_4 = new QVBoxLayout(Base);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame = new QFrame(Base);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 58, 58);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_left = new QFrame(frame);
        frame_left->setObjectName(QString::fromUtf8("frame_left"));
        frame_left->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 37, 49);"));
        frame_left->setFrameShape(QFrame::StyledPanel);
        frame_left->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_left);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_4 = new QPushButton(frame_left);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background-color: none;\n"
"   color:#ffffff;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #007ad9;\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007ad9;\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PlayerItem/icons/Play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(pushButton_4);

        slider = new QSlider(frame_left);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: none;\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #ffffff;\n"
" \n"
"    width:18px;\n"
"    margin: -1px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 5px;\n"
"}"));
        slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider);


        horizontalLayout->addWidget(frame_left);

        frame_right = new QFrame(frame);
        frame_right->setObjectName(QString::fromUtf8("frame_right"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_right->sizePolicy().hasHeightForWidth());
        frame_right->setSizePolicy(sizePolicy);
        frame_right->setFrameShape(QFrame::StyledPanel);
        frame_right->setFrameShadow(QFrame::Raised);
        frame_right->setLineWidth(1);
        verticalLayout = new QVBoxLayout(frame_right);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_tool = new QFrame(frame_right);
        frame_tool->setObjectName(QString::fromUtf8("frame_tool"));
        sizePolicy.setHeightForWidth(frame_tool->sizePolicy().hasHeightForWidth());
        frame_tool->setSizePolicy(sizePolicy);
        frame_tool->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 37, 49);\n"
"color: rgb(0, 0, 0);"));
        frame_tool->setFrameShape(QFrame::Box);
        frame_tool->setLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(frame_tool);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(frame_tool);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background-color: none;\n"
"   color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #16bb3d;\n"
"   \n"
"}\n"
"\n"
"QPushButtonr:unchecked:hover  {\n"
"   background: #007ad9;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PlayerItem/icons/Next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setCheckable(true);
        pushButton_5->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton = new QPushButton(frame_tool);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background-color: none;\n"
"   color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #007ad9;\n"
"   \n"
"}\n"
"\n"
"QPushButtonr:unchecked:hover  {\n"
"   background: #007ad9;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PlayerItem/icons/Purge.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setCheckable(true);
        pushButton->setFlat(true);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(frame_tool);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background-color: none;\n"
"   color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #007ad9;\n"
"   \n"
"}\n"
"\n"
"QPushButtonr:unchecked:hover  {\n"
"   background: #007ad9;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PlayerItem/icons/Loop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setCheckable(true);
        pushButton_3->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(frame_tool);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background-color: none;\n"
"   color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"background: #007ad9;\n"
"   \n"
"}\n"
"\n"
"QPushButtonr:unchecked:hover  {\n"
"   background: #007ad9;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #007ad9;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PlayerItem/icons/Remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setCheckable(false);
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);

        checkBox = new QCheckBox(frame_tool);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font;
        font.setPointSize(11);
        checkBox->setFont(font);
        checkBox->setAutoFillBackground(false);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"\n"
"    border: 1px solid #ffffff;\n"
"    background: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background: #007ad9;\n"
"   \n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(checkBox);


        verticalLayout->addWidget(frame_tool);

        frame_info = new QFrame(frame_right);
        frame_info->setObjectName(QString::fromUtf8("frame_info"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(frame_info->sizePolicy().hasHeightForWidth());
        frame_info->setSizePolicy(sizePolicy1);
        frame_info->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 37, 49);"));
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_info);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_titulo = new QLabel(frame_info);
        label_titulo->setObjectName(QString::fromUtf8("label_titulo"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_titulo->setFont(font1);
        label_titulo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_titulo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_titulo);

        label_tiempo = new QLabel(frame_info);
        label_tiempo->setObjectName(QString::fromUtf8("label_tiempo"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_tiempo->setFont(font2);
        label_tiempo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_tiempo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_tiempo);


        verticalLayout->addWidget(frame_info);


        horizontalLayout->addWidget(frame_right);


        verticalLayout_4->addWidget(frame);


        retranslateUi(Base);

        QMetaObject::connectSlotsByName(Base);
    } // setupUi

    void retranslateUi(QWidget *Base)
    {
        Base->setWindowTitle(QApplication::translate("Base", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Base", "Activar el Loop\n"
"Hace que el track se repita indefinidamente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Base", "<html><head/><body><p>Activar Purge</p><p>Elimina el track una vez reproducido</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Base", "Activar el Loop\n"
"Hace que el track se repita indefinidamente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Base", "Activar el Loop\n"
"Hace que el track se repita indefinidamente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("Base", "<html><head/><body><p>Selecciona el Item</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_titulo->setText(QApplication::translate("Base", "texto", 0, QApplication::UnicodeUTF8));
        label_tiempo->setText(QApplication::translate("Base", "00:00:00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Base: public Ui_Base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOITEM_H
