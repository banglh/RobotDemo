#include "Demo.h"

void buildRealMap(unsigned int rmap[N_ROW][N_COL][N_WALL]) {
//    setWall(rmap, 1,0,1,1);
//    setWall(rmap, 2,1,3,1);
//    setWall(rmap, 0,2,0,3);
//    setWall(rmap, 2,2,2,3);
//    setWall(rmap, 3,2,3,3);
//    setWall(rmap, 1,3,2,3);
//    setWall(rmap, 0,4,0,5);
//    setWall(rmap, 0,5,1,5);
}

void getSensors(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir) {

    switch (rbDir) {
    case NORTH:
        sensors[FRONT] = map[rbPos.row][rbPos.col][NORTH];
        sensors[LEFT] = map[rbPos.row][rbPos.col][WEST];
        sensors[RIGHT] = map[rbPos.row][rbPos.col][EAST];
        break;
    case EAST:
        sensors[FRONT] = map[rbPos.row][rbPos.col][EAST];
        sensors[LEFT] = map[rbPos.row][rbPos.col][NORTH];
        sensors[RIGHT] = map[rbPos.row][rbPos.col][SOUTH];
        break;
    case WEST:
        sensors[FRONT] = map[rbPos.row][rbPos.col][WEST];
        sensors[LEFT] = map[rbPos.row][rbPos.col][SOUTH];
        sensors[RIGHT] = map[rbPos.row][rbPos.col][NORTH];
        break;
    case SOUTH:
        sensors[FRONT] = map[rbPos.row][rbPos.col][SOUTH];
        sensors[LEFT] = map[rbPos.row][rbPos.col][EAST];
        sensors[RIGHT] = map[rbPos.row][rbPos.col][WEST];
        break;
    }
}

void move(Position * rbPos, Position * nextPos, unsigned int * rbDir) {
    // update robot direction
    *rbDir = getNewDirection(*rbPos, *nextPos);

    // update robot position
    *rbPos = *nextPos;
}
