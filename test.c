#include <stdio.h>
#include <stdlib.h>
#include "Demo.h"
#include "Stack.h"
#include "Position.h"
#include "Action.h"
#include "Direction.h"
#include "Map.h"
#include "VisitLog.h"
#include "PriorityQueue.h"
#include "Dictionary.h"
#include "Path.h"
#include "GameDict.h"
#include "GameQueue.h"
#include "GameTrack.h"

// real map
unsigned int rMap[N_ROW][N_COL][N_WALL];

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL][N_WALL];
unsigned int visited[N_ROW][N_COL];

unsigned int sensors[N_SENSORS];

// position of the robot
Position startPos, robotPos, nextPos, humanPos, goalPos;

// stacks
Stack posStack;

// robot direction
unsigned int robotDir;

int stepN = 0;

// find the deepest position in the stack which has unvisited neighbour
int getDeepestPos() {
    // getDeepestPos
    int i;
    for (i = posStack.top; i > -1; i--) {
        if (hasUnvisitedNeighbour2(map, visited, posStack.s[i]))
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
            testRow = robotPos.row - 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        break;
    case EAST:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos.row - 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos.row + 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        break;
    case WEST:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos.row + 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos.row - 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        break;
    case SOUTH:
        // test front position
        if (wallInfo[FRONT]==0) {
            testRow = robotPos.row + 1;
            testCol = robotPos.col;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test left position
        if (wallInfo[LEFT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col + 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
                    return;
                }
            }
        }
        // test right position
        if (wallInfo[RIGHT]==0) {
            testRow = robotPos.row;
            testCol = robotPos.col - 1;
            if (isValidPos(testRow, testCol)) {
                if (isVisited(visited, testRow, testCol) == FALSE) {
                    setPos(&nextPos, testRow, testCol);
                    push(&posStack, nextPos);
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
            setPos(&nextPos, robotPos.row + 1, robotPos.col);
            break;
        case EAST:
            setPos(&nextPos, robotPos.row, robotPos.col - 1);
            break;
        case WEST:
            setPos(&nextPos, robotPos.row, robotPos.col + 1);
            break;
        case SOUTH:
            setPos(&nextPos, robotPos.row - 1, robotPos.col);
            break;
        }
        push(&posStack, nextPos);
        return;
    }

    // backtrack
    pop(&posStack);

    // check if stack is empty
    if (isEmptyStack(posStack)) {
        setPos(&nextPos, -1, -1);
        return;
    }

    // check if previous position has unvisited neighbour
    Position prevPos = head(posStack);
    if (hasUnvisitedNeighbour2(map, visited, prevPos)) {
        nextPos = prevPos;
        return;
    }

    // find the deepest position in the stack which has unvisited neighbour
    int deepestIndex = getDeepestPos();

    // test if one of the neighbours of current position is in stack
    int index = 1000;
    int i, r, c, sid;
    //// for each neighbour
    for (i = -2; i < 3; i++) {
        if (i != 0) {
            r = robotPos.row + i/2;
            c = robotPos.col + i%2;
            if (r != prevPos.row || c != prevPos.col) {
                if (isValidPos(r, c) && !checkWall(map, r, c, robotPos.row, robotPos.col)) {
                    sid = isInStack(posStack, r, c);
                    if (sid > -1 && sid >= deepestIndex && sid < index) {
                        index = sid;
                    }
                }
            }
        }
    }

    if (index < 1000) {
        popToIndex(&posStack, index);
    }

    nextPos = head(posStack);
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

int getTransitionCost(unsigned int map[N_ROW][N_COL][N_WALL], GameState startState, GameState endState) {

    // get the position X to which robot has to reach in order to move human
    unsigned int xRow = startState.hmPos.row + startState.hmPos.row - endState.hmPos.row;
    unsigned int xCol = startState.hmPos.col + startState.hmPos.col - endState.hmPos.col;

    // check and get path cost from robot position in start state to position X
    Position xPos = newPosition(xRow, xCol);
    int cost = getMoveCost2(map, startState.rbPos, xPos, startState.hmPos);

    if (cost != MAX_VALUE) {
        // plan A: not consider the path robot has to move
        return 1;

        // plan B: consider the path robot has to move
//        return cost;
    }
    else
        return MAX_VALUE;
}

int findSolutionAstar(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int corners[N_ROW][N_COL], GameTrack * gt, Position rbPos, Position hmPos, Position gPos) {
    // initialize queue
    GameQueue gq;
    gameQueueInit(&gq);

    // initialize cost dictionary
    GameDict stateCost;
    initGameDict(&stateCost);

    // initialize game track
    initGameTrack(gt);

    // put the initial game state to queue
    enGameQueue(&gq, newGameQueueElement2(rbPos, hmPos, 0));

    // save cost of initial state to dictionary
    addState2(&stateCost, rbPos, hmPos, 0);

    while (!isEmptyGameQueue(gq)) {
//        printGameQueue(gq);

        // get state to consider from game queue
        GameQueueElement curGameE = deGameQueue(&gq);
        GameState curState = curGameE.gs;

//        printGameState(curState);
//        printf("\n");

        // check if the human has been moved to the goal in this state
        if (isSamePos2(curState.hmPos, gPos)) {
            return TRUE;
        }

        // otherwise
        int i, nextHmRow, nextHmCol, newcost;
        unsigned int priority, transCost;
        Position nextHmP;
        // for each neighbor of considered state
        for (i = -2; i < 3; i++) {
            if (i != 0) {
                nextHmRow = curState.hmPos.row + i/2;
                nextHmCol = curState.hmPos.col + i%2;

                if (isValidPos(nextHmRow, nextHmCol)
                     && !checkWall(map, nextHmRow, nextHmCol, curState.hmPos.row, curState.hmPos.col)
                     && (!isCornerPos(corners, nextHmRow, nextHmCol) || isSamePos2(gPos, newPosition(nextHmRow, nextHmCol)))
                     && isMovable(map, curState.hmPos.row, curState.hmPos.col, nextHmRow, nextHmCol)) {
                        GameState state = newGameState(curState.hmPos, newPosition(nextHmRow, nextHmCol));
                        transCost = getTransitionCost(map, curState, state);
                        if (transCost != MAX_VALUE) {
                            newcost = getStateCost2(stateCost, curState.rbPos, curState.hmPos) + transCost;
                            if (newcost < getStateCost2(stateCost, state.rbPos, state.hmPos)) {
                                addState2(&stateCost, state.rbPos, state.hmPos, newcost);
                                priority = newcost + estimateCost2(state.hmPos, gPos);
                                enGameQueue(&gq, newGameQueueElement2(state.rbPos, state.hmPos, priority));
                                addStateTrack2(gt, state, curState);
                            }
                        }
                }
            }
        }
    }
    return FALSE;
}

int main()
{
    /******************* DEMO ***************************/

    /********** Phase 1: Get map information ***********/
    printf("Start phase 1\n");
    // initialize and build real map
    mapInit(rMap);
    buildRealMap(rMap);

    // initialize map
    mapInit(map);

    // initialize visiting log
    visitLogInit(visited);

    // set robot position and direction
    setPos(&startPos, 3, 0);
    setPos(&robotPos, 3, 0);
    setDirection(&robotDir, NORTH);

    // set human position
    setPos(&humanPos, 2,2);
    setVisited2(visited, humanPos);

    // set goal position
    setPos(&goalPos, 3,0);

    // initialize stacks
    stackInit(&posStack);
    push(&posStack, robotPos);

    // run
    int action;
    printf("%-5s | %-10s | %-10s | %-s\n", "Step", "Position", "Direction", "Action");
    while (TRUE) {
        stepN++;

//        printStack(posStack);

        action = step();

        printf("%-5d | (%-d, %-d) | ", stepN, robotPos.row, robotPos.col);
        printDirection(robotDir);
        printf(" | ");
        printAction(action);
        printf("\n");

        if (isValidPos2(nextPos)) {
            move(&robotPos, &nextPos, &robotDir);
        }
        else
            break;
//        getchar();
    }

    printf("Real map: \n");
    printMap(rMap);
    printf("Explored map: \n");
    printMap(map);
    printf("End of phase 1\n\n");
//    getchar();

    /********** Phase 2: Plan to rescue ***********/
    printf("Start phase 2\n");
    // mark the corner positions in the visited array
    getCornersPos(map, visited);

    // call function to find the path to move the person to the final goal
    int hasSolution;
    RescueSolution solution;
    GameTrack gt;
    initGameTrack(&gt);
    if (!isCornerPos2(visited, humanPos)
        && hasPath2(map, humanPos, goalPos, newPosition(N_ROW, N_COL))
        && hasPath2(map, humanPos, startPos, newPosition(N_ROW, N_COL))) {
            hasSolution = findSolutionAstar(map, visited, &gt, startPos, humanPos, goalPos);
    } else {
        hasSolution = FALSE;
    }

    if (hasSolution) {
        printf("Found a solution\n");
        getRescueSolution(gt, startPos, humanPos, goalPos, &solution);
        printRescueSolution(solution);
    } else {
        printf("There is no solution\n");
        printGameTrack(gt);
    }

    /*********************************************************/

    return 0;
}
