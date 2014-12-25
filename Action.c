#include "Action.h"

int getAction(Position curpos, Position nextpos, unsigned int curDir) {
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

int getActionNorth(Position curpos, Position nextpos) {
    if (curpos.row == nextpos.row) {
        if (nextpos.col < curpos.col)
            return MOVE_LEFT;
        else
            return MOVE_RIGHT;

    } else if (curpos.col == nextpos.col) {
        if (nextpos.row < curpos.row)
            return MOVE_FORWARD;
        else
            return MOVE_BACKWARD;
    }
}

int getActionEast(Position curpos, Position nextpos) {
    if (curpos.row == nextpos.row) {
        if (nextpos.col < curpos.col)
            return MOVE_BACKWARD;
        else
            return MOVE_FORWARD;

    } else if (curpos.col == nextpos.col) {
        if (nextpos.row < curpos.row)
            return MOVE_LEFT;
        else
            return MOVE_RIGHT;
    }
}

int getActionWest(Position curpos, Position nextpos) {
    if (curpos.row == nextpos.row) {
        if (nextpos.col < curpos.col)
            return MOVE_FORWARD;
        else
            return MOVE_BACKWARD;

    } else if (curpos.col == nextpos.col) {
        if (nextpos.row < curpos.row)
            return MOVE_RIGHT;
        else
            return MOVE_LEFT;
    }
}

int getActionSouth(Position curpos, Position nextpos) {
    if (curpos.row == nextpos.row) {
        if (nextpos.col < curpos.col)
            return MOVE_RIGHT;
        else
            return MOVE_LEFT;

    } else if (curpos.col == nextpos.col) {
        if (nextpos.row < curpos.row)
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
