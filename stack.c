#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++s->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Popped %d from the stack\n", pop(&s));
    display(&s);

    printf("Top element is %d\n", peek(&s));

    return 0;
}
