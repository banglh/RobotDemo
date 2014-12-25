#include "Position.h"

Position newPosition(unsigned int row, unsigned int col) {
    Position pos;
    pos.row = row;
    pos.col = col;
    return pos;
}

int isValidPos(unsigned int row, unsigned int col) {
    if (row < 0 || row >= N_ROW || col < 0 || col >= N_COL)
        return FALSE;
    return TRUE;
}

int isValidPos2(Position pos) {
    if (pos.row < 0 || pos.row >= N_ROW || pos.col < 0 || pos.col >= N_COL)
        return FALSE;
    return TRUE;
}

int isSamePos(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (row1 != row2 || col1 != col2)
        return FALSE;
    return TRUE;
}

int isSamePos2(Position pos1, Position pos2) {
    if (pos1.row != pos2.row || pos1.col != pos2.col)
        return FALSE;
    else
        return TRUE;
}

unsigned int getRow(Position pos) {
    return pos.row;
}

unsigned int getCol(Position pos) {
    return pos.col;
}

int setRow(Position * pos, unsigned int newRow) {
    if (newRow < 0 || newRow >= N_ROW)
        return FALSE;

    (*pos).row = newRow;
    return TRUE;
}

int setCol(Position * pos, unsigned int newCol) {
    if (newCol < 0 || newCol >= N_COL)
        return FALSE;

    (*pos).col = newCol;
    return TRUE;
}

int setPos(Position * pos, unsigned int newRow, unsigned int newCol) {
    if (newRow < 0 || newRow >= N_ROW)
        return FALSE;

    if (newCol < 0 || newCol >= N_COL)
        return FALSE;

    (*pos).row = newRow;
    (*pos).col = newCol;

    return TRUE;
}

void printPos(Position pos) {
    printf("(%d, %d)", pos.row, pos.col);
}
