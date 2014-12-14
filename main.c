#include <stdio.h>
#include <stdlib.h>
#include "MapInterface.h"

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL];

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

    int row1, col1, row2, col2;
    char c = 'y';
    robotDir = 4;
    unsigned int dir = EAST;
    setRobotDirection(&robotDir, dir);
    printRobotDirection(robotDir);
    while(c == 'y' || c=='Y') {
        printf("set wall");
        printf("Row1 = ");
        scanf("%d", &row1);
        printf("Col1 = ");
        scanf("%d", &col1);
        printf("Row2 = ");
        scanf("%d", &row2);
        printf("Col2 = ");
        scanf("%d", &col2);
        if (setWall(map, row1, col1, row2, col2)) {
            printMap(map);
        } else {
            printf("row or col is invalid\n");
            printMap(map);
        }
        printf("continue? (y/n) ");
        getchar();
        c =getchar();
    }
    return 0;
}
