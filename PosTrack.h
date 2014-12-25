#ifndef __POS_TRACK_H
#define __POS_TRACK_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    int pt[N_ROW][N_COL][MAP_DIMS];
} PosTrack;

void initPosTrack(PosTrack * posTr);
void addTrack(PosTrack * posTr, unsigned int row, unsigned int col, unsigned int fromRow, unsigned int fromCol);
void addTrack2(PosTrack * posTr, Position pos, Position fromPos);
void printPosTrack(PosTrack posTr);

#endif // __POS_TRACK_H
