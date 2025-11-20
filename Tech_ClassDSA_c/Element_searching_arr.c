#include<stdio.h>
int main() {
    int arr[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element, found = 0;

    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            printf("Element %d found at index %d\n", element, i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Element %d not found in the array\n", element);
    }

    return 0;
}