#include <stdio.h>
#include <stdlib.h>
#include "Demo.h"
#include "Stack.h"
#include "Position.h"
#include "Action.h"
#include "Direction.h"
#include "Map.h"
#include "VisitLog.h"
//#include "PriorityQueue.h"
//#include "Dictionary.h"
//#include "Path.h"

// real map
unsigned int rMap[N_ROW][N_COL][N_WALL];

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL][N_WALL];
unsigned int visited[N_ROW][N_COL];

unsigned int sensors[N_SENSORS];

// position of the robot
//unsigned int startPos[MAP_DIMS];
//unsigned int robotPos[MAP_DIMS];
//unsigned int nextPos[MAP_DIMS];
Position startPos, robotPos, nextPos, humanPos, goalPos;

// stacks
//struct stack rowStack;
//struct stack colStack;
Stack posStack;

// position of the person
//unsigned int humanPos[MAP_DIMS];
// position of the goal
//unsigned int goalPos[MAP_DIMS];

// robot direction
unsigned int robotDir;

int stepN = 0;

void buildRealMap() {
    setWall(rMap, 1,0,1,1);
    setWall(rMap, 2,1,3,1);
    setWall(rMap, 0,2,0,3);
    setWall(rMap, 2,2,2,3);
    setWall(rMap, 3,2,3,3);
    setWall(rMap, 1,3,2,3);
    setWall(rMap, 0,4,0,5);
    setWall(rMap, 0,5,1,5);
}

// check if a position is in stack or not
int isInStack(unsigned int row, unsigned int col) {
    // isInStack
    int i;
    for (i = posStack.top; i > -1; i--) {
        if (posStack.s[i].row == row && posStack.s[i].col == col)
            return i;
    }
    return -1;
}

int isInStack2(Position pos) {
    int i;
    for (i = posStack.top; i > -1; i--) {
        if (isSamePos2(pos, posStack.s[i]))
            return i;
    }
    return -1;
}

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
                    sid = isInStack(r, c);
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

void move() {
    // update robot direction
    robotDir = getNewDirection(robotPos, nextPos);

    // update robot position
    robotPos = nextPos;
}

