struct Node {
    int data; // data 
    struct Node* left; // pointer
    struct Node* right; // pointer
};
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n6 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n5->data = 50;
    n6->data = 60;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = NULL;
    n4->left = NULL;
    n4->right = NULL;
    n5->left = NULL;
    n5->right = NULL;
    n6->left = NULL;
    n6->right = NULL;
    printf("Root Node: %d\n", n1->data);
    printf("Left Child of Root: %d\n", n1->left->data);
    printf("Right Child of Root: %d\n", n1->right->data);
    printf("Left Child of Left Child: %d\n", n1->left->left->data);
    printf("Right Child of Left Child: %d\n", n1->left->right->data);
    printf("Left Child of Right Child: %d\n", n1->right->left->data);
    printf("Right Child of Right Child: %s\n", n1->right->right ? "Exists" : "NULL");
    printf("Left Child of Left Child's Left Child: %s\n", n1->left->left->left ? "Exists" : "NULL");
    printf("Right Child of Left Child's Left Child: %s\n", n1->left->left->right ? "Exists" : "NULL");
    printf("Left Child of Left Child's Right Child: %s\n", n1->left->right->left ? "Exists" : "NULL");
    printf("Right Child of Left Child's Right Child: %s\n", n1->left->right->right ? "Exists" : "NULL");
    printf("Left Child of Right Child's Left Child: %s\n", n1->right->left->left ? "Exists" : "NULL");
    printf("Right Child of Right Child's Left Child: %s\n", n1->right->left->right ? "Exists" : "NULL");
    printf("Left Child of Right Child's Right Child: %s\n", n1->right->right->left ? "Exists" : "NULL");
    printf("Right Child of Right Child's Right Child: %s\n", n1->right->right->right ? "Exists" : "NULL");
    // Free allocated memory
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    return 0;
}