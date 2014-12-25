#include "GameTrack.h"

void initGameTrack(GameTrack * gameTr) {
    (*gameTr).gtSize = 0;
}

//void addStateTrack(GameTrack * gameTr, unsigned int row, unsigned int col, unsigned int fromRow, unsigned int fromCol);
void addStateTrack2(GameTrack * gameTr, GameState gs, GameState frgs) {
    int i;
    for (i = 0; i < (*gameTr).gtSize; i++) {
        if (isSameGameState((*gameTr).gsL[i], gs))
            (*gameTr).fromL[i] = frgs;
    }
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
