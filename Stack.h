#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include "Constants.h"
#include "Position.h"

typedef struct {
    Position s[STACK_SIZE];
    int top;
} Stack;

void stackInit(Stack * st);
void push(Stack * st, Position item);
Position pop(Stack * st);
Position popToIndex(Stack * st, int index);
Position head(Stack st);
int isEmptyStack(Stack st);
void printStack(Stack st);
void resetStack(Stack *st);
int isInStack(Stack st, int row, int col);
int isInStack2(Stack st, Position pos);
#endif
