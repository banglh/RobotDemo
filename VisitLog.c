#include "VisitLog.h"
#include "Position.h"

void visitLogInit(unsigned int visit[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            visit[i][j] = 0;
        }
    }
}

void printVisitLog(unsigned int visit[N_ROW][N_COL]) {
    int i,j;

    printf("\n");
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            printf("%4d", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isVisited2(unsigned int visit[N_ROW][N_COL], Position pos) {
    if (visit[pos.row][pos.col] == 1)
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

void setVisited(unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col) {
    if (visit[row][col] == 0)
        visit[row][col] = 1;
}

void setVisited2(unsigned int visit[N_ROW][N_COL], Position pos) {
    if (visit[pos.row][pos.col] == 0)
        visit[pos.row][pos.col] = 1;
}

int hasUnvisitedNeighbour(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], unsigned int row, unsigned int col) {
    // hasUnvisitedNeighbour
    int i;
    for (i = -2; i < 3; i++) {
        if (i != 0) {
            int nbRow = row + i/2;
            int nbCol = col + i%2;
            if (isValidPos(nbRow, nbCol))
                if (visit[nbRow][nbCol] == 0 && !checkWall(map, row, col, nbRow, nbCol))
                    return TRUE;
        }
    }
    return FALSE;
}

int hasUnvisitedNeighbour2(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int visit[N_ROW][N_COL], Position pos) {
    // hasUnvisitedNeighbour2
    int i;
    for (i = -2; i < 3; i++) {
        if (i != 0) {
            int nbRow = pos.row + i/2;
            int nbCol = pos.col + i%2;
            if (isValidPos(nbRow, nbCol))
                if (visit[nbRow][nbCol] == 0 && !checkWall(map, pos.row, pos.col, nbRow, nbCol))
                    return TRUE;
        }
    }
    return FALSE;
}
