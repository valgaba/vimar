#ifndef SCROLLAREA
#define SCROLLAREA

#include <QScrollArea>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QString>

#include "gui/audioitem.h"
#include "engine/StreamRender.h"



class ScrollArea: public QScrollArea

{
    Q_OBJECT

    private:

 QString botonoff;
 QString botonon;

      AudioItem * defaultaudioitem; // el audioitem que este sonando
      void Recorrer(AudioItem * audioitem);
      bool IsDuplicateItem(AudioItem * audioitem); //comprobar si se duplica el item en el reproductor
      void IsDisable(bool disabel);
      void getNext(); // devuelve el item que tiene el primer nextactivado


    public:
    QVBoxLayout *verticalLayoutArea;
    QSpacerItem *verticalSpacer;
    StreamRender *streamrender ;


      explicit ScrollArea( QWidget *parent = 0);
       ~ScrollArea();


    protected:

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    //void dragMoveEvent(QDragMoveEvent *event);

//void mouseMoveEvent(QMouseEvent *event);



    private slots:
     void ClickBtnLoadPlay();




      public slots:
       void ClickBtnStop();
       void ClickBtnPlay();
       void ClickBtnPause();
       void ClickItem();
       void streamfinal(); // señal procedente de streamrender que detrermina el final de la cancion



};








#endif // SCROLLAREA

