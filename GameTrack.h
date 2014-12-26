#ifndef __GAME_TRACK_H
#define __GAME_TRACK_H

#include <stdio.h>
#include "Constants.h"
#include "GameState.h"

typedef struct {
    GameState gsL[GAME_TRACK_SIZE];
    GameState fromL[GAME_TRACK_SIZE];
    int gtSize;
} GameTrack;

void initGameTrack(GameTrack * gameTr);
//void addStateTrack(GameTrack * gameTr, unsigned int row, unsigned int col, unsigned int fromRow, unsigned int fromCol);
void addStateTrack2(GameTrack * gameTr, GameState gs, GameState frgs);
void printGameTrack(GameTrack gameTr);

#endif // __GAME_TRACK_H