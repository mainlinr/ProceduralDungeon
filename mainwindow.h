#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <boost/multi_array.hpp>
#include <floorcontainer.h>
#include <dungeonEnums.h>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_dungeon2DButton_clicked();
    void on_dungeon3DButton_clicked();
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    void genFloor();

    Ui::MainWindow *ui;
//    typedef boost::multi_array<double, 3> threeDArray;
//    typedef threeDArray::index threeDArrayIndex;

//    typedef boost::multi_array<double, 2> twoDArray;
//    typedef twoDArray::index twoDArrayIndex;

    std::map< int, floorContainer > dungeonMap;

    floorContainer floor;

    dungeonenums::tileType testtype;

    floorContainer::vectorMapKey test;

    QDialogButtonBox::StandardButton standardButton;

    int floorNum;
    int values;
    int verify;
    int i, j;
    int xRoomRow, yRoomColumn, xRoomPosition, yRoomPostion;
    bool rightDoor, leftDoor, topDoor, bottomDoor;
    bool D2;

};

#endif // MAINWINDOW_H
