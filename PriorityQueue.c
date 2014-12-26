#include "PriorityQueue.h"

void queueInit(PriorityQueue * pqueue) {
    // queueInit
    (*pqueue).qsize = 0;
}

QueueElement dequeue(PriorityQueue * pqueue) {
    // if the queue is empty, return an invalid element
    if (isEmptyQueue(*pqueue)) {
        QueueElement e;
        e.pos.row = N_ROW;
        e.pos.col = N_COL;
        return e;
    }

    int minIndex = -1;
    int minPriority = 1000;
    int i;
    for (i = 0; i < (*pqueue).qsize; i++) {
        if (((*pqueue).q[i]).priority < minPriority) {
            minIndex = i;
            minPriority = ((*pqueue).q[i]).priority;
        }
    }

    // get the element to dequeue
    QueueElement e = (*pqueue).q[minIndex];

    // update queue
    (*pqueue).q[minIndex] = (*pqueue).q[(*pqueue).qsize - 1];
    (*pqueue).qsize--;

    return e;
}

void enqueue(PriorityQueue * pqueue, QueueElement element) {
    // enqueue
    (*pqueue).q[(*pqueue).qsize] = element;
    (*pqueue).qsize++;
}

int isEmptyQueue(PriorityQueue pqueue) {
    if (pqueue.qsize == 0)
        return TRUE;
    else
        return FALSE;
}

void printQueue(PriorityQueue pqueue) {
    int i;
    printf("\n%-5s | %-s\n", "position", "priority");
    for (i = 0; i < pqueue.qsize; i++) {
        printPos(pqueue.q[i].pos);
        printf(" | %-d\n", pqueue.q[i].priority);
    }
    printf("\n");
}

QueueElement newQueueElement(int row, int col, unsigned int priority) {
    QueueElement e;
    e.pos.row = row;
    e.pos.col = col;
    e.priority = priority;
    return e;
}

QueueElement newQueueElement2(Position pos, unsigned int priority) {
    QueueElement e;
    e.pos = pos;
    e.priority = priority;
    return e;
}

void setQueueElement(QueueElement *qe, int row, int col, unsigned int priority) {
    (*qe).pos.row = row;
    (*qe).pos.col = col;
    (*qe).priority = priority;
}
