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
#include <QHBoxLayout>
#include <QSpacerItem>


#include "gui/frameplayerslider.h"





FramePlayerSlider::FramePlayerSlider(QWidget *parent):FrameBase(parent){



    slider =new Slider(this);
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(9, 3, 9, 3); //ajuste de la botonera




    horizontalLayout->addWidget(slider);



    // espaciador
     QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);// espaciador para tirar a la izquerda
    // horizontalLayout->addItem(horizontalSpacer);




}







FramePlayerSlider::~FramePlayerSlider(){}






