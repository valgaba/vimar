#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:



    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void IniAudio(); // iniciamos los dispositivos de audio


};

#endif // MAINWINDOW_H
