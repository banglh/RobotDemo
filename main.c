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

int main()
{
    // initialize map
    mapInit(map);
    printMap(map);

    int row, col;
    char c = 'y';
    while(c == 'y' || c=='Y') {
        printf("set robot position\n");
        printf("Row = ");
        scanf("%d", &row);
        printf("Col = ");
        scanf("%d", &col);
        if (setRow(robotPos, row) && setCol(robotPos, col)) {
            printf("robot position: [%d,%d]\n", getRow(robotPos), getCol(robotPos));
        } else {
            printf("row or col is invalid\n");
        }
        printf("continue? (y/n) ");
        getchar();
        c =getchar();
    }
    return 0;
}
