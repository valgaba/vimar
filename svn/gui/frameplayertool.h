#ifndef FRAMEPLAYERTOOL
#define FRAMEPLAYERTOOL






#include "gui/framebase.h"
#include "gui/buttontool.h"



class FramePlayerTool: public FrameBase

{
    Q_OBJECT

    private:



    public:
    ButtonTool * btnNew;
    ButtonTool * btnLoad;
    ButtonTool * btnSave;
    ButtonTool * btnNext;
    ButtonTool * btnPurge;
    ButtonTool * btnColor;
    ButtonTool * btnDelete;
    ButtonTool * btnSelectAll;
    ButtonTool * btnTool;



      explicit FramePlayerTool( QWidget *parent = 0);
       ~FramePlayerTool();





    protected:




    private slots:


};



#endif // FRAMEPLAYERTOOL

