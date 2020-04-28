#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>




#include "gui/player.h"

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qDebug("BIOS_version:");

   this->resize(1247, 822);


       ui->splitter->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);"));
       ui->splitter->setHandleWidth(1);

       QVBoxLayout  *verticalLayout = new QVBoxLayout(ui->centralwidget);
                        verticalLayout->setSpacing(0);
                        verticalLayout->setContentsMargins(0, 0, 0, 0);

            verticalLayout->addWidget(ui->splitter_3);


//verticalLayout->addWidget(ui->MainWindow);

       QVBoxLayout  *verticalLayout_left = new QVBoxLayout(ui->frame_left);
                        verticalLayout_left->setSpacing(0);
                        verticalLayout_left->setContentsMargins(0, 0, 0, 0);

                        Player *player1= new Player(ui->frame_left);
                        verticalLayout_left->addWidget(player1);



        QVBoxLayout  *verticalLayout_center = new QVBoxLayout(ui->frame_center);
                      verticalLayout_center->setSpacing(0);
                      verticalLayout_center->setContentsMargins(0, 0, 0, 0);
                     // ui->frame_center->setLayout(verticalLayout_center);

                      Player *player2= new Player(ui->frame_center);
                      verticalLayout_center->addWidget(player2);


        QVBoxLayout  *verticalLayout_right = new QVBoxLayout(ui->frame_right);
                      verticalLayout_right->setSpacing(0);
                      verticalLayout_right->setContentsMargins(0, 0, 0, 0);

                       Player *player3= new Player(ui->frame_right);
                       verticalLayout_right->addWidget(player3);







}

MainWindow::~MainWindow()
{
    delete ui;
}
