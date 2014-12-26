#include "GameTrack.h"

void initGameTrack(GameTrack * gameTr) {
    (*gameTr).gtSize = 0;
}

//void addStateTrack(GameTrack * gameTr, unsigned int row, unsigned int col, unsigned int fromRow, unsigned int fromCol);
void addStateTrack2(GameTrack * gameTr, GameState gs, GameState frgs) {
    int i;
    for (i = 0; i < (*gameTr).gtSize; i++) {
        if (isSameGameState((*gameTr).gsL[i], gs)) {
            (*gameTr).fromL[i] = frgs;
            return;
        }
    }
    // add new entry
    (*gameTr).gsL[(*gameTr).gtSize] = gs;
    (*gameTr).fromL[(*gameTr).gtSize] = frgs;
    (*gameTr).gtSize++;
}

void printGameTrack(GameTrack gameTr) {
    int i;
    printf("\nGame state | from state\n");
    for (i = 0; i < gameTr.gtSize; i++) {
        printGameState(gameTr.gsL[i]);
        printf(" | ");
        printGameState(gameTr.fromL[i]);
        printf("\n");
    }
    printf("\n");
}

GameState getFromState(GameTrack gameTr, GameState gs) {
    int i;
    for (i = 0; i < gameTr.gtSize; i++) {
        if (isSameGameState(gameTr.gsL[i], gs)) {
            return gameTr.fromL[i];
        }
    }
    return newGameState(newPosition(-1, -1), newPosition(-1, -1));
}

void initSolution(RescueSolution * solution) {
    (*solution).top = -1;
}

void getRescueSolution(GameTrack gt, Position rbPos, Position hmPos, Position finalGoal, RescueSolution * solution) {
    (*solution).top = -1;
    GameState startState = newGameState(rbPos, hmPos);
    GameState curState;
    int i;
    for (i = 0; i < gt.gtSize; i++) {
        if (isSamePos2(gt.gsL[i].hmPos, finalGoal)) {
            curState = gt.gsL[i];
            break;
        }
    }

    while (!isSameGameState(curState, startState)) {
        (*solution).top++;
        (*solution).rs[(*solution).top] = curState.hmPos;
        curState = getFromState(gt, curState);
    }

    (*solution).top++;
    (*solution).rs[(*solution).top] = curState.hmPos;
}

void printRescueSolution(RescueSolution rs) {
    int i;
    printf("\n");
    for (i = rs.top; i > 0; i--) {
        printPos(rs.rs[i]);
        printf(" --> ");
    }
    printPos(rs.rs[i]);
    printf("\n");
}
