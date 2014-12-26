#include "PosTrack.h"

void initPosTrack(PosTrack * posTr) {
    // implement initDict
    int i,j,z;
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            for (z = 0; z < MAP_DIMS; z++) {
                (*posTr).pt[i][j][z] = -1;
            }
        }
    }
}

void addTrack(PosTrack * posTr, int row, int col, int fromRow, int fromCol) {
    (*posTr).pt[row][col][ROW_CODE] = fromRow;
    (*posTr).pt[row][col][COL_CODE] = fromCol;
}

void addTrack2(PosTrack * posTr, Position pos, Position fromPos) {
    (*posTr).pt[pos.row][pos.col][ROW_CODE] = fromPos.row;
    (*posTr).pt[pos.row][pos.col][COL_CODE] = fromPos.col;
}

void printPosTrack(PosTrack posTr) {
    int i, j;
    printf("%-5s | %-s\n", "position", "from");
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            printf("(%d, %d) | (%d, %d)\n", i, j, posTr.pt[i][j][ROW_CODE], posTr.pt[i][j][COL_CODE]);
        }
    }
}
