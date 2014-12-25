#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    int d[N_ROW][N_COL];
} Dict;

void initDict(Dict * d);
int hasKey(Dict d, unsigned int row, unsigned int col);
int hasKey2(Dict d, Position pos);
void addKey(Dict * d, unsigned int row, unsigned int col, int newVal);
void addKey2(Dict * d, Position pos, int newVal);
int deleteKey(Dict * d, unsigned int row, unsigned int col);
int getValue(Dict d, unsigned int row, unsigned int col);
int getValue2(Dict d, Position pos);
void printDict(Dict d);

#endif // __DICTIONARY_H
