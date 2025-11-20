#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory alloccation failed\n");
        exit(1);    
    }
    
    newNode->data= value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
    
void forwardPrintList(struct Node* head){
    struct Node* current= head;
    printf("Doubly Circular Linked List elements are: ");
    
    do{
        printf("%d\t", current->data);
        current=current->next;
    }
    while(current!=NULL && current!=head); // Loop until we reach back to the head node
    printf("\n");
}

void backwardPrintList(struct Node* tail){
    struct Node* current= tail; 
    printf("\nDoubly Circular Linked List elements in reverse order: ");
    do{
        printf("%d\t", current->data);
        current=current->prev;
    }
    while(current!=NULL && current!=tail); // Loop until we reach back to the tail node
    // Note: In a circular doubly linked list, we can also use tail->prev to start the backward traversal
    printf("\n");
}

int main(){
    struct Node* head=NULL;
    struct Node* second=NULL;
    struct Node* third=NULL;

    head=createNode(10);
    second=createNode(20);// function createNode() called 3 times to create 3 nodes
    third=createNode(30);

    head->prev=third;    // Link head node to NULL (NULL pointer)
    head->next=second;  // Link head to second node (next pointer)
    second->prev=head;  // Link second node to head (prev pointer)
    second->next=third; // Link second node to third node (next pointer)
    third->prev=second; // Link third node to second node (prev pointer)
    third->next=head;   // Link third node to head (next pointer)  to create Doubly Circular Linked List

    forwardPrintList(head); // Print the list in forward direction
    backwardPrintList(third); // Print the list in backward direction

    // Free allocated memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }  
    printf("\n");
    printf("Memory freed successfully.\n");
    getch();
    // Return 0 to indicate successful execution
    printf("Program executed successfully.\n"); 
    return 0;    
}