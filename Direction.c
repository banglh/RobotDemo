#include "Direction.h"

int setDirection(unsigned int * rbDir, unsigned int newDir) {
    if (newDir == NORTH || newDir == SOUTH || newDir == EAST || newDir == WEST) {
        *rbDir = newDir;
        return TRUE;
    } else {
        return FALSE;
    }
}

void printDirection(unsigned int rbDir) {
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

int turnLeft(unsigned int rbDir) {
    // turnLeft
    switch (rbDir) {
    case NORTH:
        return WEST;
    case EAST:
        return NORTH;
    case WEST:
        return SOUTH;
    case SOUTH:
        return EAST;
    default:
        return -1;
    }
}
int turnRight(unsigned int rbDir) {
    // turnRight
    switch (rbDir) {
    case NORTH:
        return EAST;
    case EAST:
        return SOUTH;
    case WEST:
        return NORTH;
    case SOUTH:
        return WEST;
    default:
        return -1;
    }
}

int turn180(unsigned int rbDir) {
    // turn180
    switch (rbDir) {
    case NORTH:
        return SOUTH;
    case EAST:
        return WEST;
    case WEST:
        return EAST;
    case SOUTH:
        return NORTH;
    default:
        return -1;
    }
}

int getNewDirection(unsigned int oldPos[MAP_DIMS], unsigned int newPos[MAP_DIMS]) {
    if (oldPos[ROW_CODE] == newPos[ROW_CODE]) {
        if (oldPos[COL_CODE] > newPos[COL_CODE])
            return WEST;
        else
            return EAST;
    } else if (oldPos[COL_CODE] == newPos[COL_CODE]) {
        if (oldPos[ROW_CODE] > newPos[ROW_CODE])
            return NORTH;
        else
            return SOUTH;
    }
}

