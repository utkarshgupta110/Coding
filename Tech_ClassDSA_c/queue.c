#include<stdio.h>
#include<stdlib.h>
#define maxsize 5 // Define the maximum size of the queue
// This code implements a simple queue using an array in C.
// The queue supports insertion, deletion, and display operations.
int front = -1, rear = -1;
int queue[maxsize];
void insert(int item){
    if(rear == maxsize-1){
        printf("Queue is full, cannot add.\n");
    }
    if(front == -1 && rear == -1){
        front = 0; // Initialize front if queue is empty
        rear = 0; // Initialize rear if queue is empty
    } else {
        rear++; // Move rear to the next position
    }
    queue[rear] = item; // Add the item to the queue
    printf("Inserted %d into the queue.\n", item);
}

void delete(){
    if(front == -1 || front > rear){
        printf("Queue is empty, cannot delete.\n");
        return;
    }
    int item;
    item = queue[front];
    if(front == rear){
        front = -1; // Reset front and rear if queue becomes empty
        rear = -1;
    }
    else {
        front=front+1; // Move front to the next position
    }
    printf("Deleted %d from the queue.\n", item);
}
void display(){
    if( rear == -1 && front == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void main(){
    insert(10);
    insert(20);
    insert(30);
    display();
    delete();
    display();
    insert(40);
    insert(50);
    insert(60); // This will show queue is full
    display();  
    delete();
    display();
    delete();
    delete(); // This will empty the queue
    display(); // Show queue is empty
    delete(); // Attempt to delete from an empty queue
    delete();
    delete();
}