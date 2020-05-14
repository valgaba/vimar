#ifndef SIMPLEWIDGET
#define SIMPLEWIDGET



#include <QWidget>

#include <QPoint>



class SimpleWidget: public QWidget

{
    Q_OBJECT

    private:

   int mouseClickY, oldY, oldX,mouseClickX ;

QPoint dragStartPosition;

    enum MoveDirection{MoveUp,MoveDown};

    bool IsMinimumDistanceRiched(QMouseEvent *event);
    bool moveInLayout(QWidget *widget, MoveDirection direction);
    void paintEvent(QPaintEvent *);

    public:

      explicit SimpleWidget( QWidget *parent = 0);
       ~SimpleWidget();





    protected:


  // void dragEnterEvent(QDragEnterEvent *event);
  // void dropEvent(QDropEvent *event);



 // void dragMoveEvent(QDragMoveEvent *event);

   void mouseMoveEvent(QMouseEvent *event);
   void mousePressEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *);







    private slots:




};





#endif // SIMPLEWIDGET

