#ifndef PLAYER
#define PLAYER


#include <QFrame>
#include <QVBoxLayout>
#include <QSpacerItem>

class Player: public QFrame

{
    Q_OBJECT

    private:

 QVBoxLayout *verticalLayoutArea;
 QSpacerItem *verticalSpacer;

    public:

      explicit Player( QWidget *parent = 0);
       ~Player();


    protected:

        void dragEnterEvent(QDragEnterEvent *event);
        void dropEvent(QDropEvent *event);
        void  resizeEvent(QResizeEvent *event);


    private slots:


};

#endif // PLAYER

