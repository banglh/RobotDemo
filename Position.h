#ifndef __POSITION_H
#define __POSITION_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

typedef struct {
    unsigned int row;
    unsigned int col;
} Position;

int isValidPos(unsigned int row, unsigned int col);
int isValidPos2(Position pos);
int isSamePos(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);
int isSamePos2(Position pos1, Position pos2);
unsigned int getRow(Position pos);
unsigned int getCol(Position pos);
int setRow(Position * pos, unsigned int newRow);
int setCol(Position * pos, unsigned int newCol);
int setPos(Position * pos, unsigned int newRow, unsigned int newCol);
void printPos(Position pos);

#endif // __POSITION_H
