#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->zDimensionLabel->hide();
    ui->zDimensionSpinBox->hide();
    //    ui->zRoomDimensionLabel->hide();
    //    ui->zRoomDimensionSpinBox->hide();
    //    ui->xDimensionSpinBox->setToolTip("Must be X * (room width + 1) + 1");
    ui->xDimensionSpinBox->setToolTip("integers from 1 to as large as your computer can handle.");
    ui->xDimensionSpinBox->setToolTipDuration(10000);
    ui->yDimensionSpinBox->setToolTip("integers from 1 to as large as your computer can handle.");
    ui->yDimensionSpinBox->setToolTipDuration(10000);
    ui->zDimensionSpinBox->setToolTip("integers from 1 to as large as your computer can handle.");
    ui->zDimensionSpinBox->setToolTipDuration(10000);
    ui->xRoomDimensionSpinBox->setToolTip("must be a whole fraction of the total width.");
    ui->xRoomDimensionSpinBox->setToolTipDuration(10000);
    ui->yRoomDimensionSpinBox->setToolTip("must be a whole fraction of the total length.");
    ui->yRoomDimensionSpinBox->setToolTipDuration(10000);
    //    ui->zRoomDimensionSpinBox->setToolTip("must be a whole fraction of the total height.");
    //    ui->zRoomDimensionSpinBox->setToolTipDuration(10000);
    floorNum = 1;
    values = 0;
    verify = 0;
    D2 = true;
    srand(time(NULL));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_dungeon2DButton_clicked(){
    ui->zDimensionLabel->hide();
    ui->zDimensionSpinBox->hide();
    //    ui->zRoomDimensionLabel->hide();
    //    ui->zRoomDimensionSpinBox->hide();
    D2 = true;
}

void MainWindow::on_dungeon3DButton_clicked(){
    ui->zDimensionLabel->show();
    ui->zDimensionSpinBox->show();
    //    ui->zRoomDimensionLabel->show();
    //    ui->zRoomDimensionSpinBox->show();
    D2 = false;
}

//generate rooms and floors here
void MainWindow::on_buttonBox_clicked(QAbstractButton *button){
    if( ( ui->xDimensionSpinBox->value() - 1 ) % ( ui->xRoomDimensionSpinBox->value() + 1 ) != 0
            || ( ui->yDimensionSpinBox->value() - 1 ) % ( ui->yRoomDimensionSpinBox->value() + 1 ) != 0
            /*  || ( ui->zDimensionSpinBox - 1 ) % ( ui->zRoomDimensionSpinBox + 1 ) != 0 */){
        return;
    }/*else{*/
    //        xRoomRow = ( ui->xDimensionSpinBox->value() - 1 ) / ( ui->xRoomDimensionSpinBox->value() + 1 );
    //        yRoomColumn = ( ui->yDimensionSpinBox->value() - 1 ) / ( ui->yRoomDimensionSpinBox->value() + 1 );
    //        zRoomPillar = ( ui->zDimensionSpinBox - 1 ) / ( ui->zRoomDimensionSpinBox + 1 );
    //rooms per floor
    //        roomCount = xRoomRow * yRoomColumn;
    //    }

    standardButton = ui->buttonBox->standardButton(button);

//    if(D2){
        // Create a 2D array that is 3 x 4
//        twoDArray B(boost::extents[ui->xDimensionSpinBox->value()][ui->yDimensionSpinBox->value()]);
//    }else{
        // Create a 3D array that is 3 x 4 x 2
//        threeDArray A(boost::extents[ui->xDimensionSpinBox->value()][ui->yDimensionSpinBox->value()][ui->zDimensionSpinBox->value()]);
//    }
    switch (standardButton){
    case QDialogButtonBox::Ok:
            //generate floors
            genFloor();
        break;
    case QDialogButtonBox::Reset:
        ui->xDimensionSpinBox->setValue(1);
        ui->yDimensionSpinBox->setValue(1);
        ui->zDimensionSpinBox->setValue(1);
        on_dungeon2DButton_clicked();
        ui->dungeon2DButton->setChecked(true);
        break;
    default:
        break;
    }
    return;
}

void MainWindow::genFloor()
{
    if(D2){
//        for(twoDArrayIndex i = 0; i != ui->xDimensionSpinBox->value(); i + ui->xRoomDimensionSpinBox->value() ){
//            for(twoDArrayIndex j = 0; j != ui->yDimensionSpinBox->value(); j + ui->yRoomDimensionSpinBox->value() ){
                //gens current room dimensions
                xRoomRow = 1 + rand() % ui->xRoomDimensionSpinBox->value();
                yRoomColumn = 1 + rand() % ui->yRoomDimensionSpinBox->value();
                //gens placement
                xRoomPosition = i + rand() % ( ui->xRoomDimensionSpinBox->value() - xRoomRow );
                yRoomPostion = j + rand() % ( ui->yRoomDimensionSpinBox->value() - yRoomColumn );
                //gens doors
                switch ( rand() % 15 ){
                case 0:
                    //ROOM_DOOR_RIGHT
                    break;
                case 1:
                    //ROOM_DOOR_LEFT
                    break;
                case 2:
                    //ROOM_DOOR_BOTTOM
                    break;
                case 3:
                    //ROOM_DOOR_TOP
                    break;
                case 4:
                    //ROOM_DOOR_RIGHT_LEFT
                    break;
                case 5:
                    //ROOM_DOOR_TOP_BOTTOM
                    break;
                case 6:
                    //ROOM_DOOR_LEFT_TOP
                    break;
                case 7:
                    //ROOM_DOOR_TOP_RIGHT
                    break;
                case 8:
                    //ROOM_DOOR_RIGHT_BOTTOM
                    break;
                case 9:
                    //ROOM_DOOR_BOTTOM_LEFT
                    break;
                case 10:
                    //ROOM_DOOR_LEFT_TOP_RIGHT
                    break;
                case 11:
                    //ROOM_DOOR_TOP_RIGHT_BOTTOM
                    break;
                case 12:
                    //ROOM_DOOR_RIGHT_BOTTOM_LEFT
                    break;
                case 13:
                    //ROOM_DOOR_BOTTOM_LEFT_TOP
                    break;
                case 14:
                    //ROOM_ALL_DOOR
                    break;
                default:
                    break;
                }
                rightDoor, leftDoor, topDoor, bottomDoor;

                //inserts into
//            }
            // Assign values to the elements
//        }else{
            // Assign values to the elements
//            for(threeDArrayIndex i = 0; i != ui->xDimensionSpinBox->value(); ++i){
//                for(threeDArrayIndex j = 0; j != ui->yDimensionSpinBox->value(); ++j){
//                    for(threeDArrayIndex k = 0; k != ui->zDimensionSpinBox->value(); ++k){
//                        A[i][j][k] = values++;
//                    }
//                }
//            }
//        }
    }
    test.m0 = 1;
    test.m1 = 1;
    test.m2 = 1;
    testtype = dungeonenums::CORRIDOR;
    floor.insertTile(test,testtype);

    test.m0 = 1;
    test.m1 = 2;
    test.m2 = 1;
    testtype = dungeonenums::CORRIDOR;
    floor.insertTile(test,testtype);

    dungeonMap[floorNum] = floor;
    floor.clear();
}
