#include "MapInterface2.h"
#include <math.h>

/******************************** Map related functions **************************************/
void mapInit(unsigned int map[N_ROW][N_COL][N_WALL]) {
    int i,j,z;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            for (z = 0; z < N_WALL; z++) {
                map[i][j][z] = 0;
            }
        }
    }

    // add information of border walls
    for (j = 0; j < N_COL; j++) {
        // North border
        map[0][j][NORTH] = 1;

        // South border
        map[N_ROW - 1][j][SOUTH] = 1;
    }

    for (i = 0; i < N_ROW; i++) {
        // West border
        map[i][0][WEST] = 1;

        // East border
        map[i][N_COL - 1][EAST] = 1;
    }
}

void printMap(unsigned int map[N_ROW][N_COL][N_WALL]) {
    int i,j,val;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            val = map[i][j][NORTH] * NORTH_WALL
                + map[i][j][EAST] * EAST_WALL
                + map[i][j][WEST] * WEST_WALL
                + map[i][j][SOUTH] * SOUTH_WALL;
            printf("%4d", val);
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

int isNeighbour2(unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]) {
    if (isValidPos2(pos1) && isValidPos2(pos2)) {
        if (pos1[ROW_CODE] == pos2[ROW_CODE] && abs(pos2[COL_CODE] - pos1[COL_CODE]) == 1)
            return TRUE;
        if (pos1[COL_CODE] == pos2[COL_CODE] && abs(pos1[ROW_CODE] - pos2[ROW_CODE]) == 1)
            return TRUE;
    }
    return FALSE;
}

int setWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (isNeighbour(row1, col1, row2, col2)) {
        if (row1 == row2) {
            if (col1 > col2) {
                // wall position: pos2's EAST and pos1's WEST
                map[row1][col1][WEST] = 1;
                map[row2][col2][EAST] = 1;
            } else {
                // wall position: pos1's EAST and pos2's WEST
                map[row1][col1][EAST] = 1;
                map[row2][col2][WEST] = 1;
            }
        } else if (col1 == col2) {
            if (row1 > row2) {
                // wall position: pos2's SOUTH and pos1's NORTH
                map[row1][col1][NORTH] = 1;
                map[row2][col2][SOUTH] = 1;
            } else {
                // wall position: pos2's NORTH and pos1's SOUTH
                map[row1][col1][SOUTH] = 1;
                map[row2][col2][NORTH] = 1;
            }
        }
        return TRUE;
    }
    return FALSE;
}

int setWall2(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]) {
    if (isNeighbour2(pos1, pos2)) {
        if (pos1[ROW_CODE] == pos2[ROW_CODE]) {
            if (pos1[COL_CODE] > pos2[COL_CODE]) {
                // wall position: pos2's EAST and pos1's WEST
                map[pos1[ROW_CODE]][pos1[COL_CODE]][WEST] += 1;
                map[pos2[ROW_CODE]][pos2[COL_CODE]][EAST] += 1;
            } else {
                // wall position: pos1's EAST and pos2's WEST
                map[pos1[ROW_CODE]][pos1[COL_CODE]][EAST] += 1;
                map[pos2[ROW_CODE]][pos2[COL_CODE]][WEST] += 1;
            }
        } else if (pos1[COL_CODE] == pos2[COL_CODE]) {
            if (pos1[ROW_CODE] > pos2[ROW_CODE]) {
                // wall position: pos2's SOUTH and pos1's NORTH
                map[pos1[ROW_CODE]][pos1[COL_CODE]][NORTH] = 1;
                map[pos2[ROW_CODE]][pos2[COL_CODE]][SOUTH] = 1;
            } else {
                // wall position: pos2's NORTH and pos1's SOUTH
                map[pos1[ROW_CODE]][pos1[COL_CODE]][SOUTH] = 1;
                map[pos2[ROW_CODE]][pos2[COL_CODE]][NORTH] = 1;
            }
        }
        return TRUE;
    }
    return FALSE;
}

int checkWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (isNeighbour(row1, col1, row2, col2)) {
        if (row1 == row2) {
            if (col1 > col2) {
                // check WEST bit of pos1 or EAST bit of pos2
                if (map[row1][col1][WEST])
                    return TRUE;
            } else {
                // check EAST bit of pos1 or WEST bit of pos2
                if (map[row1][col1][EAST])
                    return TRUE;
            }
        } else if (col1 == col2) {
            if (row1 > row2) {
                // check NORTH bit of pos1 or SOUTH bit of pos2
                if (map[row1][col1][NORTH])
                    return TRUE;
            } else {
                // check SOUTH bit of pos1 or NORTH bit of pos2
                if (map[row1][col1][SOUTH])
                    return TRUE;
            }
        }
        return FALSE;
    } else {
        return FALSE;
    }
}

//unsigned int getNorthBit(unsigned int val) {
//    // implement getNorthBit
//    unsigned int tmp = val;
//    tmp >>= NORTH;  // shift right to NORTH bit
//    tmp &= 1;   // and with 1
//    return tmp;
//}
//unsigned int getEastBit(unsigned int val) {
//    // implement getEastBit
//    unsigned int tmp = val;
//    tmp >>= EAST;  // shift right to EAST bit
//    tmp &= 1;   // and with 1
//    return tmp;
//}
//unsigned int getWestBit(unsigned int val) {
//    // implement getWestBit
//    unsigned int tmp = val;
//    tmp >>= WEST;  // shift right to WEST bit
//    tmp &= 1;   // and with 1
//    return tmp;
//}
//unsigned int getSouthBit(unsigned int val) {
//    // implement getSouthBit
//    unsigned int tmp = val;
//    tmp >>= SOUTH;  // shift right to SOUTH bit
//    tmp &= 1;   // and with 1
//    return tmp;
//}

/******************************** Position related functions **************************************/
int isValidPos(unsigned int row, unsigned int col) {
    if (row < 0 || row >= N_ROW || col < 0 || col >= N_COL)
        return FALSE;
    return TRUE;
}

int isValidPos2(unsigned int pos[MAP_DIMS]) {
    if (pos[ROW_CODE] < 0 || pos[ROW_CODE] >= N_ROW || pos[COL_CODE] < 0 || pos[COL_CODE] >= N_COL)
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

