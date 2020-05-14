
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

#include <QTextStream>
#include <QFile>
#include <QFileDialog>

#include "player.h"
#include "gui/audioitem.h"
#include "gui/buttontool.h"
#include "gui/combotool.h"
#include "gui/dialogprogressbar.h"





Player::Player(QWidget *parent): QFrame(parent){


   // this->setAcceptDrops(true);

    //this->setObjectName(QString::fromUtf8("frame"));
   // this->setGeometry(QRect(190, 130, 691, 471));
      this->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
   // this->setFrameShape(QFrame::StyledPanel);
   // this->setFrameShadow(QFrame::Raised);


   // espacio vertical principal--------------------------------------------------
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
      verticalLayout->setContentsMargins(0, 0, 0, 0);
      verticalLayout->setSpacing(2); //espacios entre adioiten y la botonera


     frameplayertool = new FramePlayerTool(this); //barra de herramientas netx,purge, loop, open,save...

     connect(frameplayertool->btnNext,SIGNAL(clicked()),this, SLOT(ClickBtnNext()));
     connect(frameplayertool->btnPurge,SIGNAL(clicked()),this, SLOT(ClickBtnPurge()));
     connect(frameplayertool->btnColor,SIGNAL(clicked()),this, SLOT(ClickBtnColor()));
     connect(frameplayertool->btnDelete,SIGNAL(clicked()),this, SLOT(ClickBtnDelete()));
     connect(frameplayertool->btnSelectAll,SIGNAL(clicked()),this, SLOT(ClickBtnSelect()));
     connect(frameplayertool->btnTool,SIGNAL(clicked()),this, SLOT(ClickBtnTool()));

     connect(frameplayertool->btnNew,SIGNAL(clicked()),this, SLOT(ClickNewList()));
     connect(frameplayertool->btnSave,SIGNAL(clicked()),this, SLOT(ClickSaveList()));
     connect(frameplayertool->btnLoad,SIGNAL(clicked()),this, SLOT(ClickLoadList()));


    scrollArea = new ScrollArea(this); // area para los audioitem

    frameplayernav= new FramePlayerNav(this); //barra de botones play, pausa, stop...

    connect(frameplayernav->btnStop,SIGNAL(clicked()),scrollArea, SLOT(ClickBtnStop()));
    connect(frameplayernav->btnPause,SIGNAL(clicked()),scrollArea, SLOT(ClickBtnPause()));
    connect(frameplayernav->btnPlay,SIGNAL(clicked()),scrollArea, SLOT(ClickBtnPlay()));

    scrollArea->streamrender->setLabel(frameplayernav->labelcount);
    scrollArea->streamrender->setDevice(1);

    // scrollArea->streamrender->setSlider(frameplayernav->slider);

    frameplayerslider = new FramePlayerSlider(this);
    scrollArea->streamrender->setSlider(frameplayerslider->slider);


    verticalLayout->addWidget(frameplayertool); // add frame al espacio principal botonera
    verticalLayout->addWidget(frameplayernav); // add frame al espacio principal botonera
    verticalLayout->addWidget(frameplayerslider); // add frame al espacio principal botonera

    verticalLayout->addWidget(scrollArea); // add frame al espacio area cuerpo



//------dialogos del reproductor--------------

   dialogcolor = new DialogColor(this);
   dialogcolor->hide();

   dialogplayertool = new DialogPlayerTool(this);
   dialogplayertool->hide();

}







Player::~Player(){}





void Player::dragEnterEvent(QDragEnterEvent *event){

    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();

    if (event->mimeData()->hasFormat("text/plain"))
         event->acceptProposedAction();



}


void Player::dropEvent(QDropEvent *event){

}

void Player::resizeEvent(QResizeEvent *event)
{


}

//**********botones *****************************************

void Player::ClickBtnSelect(){

     ButtonTool  *clickedButton = qobject_cast<ButtonTool*>(sender());

          if(isEmpty()){ // si las lista esta vacia
              clickedButton->setChecked(false);
          return;

          }


    for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
           AudioItem *widget = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();

           if (widget != NULL ){
                widget->CheckSelect->setChecked(clickedButton->isChecked());
                widget->setSelect(clickedButton->isChecked());
           }

   }





}

//---------------------------------------------------

void Player::ClickBtnDelete(){



 while(isSelect()){  //mientras haya algun seleccionado

    for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
           AudioItem *item = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();
           if (item != NULL){
                 if(item->Select()){

                       if(item->Playing()){ //si esta seleccionado y se esta reproduciendo no lo borra
                           item->setSelect(false);
                           item->CheckSelect->setChecked(false);

                          }else{

                             delete item;
                             delete scrollArea->verticalLayoutArea->itemAt(i)->layout();
                          }

                  }

            }

   }


}

 frameplayertool->btnSelectAll->setChecked(false);



}


void Player::ClickBtnPurge(){

    for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
           AudioItem *widget = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();
           if (widget != NULL){
                // if(widget->Select()){

                     widget->BtnPurge->setChecked(widget->Select());
                     widget->setPurge(widget->Select());

                //  }

            }

   }

uncheckAll();


}



 void Player::ClickBtnNext(){



     for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
            AudioItem *widget = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();
            if (widget != NULL){
                 // if(widget->Select()){

                      widget->BtnNext->setChecked(widget->Select());
                      widget->setNext(widget->Select());

                 //  }

             }

    }

uncheckAll();


 }




