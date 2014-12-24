#include <stdio.h>
#include "Constants.h"

typedef struct {
    int d[N_ROW][N_COL];
} Dict;

void initDict(Dict * d);
int hasKey(Dict d, unsigned int row, unsigned int col);
void addKey(Dict * d, unsigned int row, unsigned int col, int newVal);
int deleteKey(Dict * d, unsigned int row, unsigned int col);
int getValue(Dict d, unsigned int row, unsigned int col);
void printDict(Dict d);
