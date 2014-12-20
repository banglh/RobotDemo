#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

int isValidPos(unsigned int row, unsigned int col);
int isValidPos2(unsigned int pos[MAP_DIMS]);
unsigned int getRow(unsigned int pos[MAP_DIMS]);    // get row index
unsigned int getCol(unsigned int pos[MAP_DIMS]);    // get column index
int setRow(unsigned int pos[MAP_DIMS], unsigned int newRow);    // set row index
int setCol(unsigned int pos[MAP_DIMS], unsigned int newCol);    // set column index
int setPos(unsigned int pos[MAP_DIMS], unsigned int newRow, unsigned int newCol);   // set row and column index
