#include "Position.h"

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

int isSamePos(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2) {
    if (row1 != row2 || col1 != col2)
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
