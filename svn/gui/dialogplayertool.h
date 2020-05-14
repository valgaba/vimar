#ifndef DIALOGPLAYERTOOL
#define DIALOGPLAYERTOOL



#include <QWidget>
#include <QDialog>

#include "gui/framebase.h"
#include "gui/combotool.h"



class DialogPlayerTool: public FrameBase
{
    Q_OBJECT

   private:

    ComboTool *combotool;
    void AddDispositivo();
    int driver;

    public:

    int getDriver();




      explicit DialogPlayerTool( QWidget *parent = 0);
       ~DialogPlayerTool();





    protected:


    private slots:


};









#endif // DIALOGPLAYERTOOL

