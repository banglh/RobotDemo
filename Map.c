#include "Map.h"

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

void getWallInfo(unsigned int wallinfo[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir) {
    switch (rbDir) {
    case NORTH:
        wallinfo[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        wallinfo[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        wallinfo[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        break;
    case EAST:
        wallinfo[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        wallinfo[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        wallinfo[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        break;
    case WEST:
        wallinfo[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        wallinfo[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        wallinfo[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH];
        break;
    case SOUTH:
        wallinfo[FRONT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH];
        wallinfo[LEFT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST];
        wallinfo[RIGHT] = map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST];
        break;
    }
}

void updateWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int sensors[N_SENSORS], unsigned int rbPos[MAP_DIMS], unsigned int rbDir) {
    if (sensors[FRONT] == 1)
        setWallFront(map, rbPos, rbDir);
    if (sensors[LEFT] == 1)
        setWallLeft(map, rbPos, rbDir);
    if (sensors[RIGHT] ==1)
        setWallRight(map, rbPos, rbDir);
}


int setNorthWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]) {
    // update wall information for current position
    map[rbPos[ROW_CODE]][rbPos[COL_CODE]][NORTH] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos[ROW_CODE] - 1, rbPos[COL_CODE])) {
        map[rbPos[ROW_CODE] - 1][rbPos[COL_CODE]][SOUTH] = 1;
    }
    return TRUE;
}

int setEastWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]) {
    // update wall information for current position
    map[rbPos[ROW_CODE]][rbPos[COL_CODE]][EAST] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos[ROW_CODE], rbPos[COL_CODE] + 1)) {
        map[rbPos[ROW_CODE]][rbPos[COL_CODE] + 1][WEST] = 1;
    }
    return TRUE;
}

int setWestWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]) {
    // update wall information for current position
    map[rbPos[ROW_CODE]][rbPos[COL_CODE]][WEST] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos[ROW_CODE], rbPos[COL_CODE] - 1)) {
        map[rbPos[ROW_CODE]][rbPos[COL_CODE] - 1][EAST] = 1;
    }
    return TRUE;
}

int setSouthWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]) {
    // update wall information for current position
    map[rbPos[ROW_CODE]][rbPos[COL_CODE]][SOUTH] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos[ROW_CODE] + 1, rbPos[COL_CODE])) {
        map[rbPos[ROW_CODE] + 1][rbPos[COL_CODE]][NORTH] = 1;
    }
    return TRUE;
}

int setWallFront(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir){
    switch (rbDir) {
    case NORTH:
        setNorthWall(map, rbPos);
        break;
    case EAST:
        setEastWall(map, rbPos);
        break;
    case WEST:
        setWestWall(map, rbPos);
        break;
    case SOUTH:
        setSouthWall(map, rbPos);
        break;
    default:
        break;
    }
    return TRUE;
}

int setWallLeft(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir) {
    switch (rbDir) {
    case NORTH:
        setWestWall(map, rbPos);
        break;
    case EAST:
        setNorthWall(map, rbPos);
        break;
    case WEST:
        setSouthWall(map, rbPos);
        break;
    case SOUTH:
        setEastWall(map, rbPos);
        break;
    default:
        break;
    }
    return TRUE;
}

int setWallRight(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir) {
    switch (rbDir) {
    case NORTH:
        setEastWall(map, rbPos);
        break;
    case EAST:
        setSouthWall(map, rbPos);
        break;
    case WEST:
        setNorthWall(map, rbPos);
        break;
    case SOUTH:
        setWestWall(map, rbPos);
        break;
    default:
        break;
    }
    return TRUE;
}
