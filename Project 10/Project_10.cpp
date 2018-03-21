//
//
//  Program10
//
// Matthew Krieger
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********** ORIGINAL PROGRAM FUNCTIONS **********/

struct NODE
{
    struct NODE *link;
    int value;
};

typedef struct NODE Node;

Node *insertFirst(Node **ptrToHeadPtr, int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;
    node->link = *ptrToHeadPtr;
    *ptrToHeadPtr = node;
    return node;
}

void traverse(Node *p){
    while(p != NULL){
        printf("%d ", p->value);
        p = p->link;
    }
}

void freeList(Node *p){
    Node *temp;
    while (p != NULL){
        temp = p;
        p = p->link;
        free(temp);
    }
}


/********** COUNT TARGET FUNCTION **********/

int countTarget(Node *start, int target){
    int count = 0;
    while(start != NULL){
        if(start->value == target){
            count++;
        }
        start = start->link;
    }
    return count;
}


/********** IN-ORDER FUNCTION **********/

int inOrder(Node *start) {
    if(start != NULL){
        while (start->link != NULL) {
            if (start->value <= start->link->value) {
                start = start->link;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}


/********** DELETE FIRST FUNCTION **********/

void deleteFirst(Node **ptrToHeadPtr){
    Node *node = *ptrToHeadPtr;
    if(node != NULL){
        *ptrToHeadPtr = node->link;
        free(node);
    }
}

/********** INSERT LAST FUNCTION **********/

Node *insertLast(Node **ptrToHeadPtr, int val){
    Node *node = *ptrToHeadPtr;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = val;
    newNode->link = NULL;
    
    while(node && node->link != NULL){
        node = node->link;
    }
    if(!node){
        *ptrToHeadPtr = newNode;
    }
    else{
        node->link = newNode;
    }
    return newNode;
}


/********** MAIN DEBUG METHODS BELOW **********/

int main(){
    Node *HeadPtr = NULL;
    int i;
    srand((unsigned)time(NULL));
    
    
    
    /*for(i = 0; i < 50; i++){
     insertFirst(&HeadPtr, i);
     }*/
    
    
    /*for(i = 0; i < 50; i++){
     insertLast(&HeadPtr, i);
     } */
    
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 1);
    insertLast(&HeadPtr, 2);
    insertLast(&HeadPtr, 3);
    insertLast(&HeadPtr, 3);
    insertLast(&HeadPtr, 0);
    
    
    /* RANDOM NUMBER GENERATOR FOR DEBUG
     for(i = 0; i < 50; i++) {
     insertFirst(&HeadPtr, (rand() % 10 + 1));
     }
     */
    
    
    traverse(HeadPtr);
    deleteFirst(&HeadPtr);
    printf("\n");
    traverse(HeadPtr);
    printf("\nFrequency of %d: %d", 1, countTarget(HeadPtr, 1));
    printf("\nIn Order: %d", inOrder(HeadPtr));
    freeList(HeadPtr);
    
    getchar();
    return 1;
    
}