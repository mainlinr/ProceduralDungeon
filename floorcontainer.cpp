#include "floorcontainer.h"

floorContainer::floorContainer(){
}

bool floorContainer::insertTile(boost::fusion::vector3< int, int, int > tileLocation, dungeonenums::tileType type){
    try{
        floorMap[tileLocation] = type;
    }
    catch (std::exception& e){
        std::cout << "Error Generated when adding tile: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool floorContainer::deleteTile(){
//    try {
//    } catch (...) {
//    }
}

floorContainer::~floorContainer(){
}
