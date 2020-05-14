

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
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
#include <QApplication>

#include "simplewidget.h"

SimpleWidget::SimpleWidget(QWidget *parent):QWidget(parent){




}







SimpleWidget::~SimpleWidget(){

}


void SimpleWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if (!IsMinimumDistanceRiched(event))
    {
        return;
    }
    int y = event->globalY() - mouseClickY + oldY;
    int BottomBorder = this->parentWidget()->geometry().height() - this->geometry().height();
    if(y < 0) y = 0;
    else if(y > BottomBorder) y = BottomBorder;
    move(oldX, y);
}

void SimpleWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
        dragStartPosition = event->pos();
    oldX = this->geometry().x();
    oldY = this->geometry().y();
    mouseClickX = event->globalX();
    mouseClickY = event->globalY();
}

bool SimpleWidget::IsMinimumDistanceRiched(QMouseEvent *event)
{
    return (event->pos() - dragStartPosition).manhattanLength() >= QApplication::startDragDistance();
}

bool SimpleWidget::moveInLayout(QWidget *widget, MoveDirection direction)
{
    QVBoxLayout* myLayout = qobject_cast<QVBoxLayout*>(widget->parentWidget()->layout());

    const int index = myLayout->indexOf(widget);
    if (direction == MoveUp && index == 0)
    {
        return false;
    }
    if (direction == MoveDown && index == myLayout->count()-1 )
    {
        return false;
    }
    const int newIndex = direction == MoveUp ? index - 1 : index + 1;
    myLayout->removeWidget(widget);
    myLayout->insertWidget(newIndex , widget);
    return true;
}

void SimpleWidget::paintEvent(QPaintEvent *)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}



void SimpleWidget::mouseReleaseEvent(QMouseEvent *)
{
    int y = geometry().y();
    MoveDirection direct;
    int offset;
    if(oldY > y)
    {
        offset = oldY - y;
        direct = MoveUp;
    }
    else if(oldY < y)
    {
        offset = y - oldY;
        direct = MoveDown;
    }
    int count = offset/height();
    for(int i = 0; i < count; i++)
    {
        moveInLayout(this, direct);
    }
    update();
    QVBoxLayout* myLayout = qobject_cast<QVBoxLayout*>(this->parentWidget()->layout());
    myLayout->update();
    this->saveGeometry();
}












