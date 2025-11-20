
/*struct  Node {
    int data;
    struct Node* next;
};

#include <stdio.h>
#include <stdlib.h>
int main() {
   
    /* data */
    /*struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
                        struct Node* head = n1;
                        struct Node* current = head;
                        printf("Linked List elements are: ");
                        while (current != NULL) {
                            printf("%d ", current->data);
                            current = current->next;
                        }
                        printf("\n");
                        // Free allocated memory
                        current = head;
                        while (current != NULL) {
                            struct Node* temp = current;
                            current = current->next;
                            free(temp);
                        }
   while(n1!= NULL)
    // Traversing the linked list{
         printf("%d ", n1->data);
         n1 = n1->next;

    return 0;
};*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; // data 
    struct Node* next; // pointer
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List elements are: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Number of nodes in the linked list: %d\n", count);
}
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
int main() {
    struct Node* n1 = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);
    struct Node* n5 = createNode(50);

    n1->next = n3;
    n3->next = n2;
    n2->next = n5;
    n5->next = n4;

    printList(n1);
    countNodes(n1);
    insertAtEnd(&n1, 60);
    printList(n1);
    insertAtEnd(&n1, 70);
    printList(n1);
    countNodes(n1);

    // Free allocated memory
    struct Node* current = n1;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}