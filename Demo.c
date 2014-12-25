#include "Demo.h"

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
