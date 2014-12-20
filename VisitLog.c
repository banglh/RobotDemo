#include "VisitLog.h"

void visitLogInit(unsigned int visit[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            visit[i][j] = 0;
        }
    }
}

int isVisited2(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]) {
    if (visit[pos[ROW_CODE]][pos[COL_CODE]] == 1)
        return TRUE;
    else
        return FALSE;
}

int isVisited(unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col) {
    if (visit[row][col] == 1)
        return TRUE;
    else
        return FALSE;
}

void setVisited(unsigned int visit[N_ROW][N_COL], unsigned int pos[MAP_DIMS]) {
    if (visit[pos[ROW_CODE]][pos[COL_CODE]] == 0)
        visit[pos[ROW_CODE]][pos[COL_CODE]] = 1;
}
