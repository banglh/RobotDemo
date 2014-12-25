#ifndef __ACTION_H
#define __ACTION_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"

int getAction(Position curpos, Position nextpos, unsigned int curDir);
int getActionNorth(Position curpos, Position nextpos);
int getActionEast(Position curpos, Position nextpos);
int getActionWest(Position curpos, Position nextpos);
int getActionSouth(Position curpos, Position nextpos);
void printAction(int action);

#endif // __ACTION_H
