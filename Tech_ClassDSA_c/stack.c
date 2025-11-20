# include<stdio.h>
# include<stdlib.h>
# define maxsize 100
int stack[maxsize]; // array
int top = -1; // means stack is empty

void push(int value){
    if(top== maxsize-1){
        printf("stack overflow\n");
    }
    else{
        top++;
        stack[top] = value;//stack[top++]= value;
        // Uncomment the line below if you want to use the alternative syntax
        printf("pushed %d\n", value);
    }
}

void pop(){
    // Function to pop an element from the stack
    if(top== -1){
        printf("stack underflow\n");
    }
    else{
        printf("popped %d\n", stack[top]);
        top--;
    }
}
void display(){
    // Function to display the stack
    if(top== -1){
        printf("stack is empty\n");
    }
    else{
        printf("stack elements are:\n");
        for(int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}
int main(){
    int choice, value;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
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