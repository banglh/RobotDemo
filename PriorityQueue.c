#include "PriorityQueue.h"

void queueInit(PriorityQueue * pqueue) {
    // TODO queueInit
    (*pqueue).qsize = 0;
}

QueueElement dequeue(PriorityQueue * pqueue) {
    // TODO dequeue
    // if the queue is empty, return an invalid element
    if (isEmptyQueue(*pqueue)) {
        QueueElement e;
        e.row = -1;
        e.col = -1;
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
    // TODO enqueue
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
    printf("\n%-5s | %-5s | %-s\n", "row", "col", "priority");
    for (i = 0; i < pqueue.qsize; i++) {
        printf("%-5d | %-5d | %-d\n", pqueue.q[i].row, pqueue.q[i].col, pqueue.q[i].priority);
    }
    printf("\n");
}

QueueElement newQueueElement(unsigned int row, unsigned int col, unsigned int priority) {
    QueueElement e;
    e.row = row;
    e.col = col;
    e.priority = priority;
    return e;
}

void setQueueElement(QueueElement *qe, unsigned int row, unsigned int col, unsigned int priority) {
    (*qe).row = row;
    (*qe).col = col;
    (*qe).priority = priority;
}
