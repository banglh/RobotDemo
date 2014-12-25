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

    printf("\n");
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
    printf("\n");
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

int isNeighbour2(Position pos1, Position pos2) {
    if (isValidPos2(pos1) && isValidPos2(pos2)) {
        if (pos1.row == pos2.row && abs(pos2.col - pos1.col) == 1)
            return TRUE;
        if (pos1.col == pos2.col && abs(pos1.row - pos2.row) == 1)
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

int setWall2(unsigned int map[N_ROW][N_COL][N_WALL], Position pos1, Position pos2) {
    if (isNeighbour2(pos1, pos2)) {
        if (pos1.row == pos2.row) {
            if (pos1.col > pos2.col) {
                // wall position: pos2's EAST and pos1's WEST
                map[pos1.row][pos1.col][WEST] += 1;
                map[pos2.row][pos2.col][EAST] += 1;
            } else {
                // wall position: pos1's EAST and pos2's WEST
                map[pos1.row][pos1.col][EAST] += 1;
                map[pos2.row][pos2.col][WEST] += 1;
            }
        } else if (pos1.col == pos2.col) {
            if (pos1.row > pos2.row) {
                // wall position: pos2's SOUTH and pos1's NORTH
                map[pos1.row][pos1.col][NORTH] = 1;
                map[pos2.row][pos2.col][SOUTH] = 1;
            } else {
                // wall position: pos2's NORTH and pos1's SOUTH
                map[pos1.row][pos1.col][SOUTH] = 1;
                map[pos2.row][pos2.col][NORTH] = 1;
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

void getWallInfo(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir) {
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

void updateWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int sensors[N_SENSORS], Position rbPos, unsigned int rbDir) {
    if (sensors[FRONT] == 1)
        setWallFront(map, rbPos, rbDir);
    if (sensors[LEFT] == 1)
        setWallLeft(map, rbPos, rbDir);
    if (sensors[RIGHT] ==1)
        setWallRight(map, rbPos, rbDir);
}

int setNorthWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos) {
    // update wall information for current position
    map[rbPos.row][rbPos.col][NORTH] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos.row - 1, rbPos.col)) {
        map[rbPos.row - 1][rbPos.col][SOUTH] = 1;
    }
    return TRUE;
}

int setEastWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos) {
    // update wall information for current position
    map[rbPos.row][rbPos.col][EAST] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos.row, rbPos.col + 1)) {
        map[rbPos.row][rbPos.col + 1][WEST] = 1;
    }
    return TRUE;
}

int setWestWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos) {
    // update wall information for current position
    map[rbPos.row][rbPos.col][WEST] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos.row, rbPos.col - 1)) {
        map[rbPos.row][rbPos.col - 1][EAST] = 1;
    }
    return TRUE;
}

int setSouthWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos) {
    // update wall information for current position
    map[rbPos.row][rbPos.col][SOUTH] = 1;

    // update wall information for the neighbour position if any
    if (isValidPos(rbPos.row + 1, rbPos.col)) {
        map[rbPos.row + 1][rbPos.col][NORTH] = 1;
    }
    return TRUE;
}

int setWallFront(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir) {
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

int setWallLeft(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir) {
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

int setWallRight(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir) {
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

int hasCorner(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row, unsigned int col) {
    if (map[row][col][NORTH] == 1) {
        if (map[row][col][EAST] == 1 || map[row][col][WEST] == 1)
            return TRUE;
    }
    if (map[row][col][SOUTH] == 1) {
        if (map[row][col][EAST] == 1 || map[row][col][WEST] == 1)
            return TRUE;
    }
    return FALSE;
}

int isCornerPos(unsigned int corner[N_ROW][N_COL], unsigned int row, unsigned int col) {
    if (corner[row][col] == 1)
        return TRUE;
    else
        return FALSE;
}

void getCornersPos(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int corner[N_ROW][N_COL]) {
    int i, j;
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            if (hasCorner(map, i, j))
                corner[i][j] = 1;
            else
                corner[i][j] = 0;
        }
    }
}

int isMovable(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol) {
    if (startRow == endRow) {
        if (startCol > endCol) {
            // check east wall
            if (map[startRow][startCol][EAST] == 0)
                return TRUE;
        } else {
            // check west wall
            if (map[startRow][startCol][WEST] == 0)
                return TRUE;
        }
    } else if (startCol == endCol) {
        if (startRow > endRow) {
            // check south wall
            if (map[startRow][startCol][SOUTH] == 0)
                return TRUE;
        } else {
            // check north wall
            if (map[startRow][startCol][NORTH] == 0)
                return TRUE;
        }
    }
    return FALSE;
}
