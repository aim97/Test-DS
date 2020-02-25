#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

struct Stack {
    struct Node* head;
    int sz;
};

struct Stack* newStack() {
    struct Stack* new_stack = (struct Stack*) malloc(sizeof(struct Stack));
    new_stack->head = NULL;
    new_stack->sz = 0;
    return new_stack;
}

void push(struct Stack* s, int val) {
    struct Node* new_node = newNode(val);
    new_node->next = s->head;
    s->head = new_node;
    s->sz++;
}

void pop(struct Stack* s) {
    struct Node* tmp = s->head;
    s->head = s->head->next;
    free(tmp);
    s->sz--;
}

int top(struct Stack* s) {
    return s->head->value;
}

int isEmpty(struct Stack* s) {
    return s->sz == 0;
}

int main(int argc, char const *argv[]) {
    struct Stack* s = newStack();
    push(s, 4);
    push(s, 5);
    push(s, 10);
    while(!isEmpty(s)) {
        printf("%d\n", top(s));
        pop(s);
    }
    return 0;
}
