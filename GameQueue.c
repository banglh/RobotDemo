#include "GameQueue.h"

void gameQueueInit(GameQueue * gqueue) {
    (*gqueue).qsize = 0;
}

GameQueueElement deGameQueue(GameQueue * gqueue) {
    // if the queue is empty, return an invalid element
    if (isEmptyGameQueue(*gqueue)) {
        GameQueueElement e = newGameQueueElement2(newPosition(N_ROW, N_COL), newPosition(N_ROW, N_COL), 0);
        return e;
    }

    int minIndex = -1;
    int minPriority = MAX_VALUE;
    int i;
    for (i = 0; i < (*gqueue).qsize; i++) {
        if (((*gqueue).q[i]).priority < minPriority) {
            minIndex = i;
            minPriority = ((*gqueue).q[i]).priority;
        }
    }

    // get the element to dequeue
    GameQueueElement e = (*gqueue).q[minIndex];

    // update queue
    (*gqueue).q[minIndex] = (*gqueue).q[(*gqueue).qsize - 1];
    (*gqueue).qsize--;

    return e;
}

void enGameQueue(GameQueue * gqueue, GameQueueElement element) {
    (*gqueue).q[(*gqueue).qsize] = element;
    (*gqueue).qsize++;
}

int isEmptyGameQueue(GameQueue gqueue) {
    if (gqueue.qsize == 0)
        return TRUE;
    else
        return FALSE;
}

void printGameQueue(GameQueue gqueue) {
    int i;
    printf("\n%-s | %-s | %-s\n", "robotPos", "humanPos", "priority");
    for (i = 0; i < gqueue.qsize; i++) {
        printGameState(gqueue.q[i].gs);
        printf(" | %-d\n", gqueue.q[i].priority);
    }
    printf("\n");
}

GameQueueElement newGameQueueElement(unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol, unsigned int priority) {
    GameQueueElement e;
    e.gs.rbPos.row = rbRow;
    e.gs.rbPos.col = rbCol;
    e.gs.hmPos.row = hmRow;
    e.gs.hmPos.col = hmCol;
    e.priority = priority;
    return e;
}

GameQueueElement newGameQueueElement2(Position rbP, Position hmP, unsigned int priority) {
    GameQueueElement e;
    e.gs.rbPos = rbP;
    e.gs.hmPos = hmP;
    e.priority = priority;
    return e;
}

void setGameQueueElement(GameQueueElement *qe, unsigned int rbRow, unsigned int rbCol, unsigned int hmRow, unsigned int hmCol, unsigned int priority) {
    (*qe).gs.rbPos.row = rbRow;
    (*qe).gs.rbPos.col = rbCol;
    (*qe).gs.hmPos.row = hmRow;
    (*qe).gs.hmPos.col = hmCol;
    (*qe).priority = priority;
}

