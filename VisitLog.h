#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"
#include "Map.h"

void visitLogInit(unsigned int visit[N_ROW][N_COL]);
void printVisitLog(unsigned int visit[N_ROW][N_COL]);
int isVisited2(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]);
int isVisited(unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col);
void setVisited(unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col);
void setVisited2(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]);
int hasUnvisitedNeighbour(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col);
int hasUnvisitedNeighbour2(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]);
