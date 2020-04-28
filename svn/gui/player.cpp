
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

#include<QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QScrollArea>


#include "player.h"


Player::Player(QWidget *parent): QFrame(parent){


    //this->setObjectName(QString::fromUtf8("frame"));
   // this->setGeometry(QRect(190, 130, 691, 471));
    this->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 44, 59);"));
   // this->setFrameShape(QFrame::StyledPanel);
   // this->setFrameShadow(QFrame::Raised);

  QVBoxLayout *verticalLayout = new QVBoxLayout(this);
      //  verticalLayout->setContentsMargins(0, 0, 0, 0);
 verticalLayout->setContentsMargins(0, 0, 0, 0);
         QFrame *BotonFrame = new QFrame(this);
         BotonFrame ->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);"));
        // BotonFrame->setGeometry(QRect(11, 11, 821, 541));

       QHBoxLayout  *horizontalLayout = new QHBoxLayout(BotonFrame );
       horizontalLayout->setContentsMargins(0, 3, 0, 3);

       QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);// espaciador para tirar a la izquerda

         horizontalLayout->addItem(horizontalSpacer);


//botonoes del reproductor

                QPushButton * pushButton = new QPushButton(BotonFrame);
                pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(147, 147, 147);"));
                pushButton->setText("asdsddssdsdsdsd");
                horizontalLayout->addWidget(pushButton);

                QPushButton * pushButton2 = new QPushButton(BotonFrame);
                pushButton2->setStyleSheet(QString::fromUtf8("background-color: rgb(147, 147, 147);"));
                pushButton2->setText("asdsddssdsdsdsd");
                horizontalLayout->addWidget(pushButton2);





                verticalLayout->addWidget(BotonFrame);


              QScrollArea *scrollArea = new QScrollArea(this);
              scrollArea->setWidgetResizable(true);
              scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

              QWidget * scrollAreaWidgetContents = new QWidget();
              scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
              scrollAreaWidgetContents->setGeometry(QRect(0, 0, 665, 386));
              scrollArea->setWidget(scrollAreaWidgetContents);

              verticalLayout->addWidget(scrollArea);






                //qDebug("BIOS_version:");



}







Player::~Player(){

}






