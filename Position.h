#ifndef __POSITION_H
#define __POSITION_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

typedef struct {
    int row;
    int col;
} Position;

Position newPosition(int row, int col);
int isValidPos(int row, int col);
int isValidPos2(Position pos);
int isSamePos(int row1, int col1, int row2, int col2);
int isSamePos2(Position pos1, Position pos2);
int getRow(Position pos);
int getCol(Position pos);
int setRow(Position * pos, int newRow);
int setCol(Position * pos, int newCol);
int setPos(Position * pos, int newRow, int newCol);
void printPos(Position pos);

#endif // __POSITION_H
