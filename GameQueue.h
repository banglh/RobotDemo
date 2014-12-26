#ifndef __GAME_QUEUE_H
#define __GAME_QUEUE_H

#include <stdio.h>
#include "Constants.h"
#include "GameState.h"

typedef struct {
    GameState gs;
    unsigned int priority;
} GameQueueElement;

typedef struct {
    GameQueueElement q[GAME_QUEUE_SIZE];
    int qsize;
} GameQueue;

void gameQueueInit(GameQueue * gqueue);
GameQueueElement deGameQueue(GameQueue * gqueue);
void enGameQueue(GameQueue * gqueue, GameQueueElement element);
int isEmptyGameQueue(GameQueue gqueue);
void printGameQueue(GameQueue gqueue);

GameQueueElement newGameQueueElement(int rbRow, int rbCol, int hmRow, int hmCol, unsigned int priority);
GameQueueElement newGameQueueElement2(Position rbP, Position hmP, unsigned int priority);
void setGameQueueElement(GameQueueElement *qe, int rbRow, int rbCol, int hmRow, int hmCol, unsigned int priority);

#endif // __GAME_QUEUE_H
