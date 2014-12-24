#include <stdio.h>
#include <stdlib.h>
#include "Demo.h"
#include "Stack.h"
#include "Position.h"
#include "Direction.h"
#include "Map.h"
#include "VisitLog.h"
#include "PriorityQueue.h"
#include "Dictionary.h"

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

int stepN = 0;

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
//    setWall(rMap, 1,2,1,3);
}

// check if a position is in stack or not
int isInStack(unsigned int row, unsigned int col) {
    // isInStack
    int i;
    for (i = rowStack.top; i > -1; i--) {
        if (rowStack.s[i] == row && colStack.s[i] == col)
            return i;
    }
    return -1;
}

int isInStack2(unsigned int pos[MAP_DIMS]) {
    int i;
    for (i = rowStack.top; i > -1; i--) {
        if (rowStack.s[i] == pos[ROW_CODE] && colStack.s[i] == pos[COL_CODE])
            return i;
    }
    return -1;
}

// find the deepest position in the stack which has unvisited neighbour
int getDeepestPos() {
    // getDeepestPos
    int i;
    for (i = rowStack.top; i > -1; i--) {
        if (hasUnvisitedNeighbour(map, visited, rowStack.s[i], colStack.s[i]))
            return i;
    }
    return -1;
}

void getNextPos() {
    // check if there is any unvisited neighbour (order: front -> left -> right)
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

    // if robot has just started, set the position behind the robot as the next position
    if (stepN == 1) {
        switch (robotDir) {
        case NORTH:
            nextPos[ROW_CODE] = robotPos[ROW_CODE] + 1;
            nextPos[COL_CODE] = robotPos[COL_CODE];
            break;
        case EAST:
            nextPos[ROW_CODE] = robotPos[ROW_CODE];
            nextPos[COL_CODE] = robotPos[COL_CODE] - 1;
            break;
        case WEST:
            nextPos[ROW_CODE] = robotPos[ROW_CODE];
            nextPos[COL_CODE] = robotPos[COL_CODE] + 1;
            break;
        case SOUTH:
            nextPos[ROW_CODE] = robotPos[ROW_CODE] - 1;
            nextPos[COL_CODE] = robotPos[COL_CODE];
            break;
        }
        push(&rowStack, nextPos[ROW_CODE]);
        push(&colStack, nextPos[COL_CODE]);
        return;
    }

    // backtrack
    pop(&rowStack);
    pop(&colStack);

    // check if stack is empty
    if (isEmptyStack(rowStack)) {
        nextPos[ROW_CODE] = -1;
        nextPos[COL_CODE] = -1;
        return;
    }

    // check if previous position has unvisited neighbour
    unsigned int prevRow = head(rowStack);
    unsigned int prevCol = head(colStack);
    if (hasUnvisitedNeighbour(map, visited, prevRow, prevCol)) {
        nextPos[ROW_CODE] = prevRow;
        nextPos[COL_CODE] = prevCol;
        return;
    }

    // find the deepest position in the stack which has unvisited neighbour
    int deepestIndex = getDeepestPos();

    // test if one of the neighbours of current position is in stack
    int index = 1000;
    unsigned int backRow = -1;
    unsigned int backCol = -1;
    int i, r, c, sid;
    //// for each neighbour
    for (i = -2; i < 3; i++) {
        if (i != 0) {
            r = robotPos[ROW_CODE] + i/2;
            c = robotPos[COL_CODE] + i%2;
            if (r != prevRow || c != prevCol) {
                if (isValidPos(r, c) && !checkWall(map, r, c, robotPos[ROW_CODE], robotPos[COL_CODE])) {
                    sid = isInStack(r, c);
                    if (sid > -1 && sid >= deepestIndex && sid < index) {
                        index = sid;
                    }
                }
            }
        }
    }

    if (index < 1000) {
        popToIndex(&rowStack, index);
        popToIndex(&colStack, index);
    }

    nextPos[ROW_CODE] = head(rowStack);
    nextPos[COL_CODE] = head(colStack);
}

int step() {
    // mark current position as visited
    setVisited2(visited, robotPos);

    // get sensors
    getSensors(sensors, rMap, robotPos, robotDir);

    // update wall information
    updateWall(map, sensors, robotPos, robotDir);

    // decide next position to go
    getNextPos();

    // get action
    int action = getAction(robotPos, nextPos, robotDir);

    return action;
}

void move() {
    // update robot direction
    robotDir = getNewDirection(robotPos, nextPos);

    // update robot position
    robotPos[ROW_CODE] = nextPos[ROW_CODE];
    robotPos[COL_CODE] = nextPos[COL_CODE];
}

int main()
{
    Dict dict;
    initDict(&dict);

    addKey(&dict, 0, 1, 3);
    addKey(&dict, 2, 33, 2);
    addKey(&dict, 2, 0, 2);
    addKey(&dict, 2, 3, 5);

    deleteKey(&dict, 0, 1);
    deleteKey(&dict, 22, 22);

    printDict(dict);

    /******************* DEMO ***************************

    // initialize and build real map
    mapInit(rMap);
    buildRealMap();

    // initialize map
    mapInit(map);

    // initialize visiting log
    visitLogInit(visited);

    // set robot position and direction
    setPos(startPos, 0, 2);
    setPos(robotPos, 0, 2);
    setDirection(&robotDir, NORTH);

    // set human position
    setPos(humanPos, 1, 4);
    setVisited2(visited, humanPos);

    // initialize stacks
    stackInit(&rowStack);
    stackInit(&colStack);
    push(&rowStack, robotPos[ROW_CODE]);
    push(&colStack, robotPos[COL_CODE]);

    // run
    int action;
    printf("%-5s | %-10s | %-10s | %-s\n", "Step", "Position", "Direction", "Action");
    while (TRUE) {
        stepN++;

//        printStack(rowStack);
//        printStack(colStack);

        action = step();

        printf("%-5d | (%-d, %-d) | ", stepN, robotPos[ROW_CODE], robotPos[COL_CODE]);
        printDirection(robotDir);
        printf(" | ");
        printAction(action);
        printf("\n");

        if (isValidPos2(nextPos)) {
            move();
        }
        else
            break;
        getchar();
    }

    printf("Real map: \n");
    printMap(rMap);
    printf("Explored map: \n");
    printMap(map);

    // TODO mark the corner positions in the visited array

    // TODO reset stacks to reuse them as the solution stacks

    // TODO call function to find the path to move the person to the final goal

    /*********************************************************/
    return 0;
}

// TODO implement the function to find a solution for rescuing the person
int findSolution(unsigned int goalRow, unsigned int goalCol, unsigned int prevGoalRow, unsigned int prevGoalCol) {
    // TODO get subGoals and for each subGoal
    // ...

    return FALSE;
}
