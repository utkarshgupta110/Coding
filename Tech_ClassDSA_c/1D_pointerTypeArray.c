#include<stdio.h>
int a[]={1,2,3,4,5,6,7,8,9};
int main(){
    int *p=a;
    int size = sizeof(a) / sizeof(a[0]);
    printf("1D Array elements are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
       // printf("%d\n ", &p);
         //printf("%d\n ", *p);
        printf("%d\n ", p+i);
    }
    return 0;
}
