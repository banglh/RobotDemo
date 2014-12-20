#include "Demo.h"

void getSensors(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir) {

    switch (rbDir) {
    case NORTH:
        sensors[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        sensors[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        sensors[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        break;
    case EAST:
        sensors[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        sensors[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        sensors[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        break;
    case WEST:
        sensors[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        sensors[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        sensors[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        break;
    case SOUTH:
        sensors[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        sensors[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        sensors[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        break;
    }

}
