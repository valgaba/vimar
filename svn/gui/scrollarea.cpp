
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
#include <QWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QUrl>


#include "gui/scrollarea.h"
#include "gui/audioitem.h"
#include "simplewidget.h"
#include "gui/frameplayernav.h"
#include "gui/player.h"

#include "engine/StreamFile.h"
#include "engine/StreamMath.h"

ScrollArea::ScrollArea(QWidget *parent):QScrollArea(parent){

     botonoff="QPushButton {\n"
                           "width: 20px;\n"
                           "height: 20px;\n"
                           "border: 1px solid #ffffff;\n"
                           "background-color: none;\n"
                           "color:#ffffff;}\n"

                           "QPushButton:hover {\n"
                           "border: 1px solid #007ad9;}\n";

    botonon="QPushButton {\n"
                           "width: 20px;\n"
                           "height: 20px;\n"
                           "border: 1px solid #ffffff;\n"
                           "background-color: #f8485d;\n"
                           "color:#ffffff;}\n";










    streamrender = new StreamRender();
   //streamrender->setEncadenar(true);

    connect(streamrender,SIGNAL(Finish()),this, SLOT(streamfinal()));
    defaultaudioitem= NULL;


   this->setAcceptDrops(true);

    this->setWidgetResizable(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QWidget * scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 665, 386));
    this->setWidget(scrollAreaWidgetContents);

    verticalLayoutArea = new QVBoxLayout(scrollAreaWidgetContents);
    verticalLayoutArea->setContentsMargins(0, 3, 0, 0);
    verticalLayoutArea->setSpacing(3); //espacios entre adioiten

    this->setStyleSheet("QScrollBar:vertical {background-color: rgb(52, 52, 52); width: 5px; }\n"
                              "QScrollBar::handle:vertical{ background-color: rgb(255, 255, 255);  height: 5px; width: 2px;}\n"
                              "QScrollBar::add-page, QScrollBar::sub-page {background: none; }"
                         );




    verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutArea->addItem(verticalSpacer); // add area







}







ScrollArea::~ScrollArea(){}



void ScrollArea::dragEnterEvent(QDragEnterEvent *event){

//qDebug()<< event->mimeData()->text();

    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();

    if (event->mimeData()->hasFormat("text/plain"))
         event->acceptProposedAction();



}



/*void ScrollArea::dragMoveEvent(QDragMoveEvent *event){


 event->acceptProposedAction();


  // qDebug()<< event->pos();
//qDebug()<< event->pos().y()/100;

event->source()->cla


//int pos=event->pos().y()/100;


//qDebug()<< this->frameSize().height();
//QWidget *widget = verticalLayoutArea->itemAt(pos)->widget();

//widget->setStyleSheet(QString::fromUtf8("QWidget{color: #007ad9;}\n"

                                   //   ));





}*/








//**********************************************************
void ScrollArea::dropEvent(QDropEvent *event){

QUrl url;
     QList<QUrl> urls = event->mimeData()->urls();


     url=event->mimeData()->text();

     AudioItem* source = qobject_cast<AudioItem*>(event->source());



    if(source !=NULL){  //se ha arrastrado desde otro reproductor un audioitem

        if(IsDuplicateItem(source))
            return;

        verticalLayoutArea->removeItem(verticalSpacer);
        AudioItem * audioitem = new AudioItem(this);
        audioitem->setUrl(source->Url());
        audioitem->label_titulo->setText(source->label_titulo->text());
        audioitem->label_tiempo->setText(source->label_tiempo->text());
        audioitem->setSecond(source->Second());
        connect(audioitem->BtnPlay,SIGNAL(clicked()),this, SLOT(ClickBtnLoadPlay()));
       // connect(audioitem,SIGNAL(clickedItem()),this, SLOT(ClickItem()));

        verticalLayoutArea->addWidget(audioitem);
        verticalLayoutArea->addItem(verticalSpacer); // add area
      return;

    }

    verticalLayoutArea->removeItem(verticalSpacer);



    for (int i = 0; i < urls.size(); ++i) {

         StreamFile * streamfile =new StreamFile();
         streamfile->setDevice(1);
         streamfile->setUrl( urls[i].toLocalFile());


              if(streamfile->stream !=0){ // si es un fichero de audio valido
                      StreamMath * streammath = new StreamMath(streamfile->stream);

                      AudioItem * audioitem = new AudioItem(this);
                      audioitem->setSecond(streammath->Duracion());
                      audioitem->label_tiempo->setText(streammath->SegundoToFormato());
                      audioitem->setUrl(urls[i].toLocalFile());
                      connect(audioitem->BtnPlay,SIGNAL(clicked()),this, SLOT(ClickBtnLoadPlay()));
                     // connect(audioitem,SIGNAL(clickedItem()),this, SLOT(ClickItem()));

                      verticalLayoutArea->addWidget(audioitem);
                      delete streammath;
              }

              delete streamfile;

       }



         verticalLayoutArea->addItem(verticalSpacer); // add area


}

//--------------------------------------------------------

