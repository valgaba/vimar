
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

#include <QDebug>
#include <QContextMenuEvent>

#include <QDrag>
#include <QClipboard>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QScrollArea>
#include <QUrl>
#include <QSpacerItem>
#include <QScrollBar>

#include "player.h"
#include "gui/audioitem.h"
#include "gui/buttontool.h"
#include "gui/combotool.h"

Player::Player(QWidget *parent): QFrame(parent){


    this->setAcceptDrops(true);

    //this->setObjectName(QString::fromUtf8("frame"));
   // this->setGeometry(QRect(190, 130, 691, 471));
      this->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
   // this->setFrameShape(QFrame::StyledPanel);
   // this->setFrameShadow(QFrame::Raised);


   // espacio vertical principal--------------------------------------------------
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
               verticalLayout->setContentsMargins(0, 0, 0, 0);
               verticalLayout->setSpacing(2); //espacios entre adioiten y la botonera



//   espacio  frame horizontal de botonera del player-----------------------

         QFrame *BotonFrame = new QFrame(this);
         BotonFrame ->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);"));
         QHBoxLayout  *horizontalLayout = new QHBoxLayout(BotonFrame );
         horizontalLayout->setContentsMargins(0, 3, 26, 3);


//botonoes del reproductor

         //botones izquierda--------------

         ButtonTool * btnLoad = new ButtonTool(BotonFrame);
         btnLoad->SetIcon("Load.svg");
         btnLoad->SetToolTip("Seleccionar todos");
         horizontalLayout->addWidget(btnLoad);

         ButtonTool * btnSave = new ButtonTool(BotonFrame);
         btnSave->SetIcon("Save.svg");
         btnSave->SetToolTip("Seleccionar todos");
         horizontalLayout->addWidget(btnSave);


        // espaciador
         QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);// espaciador para tirar a la izquerda
         horizontalLayout->addItem(horizontalSpacer);


//botones derecha--------------

                ComboTool *combotool=new ComboTool(BotonFrame);
                horizontalLayout->addWidget(combotool);





               ButtonTool * btnNext = new ButtonTool(BotonFrame);
               btnNext->SetIcon("Next.svg");
               btnNext->SetToolTip("Seleccionar todos");
               horizontalLayout->addWidget(btnNext);


               ButtonTool * btnPurge = new ButtonTool(BotonFrame);
               btnPurge->SetIcon("Purge.svg");
               btnPurge->SetToolTip("Seleccionar todos");
               horizontalLayout->addWidget(btnPurge);



               ButtonTool * btnColor = new ButtonTool(BotonFrame);
               btnColor->SetIcon("Color.svg");
               btnColor->SetToolTip("Cambiar color...");
               horizontalLayout->addWidget(btnColor);


                ButtonTool * btnDelete = new ButtonTool(BotonFrame);
                btnDelete->SetIcon("Remove.svg");
                btnDelete->SetToolTip("Eliminar selecionados");
                horizontalLayout->addWidget(btnDelete);





                ButtonTool * btnSelectAll = new ButtonTool(BotonFrame);
                btnSelectAll->SetIcon("Selectall.svg");
                btnSelectAll->SetToolTip("Seleccionar todos...");
                horizontalLayout->addWidget(btnSelectAll);







       verticalLayout->addWidget(BotonFrame); // add frame al espacio principal botonera



//----------- area cuerpo del reproductor donde van los audioitem

              QScrollArea *scrollArea = new QScrollArea(this);
              scrollArea->setWidgetResizable(true);
              scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
              scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


              QWidget * scrollAreaWidgetContents = new QWidget();
              scrollAreaWidgetContents->setGeometry(QRect(0, 0, 665, 386));
              scrollArea->setWidget(scrollAreaWidgetContents);
              verticalLayoutArea = new QVBoxLayout(scrollAreaWidgetContents);
              verticalLayoutArea->setContentsMargins(0, 3, 0, 0);
              verticalLayoutArea->setSpacing(3); //espacios entre adioiten

              scrollArea->setStyleSheet("QScrollBar:vertical {background-color: rgb(52, 52, 52); width: 5px; }\n"
                                        "QScrollBar::handle:vertical{ background-color: rgb(255, 255, 255);  height: 5px; width: 2px;}\n"
                                        "QScrollBar::add-page, QScrollBar::sub-page {background: none; }"
                                         );


      verticalLayout->addWidget(scrollArea); // add frame al espacio area cuerpo


              verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
              verticalLayoutArea->addItem(verticalSpacer); // add area




//---------------------------------------


                //qDebug("BIOS_version:");



}







Player::~Player(){}





void Player::dragEnterEvent(QDragEnterEvent *event){


    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();

    if (event->mimeData()->hasFormat("text/plain"))
         event->acceptProposedAction();



}


void Player::dropEvent(QDropEvent *event){


verticalLayoutArea->removeItem(verticalSpacer);

QUrl url;
     QList<QUrl> urls = event->mimeData()->urls();

    /*if (!urls.isEmpty()){
         url=urls.first().toLocalFile();

       // return;
    }*/

    url=event->mimeData()->text();


    for (int i = 0; i < urls.size(); ++i) {
          //  qDebug()<< urls[i].toLocalFile();
              AudioItem * audioitem = new AudioItem(this);
              audioitem->label_titulo->setText(urls[i].toLocalFile());
              verticalLayoutArea->addWidget(audioitem);


       }



         verticalLayoutArea->addItem(verticalSpacer); // add area


}

void Player::resizeEvent(QResizeEvent *event)
{


}









 /*QScrollBar {

         ;
    background-color: rgb(52, 52, 52);
height: 15px;


     }

     QScrollBar::handle{
    background-color: rgb(255, 255, 255);

         min-width: 20px;
     }


QScrollBar::add-page, QScrollBar::sub-pagel {
         background: none;
     }

 QScrollBar::add-pagel, QScrollBar::sub-page {
         background: none;
     }*/













