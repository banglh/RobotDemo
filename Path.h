#include <stdio.h>
#include "Constants.h"

int findPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol);

// function to check if there is a path between two position given the position of person
int hasPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol);
