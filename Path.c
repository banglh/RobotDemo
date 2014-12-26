#include "Path.h"
#include <math.h>

unsigned int estimateCost(int startRow, int startCol, int endRow, int endCol) {
    // manhattan distance
    return abs(startRow - endRow) + abs(startCol - endCol);
}

unsigned int estimateCost2(Position startPos, Position endPos) {
    return abs(startPos.row - endPos.row) + abs(startPos.col - endPos.col);
}

int findPath(unsigned int map[N_ROW][N_COL][N_WALL], PosTrack * posTr, int startRow, int startCol, int endRow, int endCol, int humanRow, int humanCol) {
    // TODO implement findPath
    PriorityQueue exploreQueue;
    Dict costDict;

    // init queue and dictionary
    queueInit(&exploreQueue);
    initDict(&costDict);

    // initialization
    QueueElement e = newQueueElement(startRow, startCol, 0);
    enqueue(&exploreQueue, e);
    addKey(&costDict, startRow, startCol, 0);

    // start A* search
    while (!isEmptyQueue(exploreQueue)) {
//        printQueue(exploreQueue);
//        printDict(costDict);

        // pick the current best node from queue
        e = dequeue(&exploreQueue);

//        printf("explore node: (%d, %d)\n", e.row, e.col);

        // if we reach the end position
        if (e.pos.row == endRow && e.pos.col == endCol)
            return TRUE;

        // otherwise, for each neighbor of the current node
        int i, nbRow, nbCol, newCost;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                nbRow = e.pos.row + i/2;
                nbCol = e.pos.col + i%2;
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos(nbRow, nbCol) && !isSamePos(nbRow, nbCol, humanRow, humanCol) && !checkWall(map, e.pos.row, e.pos.col, nbRow, nbCol)) {
                    newCost = getValue(costDict, e.pos.row, e.pos.col) + ELEMENT_COST;

                    if (!hasKey(costDict, nbRow, nbCol) || newCost < getValue(costDict, nbRow, nbCol)) {
                        addKey(&costDict, nbRow, nbCol, newCost);
                        priority = newCost + estimateCost(nbRow, nbCol, endRow, endCol);
                        enqueue(&exploreQueue, newQueueElement(nbRow, nbCol, priority));
                        addTrack(posTr, nbRow, nbCol, e.pos.row, e.pos.col);
                    }
                }
            }
        }

//        getchar();
    }

    return FALSE;
}

int findPath2(unsigned int map[N_ROW][N_COL][N_WALL], PosTrack * posTr, Position startPos, Position endPos, Position humanPos) {
    // implement hasPath
    PriorityQueue exploreQueue;
    Dict costDict;

    // init queue and dictionary
    queueInit(&exploreQueue);
    initDict(&costDict);

    // initialization
    QueueElement e = newQueueElement2(startPos, 0);
    enqueue(&exploreQueue, e);
    addKey2(&costDict, startPos, 0);

    // start A* search
    while (!isEmptyQueue(exploreQueue)) {
//        printQueue(exploreQueue);
//        printDict(costDict);

        // pick the current best node from queue
        e = dequeue(&exploreQueue);

//        printf("explore node: (%d, %d)\n", e.row, e.col);

        // if we reach the end position
        if (isSamePos2(e.pos, endPos))
            return TRUE;

        // otherwise, for each neighbor of the current node
        int i, newCost;
        Position nbPos;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                setPos(&nbPos, e.pos.row + i/2, e.pos.col + i%2);
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos2(nbPos) && !isSamePos2(nbPos, humanPos) && !checkWall2(map, e.pos, nbPos)) {
                    newCost = getValue2(costDict, e.pos) + ELEMENT_COST;

                    if (!hasKey2(costDict, nbPos) || newCost < getValue2(costDict, nbPos)) {
                        addKey2(&costDict, nbPos, newCost);
                        priority = newCost + estimateCost2(nbPos, endPos);
                        enqueue(&exploreQueue, newQueueElement2(nbPos, priority));
                        addTrack2(posTr, nbPos, e.pos);
                    }
                }
            }
        }

//        getchar();
    }

    return FALSE;
}

