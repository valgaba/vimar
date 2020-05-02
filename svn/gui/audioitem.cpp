
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

#include "gui/audioitem.h"

AudioItem::AudioItem(QWidget *parent):QFrame(parent){

setupUi(this);

    this->setCursor(QCursor(Qt::PointingHandCursor));  //cambiamos el cursor
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Plain);
    this->setLineWidth(1); //grosor de linea

    this->setMinimumSize(QSize(200, 85));      //minimo que ocupa el itemaudio
    this->setMaximumSize(QSize(16777215, 85)); //maxima que ocupa el itenaudio

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








