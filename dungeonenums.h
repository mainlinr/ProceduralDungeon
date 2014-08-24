#ifndef DUNGEONENUMS_H
#define DUNGEONENUMS_H

class dungeonenums
{
public:
    enum tileType{
        UNSET,
        ENTERANCE_WITH_FLOOR,
        ENTERANCE_WITHOUT_FLOOR,
        EXIT,
        EMPTY_SPACE,
        DOOR_RIGHT,
        DOOR_LEFT,
        DOOR_UP,
        DOOR_DOWN,
        CORRIDOR,
        ROOM_NO_WALL,
        ROOM_WALL_RIGHT,
        ROOM_WALL_LEFT,
        ROOM_WALL_BOTTOM,
        ROOM_WALL_TOP,
        ROOM_WALL_RIGHT_LEFT,
        ROOM_WALL_TOP_BOTTOM,
        ROOM_WALL_LEFT_TOP,
        ROOM_WALL_TOP_RIGHT,
        ROOM_WALL_RIGHT_BOTTOM,
        ROOM_WALL_BOTTOM_LEFT,
        ROOM_WALL_LEFT_TOP_RIGHT,
        ROOM_WALL_TOP_RIGHT_BOTTOM,
        ROOM_WALL_RIGHT_BOTTOM_LEFT,
        ROOM_WALL_BOTTOM_LEFT_TOP,
        ROOM_ALL_WALL
    };
};
#endif // DUNGEONENUMS_H
