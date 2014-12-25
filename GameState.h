#ifndef __GAME_STATE_H
#define __GAME_STATE_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    Position rbPos;
    Position hmPos;
} GameState;

GameState newGameState(Position rbP, Position hmP);
void setGameState(GameState * gs, Position rbP, Position hmP);
int isSameGameState(GameState gs1, GameState gs2);
void printGameState(GameState gs);

#endif // __GAME_STATE_H
