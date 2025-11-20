#include<stdio.h>
#include<stdlib.h>
#define maxsize 5 
struct Node {
    int data; // data 
    struct Node* next; // pointer
};
struct Node* front = NULL; // global variable to keep track of the front of the queue
struct Node* rear = NULL; // global variable to keep track of the rear of the queue
int front = -1, rear = -1;
void insert(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full, cannot add.\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode; // Initialize front and rear if queue is empty
    } else {
        rear->next = newNode; // Link the new node at the end of the queue
        rear = newNode; // Move rear to the new node
    }
    printf("Inserted %d into the queue.\n", item);
}
void delete(){
    if(front == NULL){
        printf("Queue is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = front;
    int item = front->data;
    front = front->next; // Move front to the next node
    if(front == NULL) {
        rear = NULL; // If queue becomes empty, reset rear
    }
    free(temp); // Free the memory of the deleted node
    printf("Deleted %d from the queue.\n", item);
}
void display(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = front;
    printf("Queue elements are: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    }
    printf("\n");
}
int main() {
    int choice, value;
    while(1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}