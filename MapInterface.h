#include <stdio.h>
#include <stdlib.h>
#include "MapConstants.h"

// map related functions
void mapInit(unsigned int map[N_ROW][N_COL]);       // map initialization function
void printMap(unsigned int map[N_ROW][N_COL]);      // print the encode of map

// position related functions
unsigned int getRow(unsigned int pos[MAP_DIMS]);    // get row index
unsigned int getCol(unsigned int pos[MAP_DIMS]);    // get column index
int setRow(unsigned int pos[MAP_DIMS], unsigned int newRow);    // set row index
int setCol(unsigned int pos[MAP_DIMS], unsigned int newCol);    // set column index
int setPos(unsigned int pos[MAP_DIMS], unsigned int newRow, unsigned int newCol);   // set row and column index

