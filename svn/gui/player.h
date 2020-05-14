#ifndef PLAYER
#define PLAYER


#include <QFrame>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "gui/scrollarea.h"
#include "gui/buttontool.h"
#include "gui/dialogcolor.h"
#include "gui/dialogplayertool.h"
#include "gui/frameplayertool.h"
#include "gui/frameplayernav.h"
#include "gui/frameplayerslider.h"



class Player: public QFrame

{
    Q_OBJECT

    private:


     bool isSelect();  //verifica si hay seleccionados
     bool isEmpty();    //verifica si la lista esta vacia
     void uncheckAll();  // desmarca todos los selecionados

     DialogColor *dialogcolor;  //dialogo color
     DialogPlayerTool * dialogplayertool;

 QVBoxLayout *verticalLayoutArea;
 QSpacerItem *verticalSpacer;
 ScrollArea *  scrollArea;

 FramePlayerTool *frameplayertool;
 FramePlayerSlider *frameplayerslider;

 int driver;

    public:
FramePlayerNav  *frameplayernav; // es publico por necesitarlo para quitar el pause en scrollarea

      explicit Player( QWidget *parent = 0);
       ~Player();


    protected:

        void dragEnterEvent(QDragEnterEvent *event);
        void dropEvent(QDropEvent *event);
        void  resizeEvent(QResizeEvent *event);


    private slots:
      void ClickBtnSelect();
      void ClickBtnDelete();
      void ClickBtnPurge();
      void ClickBtnNext();
      void ClickBtnColor();

      void ClickNewList();
      void ClickSaveList();
      void ClickLoadList();

      // dialogos del reproductor
      void pinkColor();     //coge un color
      void ClickBtnTool();



};

#endif // PLAYER

