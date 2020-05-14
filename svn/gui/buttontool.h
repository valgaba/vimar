#ifndef BUTTONTOOL
#define BUTTONTOOL






#include <QPushButton>
#include <QString>




class ButtonTool: public QPushButton

{
    Q_OBJECT

    private:



    public:

    void SetIcon(QString file);
    void SetToolTip(QString text);

      explicit ButtonTool( QWidget *parent = 0);
       ~ButtonTool();





    protected:




    private slots:


};







#endif // BUTTONTOOL

