#include <stdio.h>
#include <stdlib.h>
#include "MapInterface2.h"

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL][N_WALL];
unsigned int sensors[N_SENSORS];

// position of the robot
unsigned int robotPos[MAP_DIMS];
// position of the person
unsigned int humanPos[MAP_DIMS];
// position of the goal
unsigned int goalPos[MAP_DIMS];

// robot direction
unsigned int robotDir;

int main()
{
    // initialize map
    mapInit(map);
    printMap(map);

    setPos(robotPos, 0, 1);
    setRobotDirection(&robotDir, EAST);

    getSensors(sensors, map, robotPos, robotDir);
    int i;
    for (i = 0; i < N_SENSORS; i++) {
        printf("%d ", sensors[i]);
    }
    printf("\n");
    return 0;
}
