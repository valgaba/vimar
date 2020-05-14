#ifndef AUDIOITEM
#define AUDIOITEM


#include <QWidget>
#include <QFrame>
#include <QUrl>

#include "ui_AudioItem.h"

class AudioItem: public QFrame ,public Ui::Base

{
    Q_OBJECT

   private:
   bool isLoop;
   bool isPurge;
   bool isNext;
   bool isSelect;
   bool isplaying; // si el item está sonando

    QString url;

   float second;    //duracion delm audio en segundos


    public:

   void setLoop  (bool value);
   void setPurge (bool value);
   void setNext  (bool value);
   void setSelect(bool value);
   void setPlaying(bool value);

   void setUrl(QString url);
   QString Url();

   void setSecond(float second);
   float Second();

   bool Loop();
   bool Purge();
   bool Next();
   bool Select();
   bool Playing();

      explicit AudioItem( QWidget *parent = 0);
       ~AudioItem();





    protected:
   void  resizeEvent(QResizeEvent *event);

   void dragEnterEvent(QDragEnterEvent *event);
   void dropEvent(QDropEvent *event);
  // void dragMoveEvent (QDragMoveEvent *event);

  // void contextMenuEvent(QContextMenuEvent *event);

//void mouseMoveEvent(QMouseEvent *event);

   void mousePressEvent(QMouseEvent *event);
  // void mouseReleaseEvent (QMouseEvent *event );
  // void keyPressEvent (QKeyEvent *event);





    private slots:

   void ClickBtnDelete();
   void ClickBtnLoop();
   void ClickBtnPurge();
   void ClickBtnNext();
   void ClickBtnSelect();


   signals:

  void clickedItem();


};





#endif // AUDIOITEM

