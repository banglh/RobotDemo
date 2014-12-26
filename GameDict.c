#include "GameDict.h"

void initGameDict(GameDict * gd) {
    (*gd).gdSize = 0;
}

int hasState(GameDict gd, int rbRow, int rbCol, int hmRow, int hmCol) {
    int i;
    GameState gs = newGameState(newPosition(rbRow, rbCol), newPosition(hmRow, hmCol));
    for (i = 0; i < gd.gdSize; i++) {
        if (isSameGameState(gd.gsL[i], gs))
            return TRUE;
    }
    return FALSE;
}

int hasState2(GameDict gd, Position rbP, Position hmP) {
    int i;
    GameState gs = newGameState(rbP, hmP);
    for (i = 0; i < gd.gdSize; i++) {
        if (isSameGameState(gd.gsL[i], gs))
            return TRUE;
    }
    return FALSE;
}

void addState(GameDict * gd, int rbRow, int rbCol, int hmRow, int hmCol, int newVal) {
    int i;
    GameState gs = newGameState(newPosition(rbRow, rbCol), newPosition(hmRow, hmCol));
    for (i = 0; i < (*gd).gdSize; i++) {
        if (isSameGameState((*gd).gsL[i], gs))
            break;
    }

    if (i == (*gd).gdSize) {
        (*gd).gsL[i].rbPos = gs.rbPos;
        (*gd).gsL[i].hmPos = gs.hmPos;
        (*gd).cost[i] = newVal;
        (*gd).gdSize++;
    } else {
        (*gd).cost[i] = newVal;
    }
}

void addState2(GameDict * gd, Position rbP, Position hmP, int newVal) {
    int i;
    GameState gs = newGameState(rbP, hmP);
    for (i = 0; i < (*gd).gdSize; i++) {
        if (isSameGameState((*gd).gsL[i], gs))
            break;
    }

    if (i == (*gd).gdSize) {
        (*gd).gsL[i].rbPos = gs.rbPos;
        (*gd).gsL[i].hmPos = gs.hmPos;
        (*gd).cost[i] = newVal;
        (*gd).gdSize++;
    } else {
        (*gd).cost[i] = newVal;
    }
}

int deleteState(GameDict * gd, int rbRow, int rbCol, int hmRow, int hmCol) {
    // TODO implement deleteState
}

int getStateCost(GameDict gd, int rbRow, int rbCol, int hmRow, int hmCol) {
    int i;
    GameState gs = newGameState(newPosition(rbRow, rbCol), newPosition(hmRow, hmCol));
    for (i = 0; i < gd.gdSize; i++) {
        if (isSameGameState(gd.gsL[i], gs))
            return gd.cost[i];
    }

    return MAX_VALUE;
}

int getStateCost2(GameDict gd, Position rbP, Position hmP) {
    int i;
    GameState gs = newGameState(rbP, hmP);
    for (i = 0; i < gd.gdSize; i++) {
        if (isSameGameState(gd.gsL[i], gs))
            return gd.cost[i];
    }

    return MAX_VALUE;
}

void printGameDict(GameDict gd) {
    int i;
    printf("\nGame state | cost\n");
    for (i = 0; i < gd.gdSize; i++) {
        printGameState(gd.gsL[i]);
        printf(" | %d\n", gd.cost[i]);
    }
    printf("\n");
}

