#include<stdio.h>
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int indexInsertion(int arr[], int size, int index, int element, int capacity){
    if(size>capacity){
        return -1;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}       

int main(){
    int arr[100]={2,71,8,5,13};
    int size=5;
    int index=2;
    int capacity=100;
    int element=7;
    display(arr,size);
    indexInsertion(arr,size,index,element,capacity);
    size+=1;
    display(arr,size);
return 0;
}