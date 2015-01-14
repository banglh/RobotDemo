#include "Stack.h"

void stackInit(Stack * st) {
    st->top = -1;
}

void push(Stack * st, Position item) {
    st->top++;
    st->s[st->top] = item;
}

Position pop(Stack * st) {
    Position item;
    item = st->s[st->top];
    st->top--;
    return item;
}

Position popToIndex(Stack * st, int index) {
    // popToIndex
    Position item;
    if (index >= st->top) {
        item = st->s[st->top];
    } else if (index > -1) {
        item = st->s[index + 1];
        st->top = index;
    } else {
        item = st->s[0];
        st->top = -1;
    }
    return item;
}

Position head(Stack st) {
    if (isEmptyStack(st) == FALSE)
        return st.s[st.top];
    else {
        Position pos;
        setPos(&pos, -1, -1);
        return pos;
    }
}

int isEmptyStack(Stack st) {
    if (st.top == -1)
        return TRUE;
    else
        return FALSE;
}

void printStack(Stack st) {
    int i;
    printf("\n");
    for (i = st.top; i >= 0; i--) {
        printPos(st.s[i]);
        printf("\n");
    }
    printf("\n");
}

void resetStack(Stack *st) {
    st->top = -1;
}

int isInStack(Stack st, int row, int col) {
    // isInStack
    int i;
    for (i = st.top; i > -1; i--) {
        if (st.s[i].row == row && st.s[i].col == col)
            return i;
    }
    return -1;
}

int isInStack2(Stack st, Position pos) {
    int i;
    for (i = st.top; i > -1; i--) {
        if (isSamePos2(pos, st.s[i]))
            return i;
    }
    return -1;
}
