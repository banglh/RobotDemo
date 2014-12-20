#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

int setDirection(unsigned int * rbDir, unsigned int newDir);
void printDirection(unsigned int rbDir);

int turnLeft(unsigned int rbDir);
int turnRight(unsigned int rbDir);
int turn180(unsigned int rbDir);

int getNewDirection(unsigned int oldPos[MAP_DIMS], unsigned int newPos[MAP_DIMS]);
