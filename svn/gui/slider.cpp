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




#include "gui/slider.h"





Slider::Slider(QWidget *parent):QSlider(parent){

 this->setOrientation(Qt::Horizontal);
    this->setCursor(QCursor(Qt::PointingHandCursor));  //cambiamos el cursor


      // para ver bien los colores del control he cambiado el estylo del padre(algo raro)
    this->parentWidget()->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);" ));






this->setStyleSheet(QString::fromUtf8(" QSlider::groove:horizontal {\n"
                                         "border: 1px solid #ffffff;\n"
                                         "height: 8px;\n"
                                         "background: none;\n"
                                         "margin: 2px 0;\n}"

                                      "QSlider::handle:horizontal {\n"
                                          "background: #ffffff;\n"
                                          "width:18px;\n"
                                          "margin: -1px 0;\n"
                                          "border-radius: 5px;\n}"

                                       ));


}







Slider::~Slider(){}













