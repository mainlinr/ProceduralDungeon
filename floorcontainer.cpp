#include "floorcontainer.h"

floorContainer::floorContainer(){
}

bool floorContainer::insertTile(boost::fusion::vector3< double, double, double > tileLocation, dungeonenums::tileType type){
    floorMap[tileLocation] = type;
    return true;
}

bool floorContainer::clear()
{
    floorMap.clear();
}

bool floorContainer::deleteTile(){
}

floorContainer::map floorContainer::getMap(){
    return floorMap;
}

floorContainer::~floorContainer(){
}
