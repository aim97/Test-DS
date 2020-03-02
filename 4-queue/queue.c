#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct Queue {
    struct Node* head;
    struct Node* tail;
    int sz;
};

struct Queue* newQueue() {
    struct Queue* q = (struct Queue *) malloc(sizeof(struct Queue));
    q->head = q->tail = NULL;
    q->sz = 0;
    return q;
}

void push(struct Queue* q, int val) {
    struct Node* new_node = newNode(val);
    if(q->head != NULL) {
        q->tail->next = new_node;
        q->tail = new_node;
    } else {
        q->head = q->tail = new_node;
    }
    q->sz++;
}

void pop(struct Queue* q) {
    struct Node* tmp = q->head;
    q->head = q->head->next;
    if(q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    q->sz--;
}

int front(struct Queue* q) {
    return q->head->val;
}

int getSize(struct Queue* q) {
    return q->sz;
}

int main() {
    struct Queue* q = newQueue();
    push(q, 4);
    push(q, 5);
    push(q, 7);
    push(q, 10);
    while(getSize(q) > 0){
        printf("%d\n", front(q));
        pop(q);
    }
    return 0;
}
