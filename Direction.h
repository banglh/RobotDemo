#ifndef __DIRECTION_H
#define __DIRECTION_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"

int setDirection(unsigned int * rbDir, unsigned int newDir);
void printDirection(unsigned int rbDir);

int turnLeft(unsigned int rbDir);
int turnRight(unsigned int rbDir);
int turn180(unsigned int rbDir);

int getNewDirection(Position oldPos, Position newPos);

#endif // __DIRECTION_H
