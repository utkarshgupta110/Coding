#include<stdio.h>
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
    
    printf("2D Array elements are:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// Output: 2D Array elements are:
// 1 2 3
// 4 5 6
// 7 8 9
// This code initializes a 2D array and traverses it to print its elements in a matrix format.
// The size of the array is calculated using the `sizeof` operator, and nested loops are used to access each element.
// The output displays the elements of the 2D array in rows and columns, demonstrating how to work with 2D arrays in C.