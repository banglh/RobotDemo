#ifndef __PATH_H
#define __PATH_H

#include <stdio.h>
#include "Constants.h"
#include "PriorityQueue.h"
#include "Dictionary.h"
#include "Position.h"
#include "Map.h"

#define ELEMENT_COST 1

unsigned int estimateCost(unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol);
unsigned int estimateCost2(Position startPos, Position endPos);

int findPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol);

// function to check if there is a path between two position given the position of person
int hasPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol);
int hasPath2(unsigned int map[N_ROW][N_COL][N_WALL], Position startPos, Position endPos, Position humanPos);

#endif // __PATH_H
