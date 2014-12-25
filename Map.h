#ifndef __MAP_H
#define __MAP_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"

void mapInit(unsigned int map[N_ROW][N_COL][N_WALL]);       // map initialization function
void printMap(unsigned int map[N_ROW][N_COL][N_WALL]);      // print the encode of map
int isNeighbour(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);    // check if two positions are neighbours
int isNeighbour2(Position pos1, Position pos2);
int setWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2); // set wall between two positions
int setWall2(unsigned int map[N_ROW][N_COL][N_WALL], Position pos1, Position pos2); // set wall between two positions
int checkWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);
void getWallInfo(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir);
void updateWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int sensors[N_SENSORS], Position rbPos, unsigned int rbDir);

int setNorthWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos);
int setEastWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos);
int setWestWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos);
int setSouthWall(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos);
int setWallFront(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir);
int setWallLeft(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir);
int setWallRight(unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir);

int hasCorner(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row, unsigned int col);
int isCornerPos(unsigned int corner[N_ROW][N_COL], unsigned int row, unsigned int col);
void getCornersPos(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int corner[N_ROW][N_COL]);
// function to check if robot can move person from start to goal
int isMovable(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol);

#endif // __MAP_H
