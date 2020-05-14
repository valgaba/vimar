
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
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QFileInfo>



#include "gui/audioitem.h"

AudioItem::AudioItem(QWidget *parent):QFrame(parent){

 setupUi(this);
 isLoop   = false;
 isPurge  = false;
 isNext   = false;
 isSelect = false;
 isplaying= false;

 //this->setAcceptDrops(true);
   connect(this->BtnDelete,SIGNAL(clicked()),this, SLOT(ClickBtnDelete()));
   connect(this->BtnLoop,SIGNAL(clicked()),this, SLOT(ClickBtnLoop()));
   connect(this->BtnPurge,SIGNAL(clicked()),this, SLOT(ClickBtnPurge()));
   connect(this->CheckSelect,SIGNAL(clicked()),this, SLOT(ClickBtnSelect()));
   connect(this->BtnNext,SIGNAL(clicked()),this, SLOT(ClickBtnNext()));


    this->setCursor(QCursor(Qt::PointingHandCursor));  //cambiamos el cursor
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Plain);
    this->setLineWidth(1); //grosor de linea

   this->setMinimumSize(QSize(200, 100));      //minimo que ocupa el itemaudio
   this->setMaximumSize(QSize(16777215, 100)); //maxima que ocupa el itenaudio

        this->label_titulo->setWordWrap(true); //hace el labal miltilinea
    //this->label_titulo->setMaximumSize(QSize(250, 100)); //maxima que ocupa el boton*/


         // this->setGeometry(QRect(130, 110, 311, 121));
         //  this->setAcceptDrops(true);


    this->setStyleSheet(QString::fromUtf8("QWidget{background-color: rgb(70, 70, 70);}\n"
                                          "QWidget:hover{color: #007ad9;}\n"
                                          "QWidget{color: rgb(0, 0, 0);}\n"
                                          ));








}







AudioItem::~AudioItem(){

}



void AudioItem::resizeEvent(QResizeEvent *event)
{






}



void AudioItem::mousePressEvent(QMouseEvent *event){

if ((event->button() == Qt::LeftButton)){

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("Desde el audio item");
    drag->setMimeData(mimeData);
    drag->exec(Qt::MoveAction);
    return;

 }




}








void AudioItem::dragEnterEvent(QDragEnterEvent *event){



}




//**********************************************************
void AudioItem::dropEvent(QDropEvent *event){





}


void AudioItem::setLoop  (bool value){isLoop=value;}
void AudioItem::setPurge (bool value){isPurge=value;}
void AudioItem::setNext  (bool value){isNext=value;}
void AudioItem::setSelect(bool value){isSelect=value;}
void AudioItem::setPlaying(bool value){this->isplaying=value;}


bool AudioItem::Loop(){return isLoop;}
bool AudioItem::Purge(){return isPurge;}
bool AudioItem::Next(){return isNext;}
bool AudioItem::Select(){return isSelect;}
bool AudioItem::Playing(){return isplaying;}








//******************************************
void AudioItem::ClickBtnDelete(){

    if(isplaying) // si esta reproduciendo no lo borra
       return;

    delete(this);


}



void AudioItem::ClickBtnLoop(){
    isLoop=this->BtnLoop->isChecked();

   BtnPurge->setHidden(BtnLoop->isChecked());
   BtnNext->setHidden(BtnLoop->isChecked());

}


void AudioItem::ClickBtnPurge(){
    isPurge=this->BtnPurge->isChecked();


}

void AudioItem::ClickBtnNext(){
     isNext=this->BtnNext->isChecked();
}

void AudioItem::ClickBtnSelect(){
    isSelect=this->CheckSelect->isChecked();
   // qDebug()<< isSelect;
}


// setes---------------------------------
void AudioItem::setUrl(QString url){

    QFileInfo file=url;

    this->url=url;
    this->label_titulo->setText(file.baseName());

   // qDebug()<< this->url.toLocalFile();
}

QString AudioItem::Url(){return this->url;}

void AudioItem::setSecond(float second){this->second=second;}
float AudioItem::Second(){return this->second;}







/*void AudioItem::mouseMoveEvent(QMouseEvent *event){

    if (!(event->buttons() & Qt::LeftButton))
        return;

    //int pos=event->pos().y()/100;


    //qDebug()<< this->label_titulo->text();

}*/


