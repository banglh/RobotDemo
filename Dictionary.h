#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    int d[N_ROW][N_COL];
} Dict;

void initDict(Dict * d);
int hasKey(Dict d, int row, int col);
int hasKey2(Dict d, Position pos);
void addKey(Dict * d, int row, int col, int newVal);
void addKey2(Dict * d, Position pos, int newVal);
int deleteKey(Dict * d, int row, int col);
int getValue(Dict d, int row, int col);
int getValue2(Dict d, Position pos);
void printDict(Dict d);

#endif // __DICTIONARY_H
