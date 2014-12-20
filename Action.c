#include "Action.h"

int getAction(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS], unsigned int curDir) {
    switch (curDir) {
    case NORTH:
        return getActionNorth(curpos, nextpos);
    case EAST:
        return getActionEast(curpos, nextpos);
    case WEST:
        return getActionWest(curpos, nextpos);
    case SOUTH:
        return getActionSouth(curpos, nextpos);
    }
}

int getActionNorth(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]) {
    if (curpos[ROW_CODE] == nextpos[ROW_CODE]) {
        if (nextpos[COL_CODE] < curpos[COL_CODE])
            return MOVE_LEFT;
        else
            return MOVE_RIGHT;

    } else if (curpos[COL_CODE] == nextpos[COL_CODE]) {
        if (nextpos[ROW_CODE] < curpos[ROW_CODE])
            return MOVE_FORWARD;
        else
            return MOVE_BACKWARD;
    }
}

int getActionEast(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]) {
    if (curpos[ROW_CODE] == nextpos[ROW_CODE]) {
        if (nextpos[COL_CODE] < curpos[COL_CODE])
            return MOVE_BACKWARD;
        else
            return MOVE_FORWARD;

    } else if (curpos[COL_CODE] == nextpos[COL_CODE]) {
        if (nextpos[ROW_CODE] < curpos[ROW_CODE])
            return MOVE_LEFT;
        else
            return MOVE_RIGHT;
    }
}

int getActionWest(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]) {
    if (curpos[ROW_CODE] == nextpos[ROW_CODE]) {
        if (nextpos[COL_CODE] < curpos[COL_CODE])
            return MOVE_FORWARD;
        else
            return MOVE_BACKWARD;

    } else if (curpos[COL_CODE] == nextpos[COL_CODE]) {
        if (nextpos[ROW_CODE] < curpos[ROW_CODE])
            return MOVE_RIGHT;
        else
            return MOVE_LEFT;
    }
}

int getActionSouth(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]) {
    if (curpos[ROW_CODE] == nextpos[ROW_CODE]) {
        if (nextpos[COL_CODE] < curpos[COL_CODE])
            return MOVE_RIGHT;
        else
            return MOVE_LEFT;

    } else if (curpos[COL_CODE] == nextpos[COL_CODE]) {
        if (nextpos[ROW_CODE] < curpos[ROW_CODE])
            return MOVE_BACKWARD;
        else
            return MOVE_FORWARD;
    }
}

void printAction(int action) {
    switch (action) {
    case MOVE_FORWARD:
        printf("forward");
        break;
    case MOVE_LEFT:
        printf("turn left + forward");
        break;
    case MOVE_RIGHT:
        printf("turn right + forward");
        break;
    case MOVE_BACKWARD:
        printf("turn 180 + forward");
        break;
    default:
        printf("N/A");
    }
}
