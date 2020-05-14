#ifndef DIALOGPROGRESSBAR
#define DIALOGPROGRESSBAR



#include <QProgressBar>
#include <QString>

#include "gui/dialogbase.h"
#include "gui/labelbase.h"



class DialogProgressBar: public DialogBase

{
    Q_OBJECT

    private:

QProgressBar *progressbar;
LabelBase* label;

    public:
void setMax(int valor);
void setValor(int valor);
void setInfo(QString info);


      explicit DialogProgressBar( QWidget *parent = 0);
       ~DialogProgressBar();





    protected:




    private slots:


};




#endif // DIALOGPROGRESSBAR