void ScrollArea::Recorrer(AudioItem * audioitem){


      for (int i = 0; i < verticalLayoutArea->count(); ++i){
             QWidget *widget = verticalLayoutArea->itemAt(i)->widget();
             if (widget != NULL){

                     if(audioitem==widget)
                        qDebug()<< widget->metaObject()->className();

               }


}

}



// evita que se dupliquen los audioitem en el mismo scroolarea
//-------------------------------------------------------------


bool ScrollArea::IsDuplicateItem(AudioItem * audioitem){


    for (int i = 0; i < verticalLayoutArea->count(); ++i){
           QWidget *widget = verticalLayoutArea->itemAt(i)->widget();

           if (widget != NULL && audioitem==widget) {
                return true;
              }

        }


       return false;




}

//---------------------------------------------------------

void ScrollArea::IsDisable(bool disabel){


    for (int i = 0; i < verticalLayoutArea->count(); ++i){
           QWidget *widget = verticalLayoutArea->itemAt(i)->widget();

           if (widget != NULL )
               widget->setDisabled(disabel);



   }


}
//-----------------------------------
void ScrollArea::ClickBtnLoadPlay(){ // cargamos audio y reproducimos el item

    QPushButton *item = qobject_cast< QPushButton*>(sender());
    AudioItem * audioitem = (AudioItem *)item->parent()->parent()->parent(); // encontramos el item

    Player *player=(Player*)audioitem->parent()->parent()->parent()->parent(); //todo esto para quitar el checked del pause
    player->frameplayernav->btnPause->setChecked(false);

    streamrender->setNext(audioitem->Url()); // cargamos el fichero

    audioitem->setNext(false); // quitamos el siguiente si estuviera activado
    audioitem->BtnNext->setChecked(false);

 if(defaultaudioitem !=NULL){ // si no es nulo cambiamos el color del play
    defaultaudioitem->BtnPlay->setStyleSheet(botonoff);
    defaultaudioitem->setPlaying(false); // esta sonando a off
 }


    defaultaudioitem =audioitem; // guardamos el que está sonando

    defaultaudioitem->BtnPlay->setStyleSheet(botonon);
    defaultaudioitem->setPlaying(true);



}

void ScrollArea::ClickBtnStop(){

   if(BASS_ChannelIsActive(streamrender->stream)==0)
     return;

   defaultaudioitem->BtnPlay->setStyleSheet(botonoff);
   defaultaudioitem->setPlaying(false);

    QPushButton *item = qobject_cast< QPushButton*>(sender()); // todo esto para quitar el color azul del pause
    FramePlayerNav *frameplayernav =(FramePlayerNav *)item->parent(); // cogemos el padre del boton
    frameplayernav->btnPause->setChecked(false);
    defaultaudioitem =NULL;

    streamrender->Stop();

}

void ScrollArea::ClickBtnPlay(){ //play despues de pause


   // if(!streamrender->stream) // si no está en pause no hay ningun stream cargado
       // return;

QPushButton *item = qobject_cast< QPushButton*>(sender()); // todo esto para quitar el color azul del pause
FramePlayerNav *frameplayernav =(FramePlayerNav *)item->parent(); // cogemos el padre del boton
frameplayernav->btnPause->setChecked(false); // quitamos el pause

if( BASS_ChannelIsActive(streamrender->stream)==3){// esta en pause
    streamrender->Play();
     return;
}





}

void ScrollArea::ClickBtnPause(){


    QPushButton *item = qobject_cast< QPushButton*>(sender()); // todo esto para quitar el color azul del pause
    FramePlayerNav *frameplayernav =(FramePlayerNav *)item->parent(); // cogemos el padre del boton

    if(BASS_ChannelIsActive(streamrender->stream)==0){
       frameplayernav->btnPause->setChecked(false);
      return;
    }

   if( BASS_ChannelIsActive(streamrender->stream)==3){// esta en pause
        ClickBtnPlay();
        return;
   }

    streamrender->Pause();
}

void ScrollArea::ClickItem(){

    AudioItem *item = qobject_cast< AudioItem*>(sender()); // todo esto para quitar el color azul del pause


     item->BtnPlay->animateClick();


}





// señal procedente de stremrender ha finalizado el audio

void ScrollArea::streamfinal(){


     defaultaudioitem->BtnPlay->setStyleSheet(botonoff);
     defaultaudioitem->setPlaying(false);


    if (defaultaudioitem->Loop()){ //loop activado vuelve a reproducir
          defaultaudioitem->BtnPlay->animateClick();
          return;
    }




    if (defaultaudioitem->Purge()){ // esta puge activado borramos item
          delete defaultaudioitem;


        }

           getNext(); // buscar si hay algun siguiente activado



}

void ScrollArea::getNext(){


    for (int i = 0; i < verticalLayoutArea->count(); ++i){
         AudioItem *item = (AudioItem*)verticalLayoutArea->itemAt(i)->widget();

            if (item != NULL ){
                 // qDebug() << item->Next();
                  if(item->Next()){

                      defaultaudioitem=item;
                      defaultaudioitem->BtnPlay->animateClick();
                      return;
                  }



            }

    }






}



