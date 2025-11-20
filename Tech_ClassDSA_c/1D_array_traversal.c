#include<stdio.h>
#include<stdlib.h>

void traverse(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements are: ");
    traverse(arr, size);
    return 0;
}
// Output: Array elements are: 1 2 3 4 5 6 7 8 9 10