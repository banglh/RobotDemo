#include <stdio.h>
#include <stdlib.h>
#include "MapInterface2.h"
#include "Stack.h"

// real map
unsigned int rMap[N_ROW][N_COL][N_WALL];

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL][N_WALL];
unsigned int visited[N_ROW][N_COL];

unsigned int sensors[N_SENSORS];

// position of the robot
unsigned int startPos[MAP_DIMS];
unsigned int robotPos[MAP_DIMS];
unsigned int nextPos[MAP_DIMS];

// stacks
struct stack rowStack;
struct stack colStack;

// position of the person
unsigned int humanPos[MAP_DIMS];
// position of the goal
unsigned int goalPos[MAP_DIMS];

// robot direction
unsigned int robotDir;

int main()
{
    // initialize and build real map
    mapInit(rMap);
    buildRealMap();

    // initialize map and robot status
    mapInit(map);
    setPos(startPos, 3, 0);
    setPos(robotPos, 3, 0);
    setRobotDirection(&robotDir, NORTH);
    stackInit(&rowStack);
    stackInit(&colStack);
    push(&rowStack, robotPos[ROW_CODE]);
    push(&colStack, robotPos[COL_CODE]);

    int c;
    while (TRUE) {
        step();

        printf("Next position: (%d, %d)\n", nextPos[ROW_CODE], nextPos[COL_CODE]);
        printf("row stack: "); printStack(rowStack);
        printf("col stack: "); printStack(colStack);

        if (isValidPos2(nextPos))
            move();
        else
            break;

        scanf("%d", &c);
    }

    printMap(map);
}

void buildRealMap() {
    setWall(rMap, 1,0,2,0);
    setWall(rMap, 1,0,1,1);
    setWall(rMap, 1,1,2,1);
    setWall(rMap, 3,0,3,1);
    setWall(rMap, 0,2,0,3);
    setWall(rMap, 2,2,2,3);
    setWall(rMap, 3,2,3,3);
    setWall(rMap, 1,3,2,3);
    setWall(rMap, 1,4,2,4);
    setWall(rMap, 3,4,3,5);
}

void step() {
    // TODO mark current position as visited
    setVisited(visited, robotPos);

    // TODO get sensors
    getSensors(sensors, rMap, robotPos, robotDir);

    // TODO update wall information
    updateWall(map, sensors, robotPos, robotDir);

    // TODO decide next position to go
    getNextPos();
}

void getNextPos() {
    // TODO check if there is any unvisited neighbour (order: front -> left -> right)
    unsigned int wallInfo[N_SENSORS];
    getWallInfo(wallInfo, map, robotPos, robotDir);

    unsigned int testRow, testCol;

    switch (robotDir) {
    case NORTH:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos[ROW_CODE] - 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        break;
    case EAST:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos[ROW_CODE] - 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos[ROW_CODE] + 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        break;
    case WEST:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos[ROW_CODE] + 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos[ROW_CODE] - 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        break;
    case SOUTH:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos[ROW_CODE] + 1;
            testCol = robotPos[COL_CODE];
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos[ROW_CODE];
            testCol = robotPos[COL_CODE] - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    nextPos[ROW_CODE] = testRow;
                    nextPos[COL_CODE] = testCol;
                    push(&rowStack, testRow);
                    push(&colStack, testCol);
                    return;
                }
            }
        }
        break;
    }

    // set last position as the next position
    pop(&rowStack);
    pop(&colStack);
    if (isEmptyStack(rowStack)) {
        nextPos[ROW_CODE] = -1;
        nextPos[COL_CODE] = -1;
    } else {
        nextPos[ROW_CODE] = head(rowStack);
        nextPos[COL_CODE] = head(colStack);
    }

}

void move() {
    // update robot direction
    robotDir = getNewDirection(robotPos, nextPos);

    // update robot position
    robotPos[ROW_CODE] = nextPos[ROW_CODE];
    robotPos[COL_CODE] = nextPos[COL_CODE];
}
