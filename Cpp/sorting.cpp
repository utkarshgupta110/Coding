#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){ // tc= O(n∧2) for all the cases
    for(int i=0; i<=n-2; i++){
        int min=i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[i],arr[min]);
    }
}
void bubble_sort(int arr[], int n){ // tc= O(n∧2) at worst & avg case, [and O(n) at best case(if the given arrary is already in sorted fashion)]
    for(int i=0; i<=n-2; i++){
        int didSwap=0;
        for(int j=0; j<=n-i-2; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
    if(didSwap==0) break;
    }
}
void insertion_sort(int arr[], int n){ // TC -> worst & avg. - O(N^2)  best - O(N)[(if the given arrary is already in sorted fashion)]
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
void merge(int arr[], int n, int low, int mid, int high){ // TC -> best, worst & avg. - O(N logN) and SC -> O(N)
    int left = low;
    int right = mid + 1;
    int temp[n];
    int k = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= high) {
        temp[k++] = arr[right++];
    }
    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}
void merge_sort(int arr[], int n, int low, int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    merge_sort(arr, n, low, mid);
    merge_sort(arr, n, mid+1, high);
    merge(arr, n, low, mid, high);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>> arr[i];
    //selection_sort(arr, n);
    //bubble_sort(arr, n);
    //insertion_sort(arr, n);
    int low= 0;
    int high= n-1;
    merge_sort(arr, n, low, high);
    for(int i=0; i<n; i++) cout<< arr[i]<<" ";
    return 0;
}