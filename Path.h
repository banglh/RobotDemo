#ifndef __PATH_H
#define __PATH_H

#include <stdio.h>
#include "Constants.h"
#include "PriorityQueue.h"
#include "Dictionary.h"
#include "Position.h"
#include "Map.h"
#include "PosTrack.h"

#define ELEMENT_COST 1

unsigned int estimateCost(int startRow, int startCol, int endRow, int endCol);
unsigned int estimateCost2(Position startPos, Position endPos);

int findPath(unsigned int map[N_ROW][N_COL][N_WALL], PosTrack * posTr, int startRow, int startCol, int endRow, int endCol, int humanRow, int humanCol);
int findPath2(unsigned int map[N_ROW][N_COL][N_WALL], PosTrack * posTr, Position startPos, Position endPos, Position humanPos);

// function to check if there is a path between two position given the position of person
int hasPath(unsigned int map[N_ROW][N_COL][N_WALL], int startRow, int startCol, int endRow, int endCol, int humanRow, int humanCol);
int hasPath2(unsigned int map[N_ROW][N_COL][N_WALL], Position startPos, Position endPos, Position humanPos);

int getMoveCost2(unsigned int map[N_ROW][N_COL][N_WALL], Position startPos, Position endPos, Position humanPos);
#endif // __PATH_H
