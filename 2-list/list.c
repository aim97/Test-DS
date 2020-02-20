#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* newNode(int val){
    // allocate space
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // set node data
    new_node->value = val;
    new_node->next = NULL;
    // return the node pointer
    return new_node;
}

struct List {
    struct Node* head;
    int sz;
};

struct List* newList(){
    struct List* new_list = (struct List*) malloc(sizeof(struct List));
    new_list->head = NULL;
    new_list->sz = 0;
    return new_list;
}

void insert(struct List* l, struct Node* node, int index) {
    assert(index >= 0);
    assert(index <= l->sz);
    assert(node != NULL);

    if(index == 0) {
        node->next = l->head;
        l->head = node;
    } else {
        struct Node* head = l->head;
        while(index > 1){
            head = head->next;
            index--;
        }

        node->next = head->next;
        head->next = node;
    }
    l->sz++;
}

void push_back(struct List* l, struct Node* node) {
    assert(node != NULL);

    struct Node* head = l->head;
    if(l->head == NULL) {
        l->head = node;
    } else {
        while(head->next) head = head->next;
        head->next = node;
    }
    l->sz++;
}
/**
delete
job: deletes the node in the given index from the linked list with given head
params : head: struct Node** > pointer that points to the address of the head of the linked list
         index:int           > the index of node to be deleted
return : void
NOTE : this triggers an assertion error if the node to be deleted is not found or
       head is NULL (can't delete from an empty list)
*/
void delete(struct List* l, int index) {
    assert(index >= 0);
    assert(index < l->sz);
    assert(l->head != NULL);

    struct Node *tmp, *head;
    if(index == 0) {
        tmp = l->head;
        l->head = (l->head)->next;
        free(tmp);
    } else {
        head = l->head;
        while(index > 1){
            head = head->next;
            index--;
        }

        tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
    l->sz--;
}


int search(struct List* l, int val) {
    int i = 0;
    struct Node* head = l->head;
    while(head != NULL) {
        if(head->value == val) return i;
        i++;
        head = head->next;
    }
    return -1;
}

void display_list(struct List* l) {
    struct Node* head = l->head;
    while(head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

/**
getsize
Job  : this function returns the size of the linked list starting at the given head.
params: head: struct Node*   > pointer to the first node in the linked list
returns: int > the size of the linked list
*/
int getSize(struct List* l) {
    return l->sz;
}

void bar(){
    printf("___________________________\n");
}

int main(){
    struct List* l = newList();
    insert(l, newNode(4), 0);
    insert(l, newNode(10), 1);
    insert(l, newNode(20), 2);
    push_back(l, newNode(30));
    display_list(l);
    bar();
    push_back(l, newNode(51));
    insert(l, newNode(12), 0);
    insert(l, newNode(34), 3);
    display_list(l);
    bar();
    delete(l, 1);
    delete(l, 3);
    display_list(l);
    bar();
    printf("list size %d\n", getSize(l));
    return 0;
}
