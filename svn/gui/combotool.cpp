
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
#include <QComboBox>
#include <QFont>

#include "gui/combotool.h"





ComboTool::ComboTool(QWidget *parent):QFrame(parent){

    this->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 59, 79);\n"
  "color: rgb(255, 255, 255);\n"
  ""));




    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
         sizePolicy.setHorizontalStretch(0);
         sizePolicy.setVerticalStretch(0);
         sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
         this->setSizePolicy(sizePolicy);




  QHBoxLayout * horizontalLayout = new QHBoxLayout(this);
          horizontalLayout->setSpacing(0);
          horizontalLayout->setContentsMargins(0, 0, 0, 0);

          comboBox = new QComboBox(this);




                QFont font;
                font.setPointSize(8);
                font.setBold(true);
                font.setWeight(75);
                comboBox->setFont(font);


          comboBox->insertItems(0, QStringList()
                  << QApplication::translate("Form", "qqewewewew", 0, QApplication::UnicodeUTF8)
                  << QApplication::translate("Form", "wewewewewew", 0, QApplication::UnicodeUTF8)
                  << QApplication::translate("Form", "ewewewewew", 0, QApplication::UnicodeUTF8)
                 );


          comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"

        "     height: 20px;\n"
        "     border: 1px solid #ffffff;\n"
        "    background-color: rgb(51, 59, 79);\n"
        "   color:#ffffff;\n"
        "}\n"
        ""));



           horizontalLayout->addWidget(comboBox);







}







ComboTool::~ComboTool(){}