int hasPath(unsigned int map[N_ROW][N_COL][N_WALL], int startRow, int startCol, int endRow, int endCol, int humanRow, int humanCol) {
    // implement hasPath
    PriorityQueue exploreQueue;
    Dict costDict;

    // init queue and dictionary
    queueInit(&exploreQueue);
    initDict(&costDict);

    // initialization
    QueueElement e = newQueueElement(startRow, startCol, 0);
    enqueue(&exploreQueue, e);
    addKey(&costDict, startRow, startCol, 0);

    // start A* search
    while (!isEmptyQueue(exploreQueue)) {
//        printQueue(exploreQueue);
//        printDict(costDict);

        // pick the current best node from queue
        e = dequeue(&exploreQueue);

//        printf("explore node: (%d, %d)\n", e.row, e.col);

        // if we reach the end position
        if (e.pos.row == endRow && e.pos.col == endCol)
            return TRUE;

        // otherwise, for each neighbor of the current node
        int i, nbRow, nbCol, newCost;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                nbRow = e.pos.row + i/2;
                nbCol = e.pos.col + i%2;
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos(nbRow, nbCol) && !isSamePos(nbRow, nbCol, humanRow, humanCol) && !checkWall(map, e.pos.row, e.pos.col, nbRow, nbCol)) {
                    newCost = getValue(costDict, e.pos.row, e.pos.col) + ELEMENT_COST;

                    if (!hasKey(costDict, nbRow, nbCol) || newCost < getValue(costDict, nbRow, nbCol)) {
                        addKey(&costDict, nbRow, nbCol, newCost);
                        priority = newCost + estimateCost(nbRow, nbCol, endRow, endCol);
                        enqueue(&exploreQueue, newQueueElement(nbRow, nbCol, priority));
                    }
                }
            }
        }

//        getchar();
    }

    return FALSE;
}

int hasPath2(unsigned int map[N_ROW][N_COL][N_WALL], Position startPos, Position endPos, Position humanPos) {
    // implement hasPath
    PriorityQueue exploreQueue;
    Dict costDict;

    // init queue and dictionary
    queueInit(&exploreQueue);
    initDict(&costDict);

    // initialization
    QueueElement e = newQueueElement2(startPos, 0);
    enqueue(&exploreQueue, e);
    addKey2(&costDict, startPos, 0);

    // start A* search
    while (!isEmptyQueue(exploreQueue)) {
//        printQueue(exploreQueue);
//        printDict(costDict);

        // pick the current best node from queue
        e = dequeue(&exploreQueue);

//        printf("explore node: (%d, %d)\n", e.pos.row, e.pos.col);

        // if we reach the end position
        if (isSamePos2(e.pos, endPos))
            return TRUE;

        // otherwise, for each neighbor of the current node
        int i, newCost;
        Position nbPos;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                setPos(&nbPos, e.pos.row + i/2, e.pos.col + i%2);
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos2(nbPos)
                    && !isSamePos2(nbPos, humanPos)
                    && !checkWall2(map, e.pos, nbPos)) {
                    newCost = getValue2(costDict, e.pos) + ELEMENT_COST;

                    if (!hasKey2(costDict, nbPos) || newCost < getValue2(costDict, nbPos)) {
                        addKey2(&costDict, nbPos, newCost);
                        priority = newCost + estimateCost2(nbPos, endPos);
//                        printf("endqueued: ");
//                        printPos(nbPos);
//                        printf("\n");
                        enqueue(&exploreQueue, newQueueElement2(nbPos, priority));
                    }
                }
            }
        }

//        getchar();
    }

    return FALSE;
}

int getMoveCost2(unsigned int map[N_ROW][N_COL][N_WALL], Position startPos, Position endPos, Position humanPos) {
    // implement hasPath
    PriorityQueue exploreQueue;
    Dict costDict;

    // init queue and dictionary
    queueInit(&exploreQueue);
    initDict(&costDict);

    // initialization
    QueueElement e = newQueueElement2(startPos, 0);
    enqueue(&exploreQueue, e);
    addKey2(&costDict, startPos, 0);

    // start A* search
    while (!isEmptyQueue(exploreQueue)) {
//        printQueue(exploreQueue);
//        printDict(costDict);

        // pick the current best node from queue
        e = dequeue(&exploreQueue);

//        printf("explore node: (%d, %d)\n", e.row, e.col);

        // if we reach the end position
        if (isSamePos2(e.pos, endPos))
            return getValue2(costDict, e.pos);

        // otherwise, for each neighbor of the current node
        int i, newCost;
        Position nbPos;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                setPos(&nbPos, e.pos.row + i/2, e.pos.col + i%2);
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos2(nbPos) && !isSamePos2(nbPos, humanPos) && !checkWall2(map, e.pos, nbPos)) {
                    newCost = getValue2(costDict, e.pos) + ELEMENT_COST;

                    if (!hasKey2(costDict, nbPos) || newCost < getValue2(costDict, nbPos)) {
                        addKey2(&costDict, nbPos, newCost);
                        priority = newCost + estimateCost2(nbPos, endPos);
                        enqueue(&exploreQueue, newQueueElement2(nbPos, priority));
                    }
                }
            }
        }

//        getchar();
    }

    return MAX_VALUE;
}
