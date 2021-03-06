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




#include "gui/labelbase.h"





LabelBase::LabelBase(QWidget *parent):QLabel(parent){

  this->setAlignment(Qt::AlignCenter);
    QFont font;
         font.setPointSize(10);
         font.setBold(true);
         font.setWeight(75);
         this->setFont(font);








this->setStyleSheet(QString::fromUtf8("padding: 2px;\n"
                                      "border-radius: 0px;\n"
                                      "border: 1px solid #ffffff;\n"
                                      "color: rgb(255, 255, 255);\n"
                                      "background-color: none;\n"

                                      "QToolTip{color:#ffffff;\n"
                                      "background-color: rgb(51, 59, 79);\n"
                                      " border: 1px solid #ffffff;}\n"

                                       ));






}











LabelBase::~LabelBase(){}


