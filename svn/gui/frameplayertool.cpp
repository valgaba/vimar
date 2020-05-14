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


#include "gui/frameplayertool.h"





FramePlayerTool::FramePlayerTool(QWidget *parent):FrameBase(parent){


    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setContentsMargins(0, 3, 9, 3); //ajuste de la botonera


    btnNew = new ButtonTool(this);
    btnNew->SetIcon("New.svg");
    btnNew->SetToolTip("Nueva lista");
    horizontalLayout->addWidget(btnNew);



    btnLoad = new ButtonTool(this);
    btnLoad->SetIcon("Load.svg");
    btnLoad->SetToolTip("Abrir una lista");
    horizontalLayout->addWidget(btnLoad);

    btnSave = new ButtonTool(this);
    btnSave->SetIcon("Save.svg");
    btnSave->SetToolTip("Gurada la lista");
    horizontalLayout->addWidget(btnSave);




    // espaciador
     QSpacerItem * horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);// espaciador para tirar a la izquerda
     horizontalLayout->addItem(horizontalSpacer);




     btnNext = new ButtonTool(this);
     btnNext->SetIcon("Next.svg");
     btnNext->SetToolTip("Seleccionar todos");
     horizontalLayout->addWidget(btnNext);



     btnPurge = new ButtonTool(this);
     btnPurge->SetIcon("Purge.svg");
     btnPurge->SetToolTip("Seleccionar todos");
     horizontalLayout->addWidget(btnPurge);




         btnColor = new ButtonTool(this);
         btnColor->setCheckable(true);
         btnColor->SetIcon("Color.svg");
         btnColor->SetToolTip("Cambiar color...");
         horizontalLayout->addWidget(btnColor);


        btnDelete = new ButtonTool(this);
        btnDelete->SetIcon("Remove.svg");
        btnDelete->SetToolTip("Eliminar selecionados");
        horizontalLayout->addWidget(btnDelete);

      btnSelectAll = new ButtonTool(this);
      btnSelectAll->SetIcon("Selectall.svg");
      btnSelectAll->SetToolTip("Seleccionar todos...");
      btnSelectAll->setCheckable(true);
      horizontalLayout->addWidget(btnSelectAll);


      btnTool = new ButtonTool(this);
      btnTool->setCheckable(true);
      btnTool->SetIcon("Tools.svg");
      btnTool->SetToolTip("Opcciones de reproductor");
      horizontalLayout->addWidget(btnTool);











}







FramePlayerTool::~FramePlayerTool(){}



