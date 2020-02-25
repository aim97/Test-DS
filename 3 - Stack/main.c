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

void push(struct Node** head, struct Node* new_node){
    new_node->next = *head;
    *head = new_node;
}

void pop(struct Node** head){
    struct Node* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

int top(struct Node* head) {
    return head->value;
}


int main() {
    struct Node* head = NULL;
    struct Node* a = newNode(4)
    push(&head, a);
    push(&head, newNode(5));
    push(&head, newNode(6));
    while(head != NULL) {
        printf("%d\n", top(head));
        pop(&head);
    }
    return 0;
}
