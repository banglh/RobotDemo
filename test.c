#include <stdio.h>
#include <stdlib.h>
#include "MapInterface2.h"

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL][N_WALL];

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

    setWall(map, 2,2,2,3);
    printf("\n");
    printMap(map);
    printf("%d\n", checkWall(map, 2,0,1,0));
//    int row1, col1, row2, col2;
//    char c = 'y';
//    robotDir = 4;
//    unsigned int dir = EAST;
//    setRobotDirection(&robotDir, dir);
//    printRobotDirection(robotDir);
//    setPos(humanPos, 0,0);
//    setPos(goalPos, 1,1);
//    if (isNeighbour2(humanPos, goalPos))
//        printf("is neighbours\n");
//    else
//        printf("not neighbours\n");
//    while(c == 'y' || c=='Y') {
//        printf("set wall");
//        printf("Row1 = ");
//        scanf("%d", &row1);
//        printf("Col1 = ");
//        scanf("%d", &col1);
//        printf("Row2 = ");
//        scanf("%d", &row2);
//        printf("Col2 = ");
//        scanf("%d", &col2);
//        unsigned int pos1[MAP_DIMS] = {row1, col1};
//        unsigned int pos2[MAP_DIMS] = {row2, col2};
//        if (setWall2(map, pos1, pos2)) {
//            printMap(map);
//        } else {
//            printf("row or col is invalid\n");
//            printMap(map);
//        }
//        printf("continue? (y/n) ");
//        getchar();
//        c =getchar();
//    }
    return 0;
}
