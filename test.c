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

// function to check if a position can be a subGoal or not
int isSubGoal(unsigned int checkRow, unsigned int checkCol, unsigned int curGoalRow, unsigned int curGoalCol, unsigned int prevGoalRow, unsigned int prevGoalCol) {
    /* criteria
    1. neighbor of current goal
    2. Not the final goal
    3. Not at the corner
    4. There is no wall between the subGoal and the position A (subGoal is between A and the goal)
    5. After robot move the person from subGoal to the current goal, it can continue with the prevGoal (no need to check when goal == prevGoal == final goal)
    6. Assume subGoal == prevGoal, if robot still can move person from subGoal back to current goal after move it from current goal to subGoal  invalid subGoal
    */

    // check if the candidate is the final goal
    if (isSamePos(checkRow, checkCol, goalPos.row, goalPos.col))
        return FALSE;

    // check if there is wall between current goal and the candidate position
    if (checkWall(map, checkRow, checkCol, curGoalRow, curGoalCol))
        return FALSE;

    // check if the candidate is a corner position
    if (isCornerPos(visited, checkRow, checkCol))
        return FALSE;

    // check if robot can move person from the candidate position to the current goal
    if (!isMovable(map, checkRow, checkCol, curGoalRow, curGoalCol))
        return FALSE;

    // check criterion 5
    if (!isSamePos(goalPos.row, goalPos.col, prevGoalRow, prevGoalCol)) {
        // check if there is a path from the candidate position to the position X from which robot move person from the current goal to the prevGoal
        // given the human is at the current goal
        unsigned int rowX = curGoalRow + curGoalRow - prevGoalRow;
        unsigned int colX = curGoalCol + curGoalCol - prevGoalCol;
        if (!hasPath(map, checkRow, checkCol, rowX, colX, curGoalRow, curGoalCol))
            return FALSE;
    }

    // check criterion 6
    if (isSamePos(checkRow, checkCol, prevGoalRow, prevGoalCol)) {
        // check if there is a path from current goal to the position from which robot move person given person position is at subGoal
        unsigned int xRow = checkRow + checkRow - curGoalRow;
        unsigned int xCol = checkCol + checkCol - curGoalCol;
        if (hasPath(map, curGoalRow, curGoalCol, xRow, xCol, checkRow, checkCol))
            return FALSE;
    }

    // all the criteria is satisfied
    return TRUE;
}

// function to get subGoal candidates
void getCandidates(int candidates[4][MAP_DIMS], unsigned int curGoalRow, unsigned int curGoalCol, unsigned int prevGoalRow, unsigned int prevGoalCol) {
    // get candidates
    int j = 0;
    int i;
    for (i = -2; i < 3; i++) {
        if (i != 0) {
            candidates[j][ROW_CODE] = curGoalRow + i/2;
            candidates[j][COL_CODE] = curGoalCol + i%2;
            j++;
        }
    }

    // sort candidates
    int tmpRow, tmpCol, costi, costj;
    int acrossRow = curGoalRow + curGoalRow - prevGoalRow;
    int acrossCol = curGoalCol + curGoalCol - prevGoalCol;
    for (i = 0; i < 3; i++) {
        for (j = i+1; j < 4; j++) {
            // get cost i
            if (isValidPos(candidates[i][ROW_CODE], candidates[i][COL_CODE]))
                costi = estimateCost(candidates[i][ROW_CODE], candidates[i][COL_CODE], humanPos.row, humanPos.col);
            else
                costi = MAX_VALUE;

            // get cost j
            if (isValidPos(candidates[j][ROW_CODE], candidates[j][COL_CODE]))
                costj = estimateCost(candidates[j][ROW_CODE], candidates[j][COL_CODE], humanPos.row, humanPos.col);
            else
                costj = MAX_VALUE;

            // exchange if costi > costj
            if (costi > costj) {
                tmpRow = candidates[i][ROW_CODE];
                tmpCol = candidates[i][COL_CODE];
                candidates[i][ROW_CODE] = candidates[j][ROW_CODE];
                candidates[i][COL_CODE] = candidates[j][COL_CODE];
                candidates[j][ROW_CODE] = tmpRow;
                candidates[j][COL_CODE] = tmpCol;
            }

            if (costi == costj && costi != MAX_VALUE) {
                if (candidates[j][ROW_CODE] == acrossRow && candidates[j][COL_CODE] == acrossCol) {
                    tmpRow = candidates[i][ROW_CODE];
                    tmpCol = candidates[i][COL_CODE];
                    candidates[i][ROW_CODE] = candidates[j][ROW_CODE];
                    candidates[i][COL_CODE] = candidates[j][COL_CODE];
                    candidates[j][ROW_CODE] = tmpRow;
                    candidates[j][COL_CODE] = tmpCol;
                }
            }
        }
    }
}

