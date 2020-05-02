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
#include <QIcon>



#include "gui/buttontool.h"





ButtonTool::ButtonTool(QWidget *parent):QPushButton(parent){

    this->setCheckable(false);
    this->setFlat(true);


this->setStyleSheet(QString::fromUtf8("QPushButton {\n"
                                      "width: 20px;\n"
                                      "height: 20px;\n"
                                      "border: 1px solid #ffffff;\n"
                                      "background-color: none;}\n"

                                      "QPushButton:checked {\n"
                                      "background: #007ad9;}\n"

                                      "QPushButtonr:unchecked:hover{\n"
                                      "background: #007ad9;}\n"

                                      "QPushButton:pressed {\n"
                                      "background-color: #007ad9;}\n"



                                       ));






}







ButtonTool::~ButtonTool(){}






void ButtonTool::SetIcon(QString file){

    QIcon icon;
    icon.addFile(":/PlayerItem/icons/"+file, QSize(), QIcon::Normal, QIcon::Off);
    this->setIcon(icon);


}

//-------------------------------
void ButtonTool:: SetToolTip(QString text){

 this->setToolTip(text);




}









