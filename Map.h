#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

void mapInit(unsigned int map[N_ROW][N_COL][N_WALL]);       // map initialization function
void printMap(unsigned int map[N_ROW][N_COL][N_WALL]);      // print the encode of map
int isNeighbour(unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);    // check if two positions are neighbours
int isNeighbour2(unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]);
int setWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2); // set wall between two positions
int setWall2(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int pos1[MAP_DIMS], unsigned int pos2[MAP_DIMS]); // set wall between two positions
int checkWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int row1, unsigned int col1, unsigned int row2, unsigned int col2);
void getWallInfo(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir);
void updateWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int sensors[N_SENSORS], unsigned int rbPos[MAP_DIMS], unsigned int rbDir);
int setNorthWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]);
int setEastWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]);
int setWestWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]);
int setSouthWall(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS]);
int setWallFront(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir);
int setWallLeft(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir);
int setWallRight(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int rbPos[MAP_DIMS], unsigned int rbDir);