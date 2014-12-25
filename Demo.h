#ifndef __DEMO_H
#define __DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Position.h"
#include "Map.h"

void buildRealMap(unsigned int rmap[N_ROW][N_COL][N_WALL]);
void getSensors(unsigned int sensors[N_SENSORS], unsigned int map[N_ROW][N_COL][N_WALL], Position rbPos, unsigned int rbDir);
void move(Position * rbPos, Position * nextPos, unsigned int * rbDir);

#endif // __DEMO_H
