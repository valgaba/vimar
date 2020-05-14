
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


#include <QVBoxLayout>
#include <QSpacerItem>
#include <QLabel>

#include"bass.h"

#include "gui/dialogplayertool.h"
#include "gui/labelbase.h"

DialogPlayerTool::DialogPlayerTool(QWidget *parent):FrameBase(parent){

 //setupUi(this);

 this->setMaximumSize(300,300);


    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setContentsMargins(9, 3, 9, 3); //ajuste de la botonera
    QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    LabelBase *label_dispositivo = new LabelBase ();
    label_dispositivo->setText(QString::fromUtf8("Dispositivo de reproducción"));



    combotool = new ComboTool(this);


verticalLayout->addWidget(label_dispositivo);

       verticalLayout->addWidget(combotool);

       verticalLayout->addItem(verticalSpacer);

       AddDispositivo();



}







DialogPlayerTool::~DialogPlayerTool(){

}



//--------------------------------------------
void DialogPlayerTool::AddDispositivo(){

    BASS_DEVICEINFO i;
        QString nombre;

        QString nulo(tr("Sin Sonido")); //añadimos nulo

       combotool->comboBox->addItem(nulo);

        #ifdef Q_OS_UNIX
          //  QString def(tr("Defecto")); //en linux añadimos otro el default
          //  this->Dispositivo->addItem(def);
        #endif


     //****************** añadimos las tarjetas de audio *****************************
        for (int c=1;BASS_GetDeviceInfo(c,&i);c++)// device 1 = el primer dispositivo
        {
           if (i.flags&BASS_DEVICE_ENABLED){
                    combotool->comboBox->addItem(nombre.fromAscii(i.name));

              }
        }


}



int DialogPlayerTool::getDriver(){
    driver=combotool->comboBox->currentIndex();
    return this->driver;
}






