#include "GameState.h"

GameState newGameState(Position rbP, Position hmP) {
    GameState gs;
    gs.rbPos = rbP;
    gs.hmPos = hmP;
    return gs;
}

void setGameState(GameState * gs, Position rbP, Position hmP) {
    (*gs).rbPos = rbP;
    (*gs).hmPos = hmP;
}

int isSameGameState(GameState gs1, GameState gs2) {
    if (isSamePos2(gs1.rbPos, gs2.rbPos) && isSamePos2(gs1.hmPos, gs2.hmPos))
        return TRUE;
    return FALSE;
}

void printGameState(GameState gs) {
    printf("(%d, %d) - (%d, %d)", gs.rbPos.row, gs.rbPos.col, gs.hmPos.row, gs.hmPos.col);
}
