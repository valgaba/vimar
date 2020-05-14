/* This file is part of IRadit.
   Copyright 2020, Victor Algaba <victor@radit.org> www.radit.org

   IRadit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Iradit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Iradit.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>

#include "bass.h"

#include "gui/player.h"

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    IniAudio(); // abrimos el audio



// espacio general---------------------------------
        this->resize(1247, 822);
        ui->splitter->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);"));
        ui->splitter->setHandleWidth(1);


       QVBoxLayout  *verticalLayout = new QVBoxLayout(ui->centralwidget); //espacio global vertical
                     verticalLayout->setSpacing(0);
                     verticalLayout->setContentsMargins(0, 0, 0, 0);
                     verticalLayout->addWidget(ui->splitter_principal);



// zona de player parte baja 3 espacios--------------------------------------

          QVBoxLayout  *verticalLayout_left = new QVBoxLayout(ui->frame_left); //zona detrecha
                        verticalLayout_left->setSpacing(0);
                        verticalLayout_left->setContentsMargins(0, 0, 0, 0);

                        Player *player1= new Player(ui->frame_left);
                        verticalLayout_left->addWidget(player1);



          QVBoxLayout  *verticalLayout_center = new QVBoxLayout(ui->frame_center); // zona centro
                        verticalLayout_center->setSpacing(0);
                        verticalLayout_center->setContentsMargins(0, 0, 0, 0);


                         Player *player2= new Player(ui->frame_center);
                         verticalLayout_center->addWidget(player2);


          QVBoxLayout  *verticalLayout_right = new QVBoxLayout(ui->frame_right); //zona izquierda
                        verticalLayout_right->setSpacing(0);
                        verticalLayout_right->setContentsMargins(0, 0, 0, 0);

                        Player *player3= new Player(ui->frame_right);
                        verticalLayout_right->addWidget(player3);


// zona parte alta--- 2 espacios-----------------------------------------------

         QVBoxLayout  *verticalLayout_up_left = new QVBoxLayout(ui->frame_up_left); // zona alta izquierda
                       verticalLayout_up_left->setSpacing(0);
                       verticalLayout_up_left->setContentsMargins(0, 0, 0, 0);

                      // Player *player4= new Player(ui->frame_up_left);
                     //  verticalLayout_up_left->addWidget(player4);



          QVBoxLayout  *verticalLayout_up_right = new QVBoxLayout(ui->frame_up_right); // zona alta derecha
                        verticalLayout_up_right->setSpacing(0);
                        verticalLayout_up_right->setContentsMargins(0, 0, 0, 0);

                       // Player *player5= new Player(ui->frame_up_right);
                        //verticalLayout_up_right->addWidget(player5);







}

MainWindow::~MainWindow()
{
    delete ui;
}


//------------------------------------------
void MainWindow::IniAudio(){

    BASS_DEVICEINFO i;


    //bass configuration
    BASS_SetConfig(BASS_CONFIG_BUFFER, 5000 );
    // BASS_SetConfig(BASS_CONFIG_UPDATEPERIOD, 10);
    BASS_SetConfig(BASS_CONFIG_NET_PLAYLIST,1); // enable playlist processing

    // plugin

    BASS_PluginFree(0);
    QString Path=QCoreApplication::applicationDirPath().toLatin1();

    #ifdef _WIN32
        BASS_PluginLoad(Path.toLatin1() + "/Plugin/bass_aac.dll",0);
        BASS_PluginLoad(Path.toLatin1() + "/Plugin/bassflac.dll",0);
        BASS_PluginLoad(Path.toLatin1() + "/Plugin/basswma.dll",0);
    #endif


    #ifdef Q_OS_UNIX
        BASS_PluginLoad(Path.toLatin1() + "/Plugin/libbass_aac.so",0);
        BASS_PluginLoad(Path.toLatin1() + "/Plugin/libbassflac.so",0);
    #endif



        #ifdef Q_OS_UNIX
          //  QString def(tr("Defecto")); //en linux añadimos otro el default
          //  this->Dispositivo->addItem(def);
        #endif


     //****************** Abrimmos dispositivos de audio *****************************
        for (int c=1;BASS_GetDeviceInfo(c,&i);c++)// device 1 = el primer dispositivo
        {
           if (i.flags&BASS_DEVICE_ENABLED){
                 BASS_Init(c, 44100,0, 0, NULL);

              }
        }


}








