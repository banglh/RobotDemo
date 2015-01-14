#ifndef __POS_TRACK_H
#define __POS_TRACK_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"
#include "Stack.h"

typedef struct {
    int pt[N_ROW][N_COL][MAP_DIMS];
} PosTrack;

void initPosTrack(PosTrack * posTr);
void addTrack(PosTrack * posTr, int row, int col, int fromRow, int fromCol);
void addTrack2(PosTrack * posTr, Position pos, Position fromPos);
void printPosTrack(PosTrack posTr);

void getPath(PosTrack gt, Position startPos, Position endPos, Stack * path);

#endif // __POS_TRACK_H
