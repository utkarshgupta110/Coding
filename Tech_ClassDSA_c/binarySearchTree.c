#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data; // data 
    struct Node* left; // pointer
    struct Node* right; // pointer
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void postOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(6);
    root->right = createNode(15);
    root->left->left = createNode(8);
    root->left->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here for brevity)
    
    return 0;
}