void Player::ClickBtnColor(){


    if(dialogcolor->isVisible()){
        dialogcolor->hide();
        return;
    }

    ButtonTool  *clickedButton = qobject_cast<ButtonTool*>(sender());
    connect(dialogcolor->color1,SIGNAL(clicked()),this, SLOT(pinkColor()));
    dialogcolor->setGeometry(clickedButton->geometry().x()-50,clickedButton->geometry().y()+20,150,90);
    dialogcolor->show();


}



//#
void Player::ClickBtnTool(){

    //dialogplayertool->setParent(this->scrollArea);

    if(dialogplayertool->isVisible()){

        this->driver=dialogplayertool->getDriver();
        scrollArea->streamrender->setDevice(this->driver);


        dialogplayertool->hide();
        return;
    }



    dialogcolor->hide(); // cerramos el dialogo del color por elegancia

    ButtonTool  *clickedButton = qobject_cast<ButtonTool*>(sender());

    dialogplayertool->setGeometry(clickedButton->geometry().x()-230,clickedButton->geometry().y()+30,250,300);


    dialogplayertool->show();

}




//----------------utilidades----------------------
//***************************************************************
bool Player::isSelect(){ //si hay algun audioitem seleccionado

    for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
           AudioItem *widget = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();

           if (widget != NULL){
                if(widget->Select()){return true;} // si hay alguno selecionado
           }

    }

          return false;
}



//----------------------------------------------------
bool Player::isEmpty(){ //la lista esta vacia


    if(scrollArea->verticalLayoutArea->count()==1){
         return true;

    }

    return false;

}


void Player::uncheckAll(){ // desmarca todos los audioitem


for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
     AudioItem *widget = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();

     if (widget != NULL ){
          widget->CheckSelect->setChecked(false);
          widget->setSelect(false);
     }

}

    frameplayertool->btnSelectAll->setChecked(false);

}


//-----------------------------

void Player:: pinkColor(){ // coge un color de la paleta de colores
frameplayertool->btnColor->setChecked(false);
    dialogcolor->hide();
 }






//------------------------------------------
 void Player::ClickNewList(){

     if( BASS_ChannelIsActive(this->scrollArea->streamrender->stream) != 0) // evita que se ejecute mientras suena
         return;


         QLayoutItem *child;
         while ((child = scrollArea->verticalLayoutArea->takeAt(0)) != 0) {
             delete child->widget(); // get rid of widget too
             //delete child;
         }



 }



//--------------------------------------------
void Player::ClickSaveList(){


    QString fileName = QFileDialog::getSaveFileName(0, QObject::tr("Guardar"),
                                                        "",
                                                        QObject::tr("Lista (*.lst)"

                                                        ));





//qDebug() <<scrollArea->verticalLayoutArea->count();

    QFile file(fileName);
   // file.remove(); // lo borramos antes sino se añaden
       if(!file.open(QFile::WriteOnly|QFile::Truncate)) {

           return;
       }


       DialogProgressBar *dialogprogressbar= new DialogProgressBar(this);

       int size = scrollArea->verticalLayoutArea->count();

   dialogprogressbar->setMax(size);

       dialogprogressbar->show();



 QTextStream out(&file);


          for (int i = 0; i < scrollArea->verticalLayoutArea->count(); ++i){
               AudioItem *item = (AudioItem*)scrollArea->verticalLayoutArea->itemAt(i)->widget();

               if (item != NULL ){
                            out << item->Url() << "\r\n";
                            out << item->label_titulo->text() << "\r\n";
                            out << item->label_tiempo->text() << "\r\n";
                            out << item->Second() << "\r\n";

               }
                dialogprogressbar->setValor(i);
          }

delete dialogprogressbar;

}

//---------------------------------------------------
void Player::ClickLoadList(){


    if( BASS_ChannelIsActive(this->scrollArea->streamrender->stream) != 0) // evita que se ejecute mientras suena
        return;


    QString fileName = QFileDialog::getOpenFileName(0,
                                                       QObject::tr("Abrir"),
                                                       "",
                                                       QObject::tr("Lista (*.lst)"

                                                                   ));







    QFile file(fileName);
       if(!file.open(QIODevice::ReadOnly)) {

           return;
       }

ClickNewList(); // lo borramos antes
 DialogProgressBar *dialogprogressbar= new DialogProgressBar(this);


       QTextStream in(&file);

 //int size = file.size(); //228
 int size =0;

 while (!in.atEnd()){
     in.readLine();
     size++;

 }
in.seek(0);

 dialogprogressbar->setMax(size);

dialogprogressbar->show();
 int i=4;

       scrollArea->verticalLayoutArea->removeItem(scrollArea->verticalSpacer);
        while (!in.atEnd())
       {


            AudioItem * audioitem = new AudioItem(this);
            audioitem->setUrl(in.readLine());
            audioitem->label_titulo->setText(in.readLine());
            audioitem->label_tiempo->setText(in.readLine());
            float second=in.readLine().toFloat();
            audioitem->setSecond(second);
            connect(audioitem->BtnPlay,SIGNAL(clicked()),scrollArea, SLOT(ClickBtnLoadPlay()));
            scrollArea->verticalLayoutArea->addWidget(audioitem);


            i +=4;
            dialogprogressbar->setValor(i);

       }

        scrollArea->verticalLayoutArea->addItem(scrollArea->verticalSpacer);

file.close();
delete dialogprogressbar;






}









