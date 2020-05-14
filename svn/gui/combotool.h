#ifndef COMBOTOOL
#define COMBOTOOL


#include <QFrame>
#include <QString>
#include <QComboBox>


class ComboTool: public QFrame

{
    Q_OBJECT

    private:



    public:
QComboBox *comboBox;

   // void SetToolTip(QString text);

      explicit ComboTool( QWidget *parent = 0);
       ~ComboTool();





    protected:




    private slots:


};








#endif // COMBOTOOL

