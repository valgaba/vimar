#ifndef AUDIOITEM
#define AUDIOITEM


#include <QWidget>
#include <QFrame>

#include "ui_AudioItem.h"

class AudioItem: public QFrame ,public Ui::Base

{
    Q_OBJECT

    private:



    public:

      explicit AudioItem( QWidget *parent = 0);
       ~AudioItem();





    protected:
   void  resizeEvent(QResizeEvent *event);



    private slots:


};





#endif // AUDIOITEM

