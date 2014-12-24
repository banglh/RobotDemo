#include "Path.h"
#include <math.h>

unsigned int estimateCost(unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol) {
    // manhattan distance
    return abs(startRow - endRow) + abs(startCol - endCol);
}

int findPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol) {
    // TODO implement findPath
}

int hasPath(unsigned int map[N_ROW][N_COL][N_WALL], unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol, unsigned int humanRow, unsigned int humanCol) {
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
        if (e.row == endRow && e.col == endCol)
            return TRUE;

        // otherwise, for each neighbor of the current node
        int i, nbRow, nbCol, newCost;
        unsigned int priority;

        for (i = -2; i < 3; i++) {
            if (i != 0) {
                nbRow = e.row + i/2;
                nbCol = e.col + i%2;
                // the neighbor node should satisfy: valid position, not the human position and there is no wall between it and the current node
                if (isValidPos(nbRow, nbCol) && !isSamePos(nbRow, nbCol, humanRow, humanCol) && !checkWall(map, e.row, e.col, nbRow, nbCol)) {
                    newCost = getValue(costDict, e.row, e.col) + ELEMENT_COST;

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
