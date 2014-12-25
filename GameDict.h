#ifndef __GAME_DICT_H
#define __GAME_DICT_H

#include <stdio.h>
#include "Constants.h"
#include "GameState.h"

typedef struct {
    GameState gsL[GAME_DICT_SIZE];
    unsigned int cost[GAME_DICT_SIZE];
    int gdSize;
} GameDict;

void initGameDict(GameDict * gd);
int hasState(GameDict gd, unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol);
int hasState2(GameDict gd, Position rbP, Position hmP);
void addState(GameDict * gd, unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol, int newVal);
void addState2(GameDict * gd, Position rbP, Position hmP, int newVal);
int deleteState(GameDict * gd, unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol);
int getStateCost(GameDict gd, unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol);
int getStateCost2(GameDict gd, Position rbP, Position hmP);
void printGameDict(GameDict gd);

#endif // __GAME_DICT_H
