#include <stdio.h>
#include "Constants.h"

struct stack {
    unsigned int s[STACK_SIZE];
    int top;
};

void stackInit(struct stack * st);
void push(struct stack * st, unsigned int item);
unsigned int pop(struct stack * st);
unsigned int popToIndex(struct stack * st, int index);
unsigned int head(struct stack st);
int isEmptyStack(struct stack st);
void printStack(struct stack st);
