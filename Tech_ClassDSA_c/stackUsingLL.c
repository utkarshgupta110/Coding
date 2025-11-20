#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; // data 
    struct Node* next; // pointer
};

struct Node* head = NULL; // global variable to keep track of the top of the stack

void push(int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("cannot push the element\n");
    }
    else{
        if(head==NULL){
            ptr->data = data;
            ptr->next = NULL;
            head = ptr;
        }
        else{
            ptr->data = data;
            ptr->next = head;
            head = ptr;
        }
    }
}
void pop(){
    if(head==NULL){
        printf("stack underflow\n");
    }
    else{
        struct Node* temp = head;
        head = head->next;
        printf("popped %d\n", temp->data);
        free(temp);
    }
}
void display(){
    if(head==NULL){
        printf("stack is empty\n");
    }
    else{
        struct Node* current = head;
        printf("stack elements are:\n");
        while(current != NULL){
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}
int main() {
    int choice, value;
    while(1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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