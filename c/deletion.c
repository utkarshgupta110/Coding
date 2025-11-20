#include<stdio.h>
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void indexDeletion(int arr[], int size, int index){
    for(int i=index; i<size; i++){
        arr[i]=arr[i+1];
    }
}       

int main(){
    int arr[100]={2,71,8,5,13};
    int size=5;
    int index=2;
    display(arr,size);
    indexDeletion(arr,size,index);
    size-=1;
    display(arr,size);
return 0;
}