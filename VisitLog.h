#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

void visitLogInit(unsigned int visit[N_ROW][N_COL]);
int isVisited2(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]);
int isVisited(unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col);
void setVisited(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]);
