#include "MapInterface.h"

/******************************** Map related functions **************************************/
void mapInit(unsigned int map[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            map[i][j] = 0;
        }
    }

    // add information of border walls
    for (j = 0; j < N_COL; j++) {
        // North border
        map[0][j] += NORTH_WALL;

        // South border
        map[N_ROW - 1][j] += SOUTH_WALL;
    }

    for (i = 0; i < N_ROW; i++) {
        // West border
        map[i][0] += WEST_WALL;

        // East border
        map[i][N_COL - 1] += EAST_WALL;
    }
}

void printMap(unsigned int map[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            printf("%4d", map[i][j]);
        }
        printf("\n");
    }
}

/******************************** Position related functions **************************************/
unsigned int getRow(unsigned int pos[MAP_DIMS]) {
    return pos[ROW_CODE];
}

unsigned int getCol(unsigned int pos[MAP_DIMS]) {
    return pos[COL_CODE];
}

int setRow(unsigned int pos[MAP_DIMS], unsigned int newRow) {
    // check if the new row is valid or not
    if (newRow < 0 || newRow >= N_ROW)
        return FALSE;
    else
        pos[ROW_CODE] = newRow;

    return TRUE;
}

int setCol(unsigned int pos[MAP_DIMS], unsigned int newCol) {
    // check if the new column is valid or not
    if (newCol < 0 || newCol >= N_COL)
        return FALSE;
    else
        pos[COL_CODE] = newCol;

    return TRUE;
}

int setPos(unsigned int pos[MAP_DIMS], unsigned int newRow, unsigned int newCol) {
    // check if the new row is valid or not
    if (newRow < 0 || newRow >= N_ROW)
        return FALSE;
    // check if the new column is valid or not
    if (newCol < 0 || newCol >= N_COL)
        return FALSE;

    // if new row and column are valid
    pos[ROW_CODE] = newRow;
    pos[COL_CODE] = newCol;
}

/******************************** Robot direction related functions **************************************/
int setRobotDirection(unsigned int * rbDir, unsigned int newDir) {
    if (newDir == NORTH || newDir == SOUTH || newDir == EAST || newDir == WEST) {
        *rbDir = newDir;
        return TRUE;
    } else {
        return FALSE;
    }
}

void printRobotDirection(unsigned int rbDir) {
    switch (rbDir) {
    case NORTH:
        printf("Current robot direction: NORTH\n");
        break;
    case SOUTH:
        printf("Current robot direction: SOUTH\n");
        break;
    case EAST:
        printf("Current robot direction: EAST\n");
        break;
    case WEST:
        printf("Current robot direction: WEST\n");
        break;
    default:
        printf("Current robot direction: N/A\n");
    }
}
