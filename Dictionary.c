#include "Dictionary.h"

void initDict(Dict * d) {
    // implement initDict
    int i,j;
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            (*d).d[i][j] = -1;
        }
    }
}

int hasKey(Dict d, unsigned int row, unsigned int col) {
    // implement initDict
    if (row >= 0 && row < N_ROW && col >= 0 && col < N_COL && d.d[row][col] != -1)
        return TRUE;
    else
        return FALSE;
}

void addKey(Dict * d, unsigned int row, unsigned int col, int newVal) {
    // implement initDict
    if (row >= 0 && row < N_ROW && col >= 0 && col < N_COL)
        (*d).d[row][col] = newVal;
}

int deleteKey(Dict * d, unsigned int row, unsigned int col) {
    if (row >= 0 && row < N_ROW && col >= 0 && col < N_COL) {
        int val = (*d).d[row][col];
        (*d).d[row][col] = -1;
        return val;
    }
    return -1;
}

int getValue(Dict d, unsigned int row, unsigned int col) {
    // implement initDict
    if (row >= 0 && row < N_ROW && col >= 0 && col < N_COL)
        return d.d[row][col];
}

void printDict(Dict d) {
    int i,j;
    printf("\nkey | value\n");
    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            if (d.d[i][j] != -1)
                printf("(%d, %d) | %d\n", i, j, d.d[i][j]);
        }
    }
    printf("\n");
}
