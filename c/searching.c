#include<stdio.h>
int linearSearch(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
        return i;   
        }
    }
    return -1;
}   

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low=0;
    high=size-1;
    while(low<=high){
        mid=(low+high)/2;
       if (arr[mid]==element){
        return mid;
      }
       if (arr[mid]<element){
        low=mid+1;
      }
       else{
        high=mid-1;
      }
    }
    return -1;    
}

int main(){
    int arr[100],i,size,element;
    printf("enter size of an array:");
    scanf("%d",&size);
    printf("\n");
printf("Input elements in the array\n");
    for(i=0;i<size;i++){
        printf("enter elements  a[%d] : ",i);
	    scanf("%d",&arr[i]);
    }
     printf("\n");
printf("array elements are: ");   
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("enter element to be searched:");
    scanf("%d",&element);
    int LsearchIndex=linearSearch(arr,size,element);
    int BsearchIndex=binarySearch(arr,size,element);
     printf("\n");
    printf("For linear search the element %d was found at index %d and for binary search the element %d was found at index %d",element,LsearchIndex,element,BsearchIndex);
return 0;
}