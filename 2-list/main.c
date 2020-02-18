#include <stdio.h>
#include <stdlib.h>

// function assert is used to check if the assumptions you make are true.
// lets say i make a function to compute factorial
// i can compute the factorial of any number from 1 to n
// but not negative numbers, so how to prevent that
// we use function assert to make sure the given number is >= 0
// assert(i >= 0);
// so if the user called factorial(-1) it will trigger an error
// and close the program instead of making any unpredictable behviours
#include <assert.h>

// the Node structure contains at least two components
// 1 - the value it will hold
//     it can be int, float or even another structure, there can be more than one value
//     like int x, y;
// 2 - next pointer
//    a pointer that holds the address of the next node.
//    this is the most important part, the linked list depends on this pointer.
struct Node {
    int value;
    struct Node* next;
};

/**
newNode
Job    : this function creas a new node, sets its value to the given
         value, and set its next to NULL.
params : val:int > this is the value of the node you want to add
return : it returns a pointer to the new node created.
*/
struct Node* newNode(int val){
    // allocate space
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // set node data
    new_node->value = val;
    new_node->next = NULL;
    // return the node pointer
    return new_node;
}

/**
insert
Job   : this function inserts the given node <node> in the given linked list <head>
        in the given index
params : head: struct Node** > pointer that points to the address of the head of the linked list
         node: struct Node*  > pointer to the node to be inserted
        index: int           > the index to insert the new node in.
return : void
NOTE : this triggers an assertion error if the index is out of range, and the node
       to be inserted is NULL.
*/
void insert(struct Node** head, struct Node* node, int index) {
    assert(index >= 0);
    assert(node != NULL);

    if(index == 0) {
        node->next = *head;
        *head = node;
    } else if(index == 1) {
        node->next = (*head)->next;
        (*head)->next = node;
    } else {
        insert(&((*head)->next), node, index - 1);
    }
}

/**
push_back
Job   : this function inserts the given node <node> in the given linked list <head>
        in the end of the list
params : head: struct Node** > pointer that points to the address of the head of the linked list
         node: struct Node*  > pointer to the node to be inserted
return : void
NOTE : this triggers an assertion error if the node
       to be inserted is NULL.
*/
void push_back(struct Node** head, struct Node* node) {
    assert(node != NULL);

    if(*head == NULL) {
        *head = node;
    }
    struct Node* tmp = *head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = node;
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
void delete(struct Node** head, int index) {
    assert(index >= 0);
    assert(*head != NULL);

    struct Node* tmp;
    if(index == 0) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    } else if(index == 1){
        tmp = (*head)->next;
        (*head)->next = tmp->next;
        free(tmp);
    } else {
        delete(&(*head)->next, index - 1);
    }
}

/**
search
Job    :this function searches for the given value in the linked list with the given head
params:  head: struct Node*   > pointer to the first node in the linked list
         val : int            > the value to search for.
return : int > the index where the value is found or -1 if not found
*/
int search(struct Node* head, int val) {
    int i = 0;
    while(head != NULL) {
        if(head->value == val) return i;
        i++;
        head = head->next;
    }
    return -1;
}

/**
display_list
Job  : this function displays the linked list starting at the given head
params: head: struct Node*   > pointer to the first node in the linked list
returns : void
*/
void display_list(struct Node* head) {
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
int getSize(struct Node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

void bar(){
    printf("___________________________\n");
}

int main(){
    struct Node* head = newNode(4);
    insert(&head, newNode(10), 1);
    insert(&head, newNode(20), 2);
    push_back(&head, newNode(30));
    display_list(head);
    bar();
    push_back(&head, newNode(51));
    insert(&head, newNode(12), 0);
    insert(&head, newNode(34), 3);
    display_list(head);
    bar();
    delete(&head, 1);
    delete(&head, 3);
    display_list(head);
    bar();
    printf("list size %d\n", getSize(head));
    return 0;
}
