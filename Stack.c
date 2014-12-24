#include "Stack.h"

void stackInit(struct stack * st) {
    (*st).top = -1;
}

void push(struct stack * st, unsigned int item) {
    (*st).top++;
    (*st).s[(*st).top] = item;
}

unsigned int pop(struct stack * st) {
    unsigned int item;
    item = (*st).s[(*st).top];
    (*st).top--;
    return item;
}

unsigned int popToIndex(struct stack * st, int index) {
    // popToIndex
    unsigned int item;
    if (index >= (*st).top) {
        item = (*st).s[(*st).top];
    } else if (index > -1) {
        item = (*st).s[index + 1];
        (*st).top = index;
    } else {
        item = (*st).s[0];
        (*st).top = -1;
    }
    return item;
}

unsigned int head(struct stack st) {
    if (isEmptyStack(st) == FALSE)
        return st.s[st.top];
    else
        return -1;
}

int isEmptyStack(struct stack st) {
    if (st.top == -1)
        return TRUE;
    else
        return FALSE;
}

void printStack(struct stack st) {
    int i;
    for (i = 0; i <= st.top; i++)
        printf("%d | ", st.s[i]);
    printf("\n");
}

void resetStack(struct stack *st) {
    (*st).top = -1;
}
