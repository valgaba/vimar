

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
#include <QProgressBar>


#include "gui/dialogprogressbar.h"





DialogProgressBar::DialogProgressBar(QWidget *parent):DialogBase(parent){



   QVBoxLayout *verticalLayout = new QVBoxLayout(this);

          progressbar = new QProgressBar(this);
         // label = new LabelBase(this);
          progressbar->setMaximum(0);

          progressbar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
                                               "border: 1px solid white;\n"
                                               "border-radius: 0px;\n"
                                               " background-color: rgb(51, 59, 79);}\n"
                                               "QProgressBar::chunk {\n"
                                               "background-color: white;\n"
                                               "width: 20px;}\n"
                                                 ));





         // progressbar->setValue(24);

          verticalLayout->addWidget(progressbar);
         // verticalLayout->addWidget(label);






}







DialogProgressBar::~DialogProgressBar(){}



void DialogProgressBar::setMax(int valor){

    progressbar->setMaximum(valor);
}

void DialogProgressBar::setValor(int valor){
    progressbar->setValue(valor);

}

void DialogProgressBar::setInfo(QString info){

    label->setText(info);
}
