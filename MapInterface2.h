#include <stdio.h>
#include <stdlib.h>
#include "MapConstants.h"

/******************************** Map related functions **************************************/
void mapInit(unsigned int map[N_ROW][N_COL][N_WALL]);       // map initialization function
void printMap(unsigned int map[N_ROW][N_COL][N_WALL]);      // print the encode of map
int isNeighbour(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);    // check if two positions are neighbours
int isNeighbour2(unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]);
int setWall(unsigned int map[N_ROW][N_COL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2); // set wall between two positions
int setWall2(unsigned int map[N_ROW][N_COL], unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]); // set wall between two positions
// check if wall exists between two neighbours
int checkWall(unsigned int map[N_ROW][N_COL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);
// get N, W, S, E wall bit
unsigned int getNorthBit(unsigned int val);
unsigned int getEastBit(unsigned int val);
unsigned int getWestBit(unsigned int val);
unsigned int getSouthBit(unsigned int val);

// position related functions
int isValidPos(unsigned int row, unsigned int col);
int isValidPos2(unsigned int pos[MAP_DIMS]);
unsigned int getRow(unsigned int pos[MAP_DIMS]);    // get row index
unsigned int getCol(unsigned int pos[MAP_DIMS]);    // get column index
int setRow(unsigned int pos[MAP_DIMS], unsigned int newRow);    // set row index
int setCol(unsigned int pos[MAP_DIMS], unsigned int newCol);    // set column index
int setPos(unsigned int pos[MAP_DIMS], unsigned int newRow, unsigned int newCol);   // set row and column index

// robot direction related functions
int setRobotDirection(unsigned int * rbDir, unsigned int newDir);
void printRobotDirection(unsigned int rbDir);
