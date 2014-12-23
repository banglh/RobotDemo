#include <stdio.h>
#include "Constants.h"

typedef struct {
    unsigned int row;
    unsigned int col;
    unsigned int priority;
} QueueElement;

typedef struct {
    QueueElement q[QUEUE_SIZE];
    int qsize;
} PriorityQueue;

/******************* function for priority queue *******************/
void queueInit(PriorityQueue * pqueue);
QueueElement dequeue(PriorityQueue * pqueue);
void enqueue(PriorityQueue * pqueue, QueueElement element);
int isEmptyQueue(PriorityQueue pqueue);
void printQueue(PriorityQueue pqueue);

QueueElement newQueueElement(unsigned int row, unsigned int col, unsigned int priority);
void setQueueElement(QueueElement *qe, unsigned int row, unsigned int col, unsigned int priority);
