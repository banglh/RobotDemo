#ifndef __PRIORITY_QUEUE_H
#define __PRIORITY_QUEUE_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    Position pos;
    unsigned int priority;
} QueueElement;

typedef struct {
    QueueElement q[QUEUE_SIZE];
    int qsize;
} PriorityQueue;

void queueInit(PriorityQueue * pqueue);
QueueElement dequeue(PriorityQueue * pqueue);
void enqueue(PriorityQueue * pqueue, QueueElement element);
int isEmptyQueue(PriorityQueue pqueue);
void printQueue(PriorityQueue pqueue);

QueueElement newQueueElement(int row, int col, unsigned int priority);
QueueElement newQueueElement2(Position pos, unsigned int priority);
void setQueueElement(QueueElement *qe, int row, int col, unsigned int priority);

#endif // __PRIORITY_QUEUE_H
