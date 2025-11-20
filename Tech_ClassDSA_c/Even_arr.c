#include<stdio.h>
int main() {
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Even elements are:\n");
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}