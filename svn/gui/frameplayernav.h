#ifndef FRAMEPLAYERNAV
#define FRAMEPLAYERNAV




#include "gui/framebase.h"
#include "gui/buttontool.h"
//#include "gui/slider.h"
#include "gui/labelcount.h"



class FramePlayerNav: public FrameBase

{
    Q_OBJECT

    private:



    public:

 ButtonTool * btnPlay;
 ButtonTool * btnPause;
 ButtonTool * btnStop;

 //Slider * slider;
 LabelCount * labelcount;

      explicit FramePlayerNav( QWidget *parent = 0);
       ~FramePlayerNav();





    protected:




    private slots:


};



#endif // FRAMEPLAYERNAV

