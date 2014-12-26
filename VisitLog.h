#ifndef __VISIT_LOG_H
#define __VISIT_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"
#include "Map.h"

void visitLogInit(unsigned int visit[N_ROW][N_COL]);
void printVisitLog(unsigned int visit[N_ROW][N_COL]);
int isVisited(unsigned int visit[N_ROW][N_COL], int row, int col);
int isVisited2(unsigned int visit[N_ROW][N_COL], Position pos);
void setVisited(unsigned int visit[N_ROW][N_COL], int row, int col);
void setVisited2(unsigned int visit[N_ROW][N_COL], Position pos);
int hasUnvisitedNeighbour(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], int row, int col);
int hasUnvisitedNeighbour2(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], Position pos);

#endif // __VISIT_LOG_H