// implement the function to find a solution for rescuing the person
int findSolution(unsigned int goalRow, unsigned int goalCol, unsigned int prevGoalRow, unsigned int prevGoalCol, int depth) {
    // limit the depth of tree search
    if (depth == MAX_DEPTH)
        return FALSE;

    int candidates[4][MAP_DIMS];

    // get candidates
    getCandidates(candidates, goalRow, goalCol, prevGoalRow, prevGoalCol);

    /*******
    printf("current goal: (%d, %d), prevGoal: (%d, %d)\n", goalRow, goalCol, prevGoalRow, prevGoalCol);
    int i;
    for (i = 0; i < 4; i++) {
        printf("candidate %d: (%d, %d), ", i, candidates[i][ROW_CODE], candidates[i][COL_CODE]);
    }
    printf("\ndepth = %d", depth);
    printf("\n\n");
//    getchar();
    /*******/

    // for each candidate
    int c, cRow, cCol;
    for (c = 0; c < 4; c++) {
        cRow = candidates[c][ROW_CODE];
        cCol = candidates[c][COL_CODE];
        if (isValidPos(cRow, cCol)) {
            if (isSubGoal(cRow, cCol, goalRow, goalCol, prevGoalRow, prevGoalCol)) {
                // push subGoal to stack
                push(&posStack, newPosition(cRow, cCol));

                // check element problem (when the subGoal is the initial human position)
                if (isSamePos(cRow, cCol, humanPos.row, humanPos.col)) {
                    int rowX = cRow + cRow - goalRow;
                    int colX = cCol + cCol - goalCol;
                    if (hasPath(map, startPos.row, startPos.col, rowX, colX, cRow, cCol)) {
                        // there is a solution
                        return TRUE;
                    } else {
                        // solution invalid
                        pop(&posStack);
                        return FALSE;
                    }
                }

                // otherwise, solve a sub problem with the subGoal as the goal and the current goal as the prevGoal
                int hasSolution = findSolution(cRow, cCol, goalRow, goalCol, depth + 1);

                if (hasSolution)
                    return TRUE;
                else {
                    pop(&posStack);
                    continue;
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

    // reset stacks to reuse them as the solution stacks
    resetStack(&posStack);

    // call function to find the path to move the person to the final goal
    int hasSolution;
    if (!isCornerPos2(visited, humanPos)
        && hasPath2(map, humanPos, goalPos, newPosition(N_ROW, N_COL))
        && hasPath2(map, humanPos, startPos, newPosition(N_ROW, N_COL))) {
            hasSolution = findSolution(goalPos.row, goalPos.col, goalPos.row, goalPos.col, 0);
    } else {
        hasSolution = FALSE;
    }

    if (hasSolution) {
        printf("Found a solution\n");
        printStack(posStack);
    } else {
        printf("There is no solution\n");
    }
    /*********************************************************/

    PosTrack posTr;
    initPosTrack(&posTr);

    Position p1 = newPosition(3,0);
    Position p2 = newPosition(3,5);

    int a = findPath2(map, &posTr, p1, p2, newPosition(2,2));

    printf("\na = %d\n", a);
    printPosTrack(posTr);

    return 0;
}
