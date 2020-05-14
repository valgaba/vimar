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


#include "gui/frameplayernav.h"





FramePlayerNav::FramePlayerNav(QWidget *parent):FrameBase(parent){


    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(9, 3, 9, 3); //ajuste de la botonera



    btnPlay = new ButtonTool(this);
    btnPlay->setIconSize(QSize(30, 30));
    btnPlay->setMinimumSize(50,30);
    btnPlay->SetIcon("Play.svg");
    btnPlay->SetToolTip("Continua la reproducción del item");
    horizontalLayout->addWidget(btnPlay);

    btnPause = new ButtonTool(this);
    btnPause->setCheckable(true);
    btnPause->setIconSize(QSize(30, 30));
    btnPause->setMinimumSize(50,30);
    btnPause->SetIcon("Pause.svg");
    btnPause->SetToolTip("Pausa del item");
    horizontalLayout->addWidget(btnPause);

    btnStop = new ButtonTool(this);
    btnStop->setIconSize(QSize(30, 30));
    btnStop->setMinimumSize(50,30);
    btnStop->SetIcon("Stop.svg");
    btnStop->SetToolTip("Stop del item");
    horizontalLayout->addWidget(btnStop);


    // espaciador
     QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);// espaciador para tirar a la izquerda
     horizontalLayout->addItem(horizontalSpacer);

      labelcount = new LabelCount(this);
      horizontalLayout->addWidget(labelcount);

}







FramePlayerNav::~FramePlayerNav(){}