// function to check if a position can be a subGoal or not
//int isSubGoal(unsigned int checkRow, unsigned int checkCol, unsigned int curGoalRow, unsigned int curGoalCol, unsigned int prevGoalRow, unsigned int prevGoalCol) {
//    /* criteria
//    1. neighbor of current goal
//    2. Not the final goal
//    3. Not at the corner
//    4. There is no wall between the subGoal and the position A (subGoal is between A and the goal)
//    5. After robot move the person from subGoal to the current goal, it can continue with the prevGoal (no need to check when goal == prevGoal == final goal)
//    6. Assume subGoal == prevGoal, if robot still can move person from subGoal back to current goal after move it from current goal to subGoal  invalid subGoal
//    */
//
//    // check if the candidate is the final goal
//    if (isSamePos(checkRow, checkCol, goalPos.row, goalPos.col))
//        return FALSE;
//
//    // check if there is wall between current goal and the candidate position
//    if (checkWall(map, checkRow, checkCol, curGoalRow, curGoalCol))
//        return FALSE;
//
//    // check if the candidate is a corner position
//    if (isCornerPos(visited, checkRow, checkCol))
//        return FALSE;
//
//    // check if robot can move person from the candidate position to the current goal
//    if (!isMovable(map, checkRow, checkCol, curGoalRow, curGoalCol))
//        return FALSE;
//
//    // check criterion 5
//    if (!isSamePos(goalPos.row, goalPos.col, prevGoalRow, prevGoalCol)) {
//        // check if there is a path from the candidate position to the position X from which robot move person from the current goal to the prevGoal
//        // given the human is at the current goal
//        unsigned int rowX = curGoalRow + curGoalRow - prevGoalRow;
//        unsigned int colX = curGoalCol + curGoalCol - prevGoalCol;
//        if (!hasPath(map, checkRow, checkCol, rowX, colX, curGoalRow, curGoalCol))
//            return FALSE;
//    }
//
//    // check criterion 6
//    if (isSamePos(checkRow, checkCol, prevGoalRow, prevGoalCol)) {
//        // check if there is a path from current goal to the position from which robot move person given person position is at subGoal
//        unsigned int xRow = checkRow + checkRow - curGoalRow;
//        unsigned int xCol = checkCol + checkCol - curGoalCol;
//        if (hasPath(map, curGoalRow, curGoalCol, xRow, xCol, checkRow, checkCol))
//            return FALSE;
//    }
//
//    // all the criteria is satisfied
//    return TRUE;
//}
//
//// function to get subGoal candidates
//void getCandidates(int candidates[4][MAP_DIMS], unsigned int curGoalRow, unsigned int curGoalCol, unsigned int prevGoalRow, unsigned int prevGoalCol) {
//    // get candidates
//    int j = 0;
//    int i;
//    for (i = -2; i < 3; i++) {
//        if (i != 0) {
//            candidates[j].row = curGoalRow + i/2;
//            candidates[j].col = curGoalCol + i%2;
//            j++;
//        }
//    }
//
//    // sort candidates
//    int tmpRow, tmpCol, costi, costj;
//    int acrossRow = curGoalRow + curGoalRow - prevGoalRow;
//    int acrossCol = curGoalCol + curGoalCol - prevGoalCol;
//    for (i = 0; i < 3; i++) {
//        for (j = i+1; j < 4; j++) {
//            // get cost i
//            if (isValidPos(candidates[i].row, candidates[i].col))
//                costi = estimateCost(candidates[i][ROW_CODE], candidates[i].col, humanPos[ROW_CODE], humanPos.col);
//            else
//                costi = MAX_VALUE;
//
//            // get cost j
//            if (isValidPos(candidates[j][ROW_CODE], candidates[j].col))
//                costj = estimateCost(candidates[j][ROW_CODE], candidates[j].col, humanPos[ROW_CODE], humanPos.col);
//            else
//                costj = MAX_VALUE;
//
//            // exchange if costi > costj
//            if (costi > costj) {
//                tmpRow = candidates[i][ROW_CODE];
//                tmpCol = candidates[i].col;
//                candidates[i][ROW_CODE] = candidates[j][ROW_CODE];
//                candidates[i].col = candidates[j].col;
//                candidates[j][ROW_CODE] = tmpRow;
//                candidates[j].col = tmpCol;
//            }
//
//            if (costi == costj && costi != MAX_VALUE) {
//                if (candidates[j][ROW_CODE] == acrossRow && candidates[j].col == acrossCol) {
//                    tmpRow = candidates[i][ROW_CODE];
//                    tmpCol = candidates[i].col;
//                    candidates[i][ROW_CODE] = candidates[j][ROW_CODE];
//                    candidates[i].col = candidates[j].col;
//                    candidates[j][ROW_CODE] = tmpRow;
//                    candidates[j].col = tmpCol;
//                }
//            }
//        }
//    }
//}
//
//// implement the function to find a solution for rescuing the person
//// [Bug fixed] infinitive function call when there is no solution
//int findSolution(unsigned int goalRow, unsigned int goalCol, unsigned int prevGoalRow, unsigned int prevGoalCol, int depth) {
//    // limit the depth of tree search
//    if (depth == MAX_DEPTH)
//        return FALSE;
//
//    int candidates[4][MAP_DIMS];
//
//    // get candidates
//    getCandidates(candidates, goalRow, goalCol, prevGoalRow, prevGoalCol);
//
//    /*******/
//    printf("current goal: (%d, %d), prevGoal: (%d, %d)\n", goalRow, goalCol, prevGoalRow, prevGoalCol);
//    int i;
//    for (i = 0; i < 4; i++) {
//        printf("candidate %d: (%d, %d), ", i, candidates[i][ROW_CODE], candidates[i].col);
//    }
//    printf("\ndepth = %d", depth);
//    printf("\n\n");
////    getchar();
//    /*******/
//
//    // for each candidate
//    int c, cRow, cCol;
//    for (c = 0; c < 4; c++) {
//        cRow = candidates[c][ROW_CODE];
//        cCol = candidates[c].col;
//        if (isValidPos(cRow, cCol)) {
//            if (isSubGoal(cRow, cCol, goalRow, goalCol, prevGoalRow, prevGoalCol)) {
//                // push subGoal to stack
//                push(&rowStack, cRow);
//                push(&colStack, cCol);
//
//                // check element problem (when the subGoal is the initial human position)
//                if (isSamePos(cRow, cCol, humanPos[ROW_CODE], humanPos.col)) {
//                    int rowX = cRow + cRow - goalRow;
//                    int colX = cCol + cCol - goalCol;
//                    if (hasPath(map, startPos[ROW_CODE], startPos.col, rowX, colX, cRow, cCol)) {
//                        // there is a solution
//                        return TRUE;
//                    } else {
//                        // solution invalid
//                        pop(&rowStack);
//                        pop(&colStack);
//                        return FALSE;
//                    }
//                }
//
//                // otherwise, solve a sub problem with the subGoal as the goal and the current goal as the prevGoal
//                int hasSolution = findSolution(cRow, cCol, goalRow, goalCol, depth + 1);
//
//                if (hasSolution)
//                    return TRUE;
//                else {
//                    pop(&rowStack);
//                    pop(&colStack);
//                    continue;
//                }
//            }
//        }
//    }
//
//    return FALSE;
//}

int main()
{
    /******************* DEMO ***************************/

    /********** Phase 1: Get map information ***********/
    // initialize and build real map
    mapInit(rMap);
    buildRealMap();

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
    setPos(&goalPos, 0,4);

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
            move();
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

    /********** Phase 2: Plan to rescue ***********
    // mark the corner positions in the visited array
    getCornersPos(map, visited);

    // reset stacks to reuse them as the solution stacks
    resetStack(&rowStack);
    resetStack(&colStack);

    // call function to find the path to move the person to the final goal
    int hasSolution;
    if (!isCornerPos(visited, humanPos[ROW_CODE], humanPos.col)
        && hasPath(map, humanPos[ROW_CODE], humanPos.col, goalPos[ROW_CODE], goalPos.col, -1, -1)
        && hasPath(map, humanPos[ROW_CODE], humanPos.col, startPos[ROW_CODE], startPos.col, -1, -1)) {
            hasSolution = findSolution(goalPos[ROW_CODE], goalPos.col, goalPos[ROW_CODE], goalPos.col, 0);
    } else {
        hasSolution = FALSE;
    }

    if (hasSolution) {
        printStack(rowStack);
        printStack(colStack);
    } else {
        printf("There is no solution\n");
    }
    /*********************************************************/

    return 0;
}
