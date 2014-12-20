#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"

int getAction(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS], unsigned int curDir);
int getActionNorth(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]);
int getActionEast(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]);
int getActionWest(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]);
int getActionSouth(unsigned int curpos[MAP_DIMS], unsigned int nextpos[MAP_DIMS]);
void printAction(int action);
