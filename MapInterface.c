#include "MapInterface.h"
#include <math.h>

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

int isNeighbour(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (isValidPos(row1, col1) && isValidPos(row2, col2)) {
        if (row1 == row2 && abs(col2 - col1) == 1)
            return TRUE;
        if (col1 == col2 && abs(row1 - row2) == 1)
            return TRUE;
    }

    return FALSE;
}

int setWall(unsigned int map[N_ROW][N_COL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (isNeighbour(row1, col1, row2, col2)) {
        if (row1 == row2) {
            if (col1 > col2) {
                // wall position: pos2's EAST and pos1's WEST
                map[row1][col1] += WEST_WALL;
                map[row2][col2] += EAST_WALL;
            } else {
                // wall position: pos1's EAST and pos2's WEST
                map[row1][col1] += EAST_WALL;
                map[row2][col2] += WEST_WALL;
            }
        } else if (col1 == col2) {
            if (row1 > row2) {
                // wall position: pos2's SOUTH and pos1's NORTH
                map[row1][col1] += NORTH_WALL;
                map[row2][col2] += SOUTH_WALL;
            } else {
                // wall position: pos2's NORTH and pos1's SOUTH
                map[row1][col1] += SOUTH_WALL;
                map[row2][col2] += NORTH_WALL;
            }
        }
        return TRUE;
    }
    return FALSE;
}

/******************************** Position related functions **************************************/
int isValidPos(unsigned int row, unsigned int col) {
    if (row < 0 || row >= N_ROW || col < 0 || col >= N_COL)
        return FALSE;
    return TRUE;
}

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
