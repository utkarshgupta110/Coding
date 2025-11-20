#include<bits/stdc++.h>
using namespace std;

// binary search(iterative approach), tc-> O(logn) & sc-> O(1)
int problem1_1(vector<int>& arr, int target){
    int n= arr.size();
    int low= 0;
    int high= n-1;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) low= mid+1;
        else high= mid-1;
    }
    return -1;
}

// binary search(recursive approach), tc-> O(logn) & sc-> O(1)
int problem1_2(vector<int>& arr, int target, int low, int high){
    if(low>=high) return -1; // base case
    int mid= (low + high)/2;
    if(arr[mid]==target) return mid;
    else if(target>arr[mid]) return problem1_2(arr, target, mid+1, high);
    else return problem1_2(arr, target, low, mid-1);
}

// finding lower bound & Search Insert Position, tc-> O(logn) & sc-> O(1)
int problem2(vector<int>& arr, int x){
    int n= arr.size();
    int low= 0;
    int high= n-1;
    int ans= n;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]>=x){
            ans= mid;
            high= mid-1;
        }
        else low= mid+1;
    }
    return ans;
}

// finding upper bound, tc-> O(logn) & sc-> O(1)
int problem3(vector<int>& arr, int x){
    int n= arr.size();
    int low= 0;
    int high= n-1;
    int ans= n;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]>x){
            ans= mid;
            high= mid-1;
        }
        else low= mid+1;
    }
    return ans;
}

// floor/ceil in sorted array, tc-> O(logn) & sc-> O(1)
vector<int> problem4(vector<int>& arr, int x){
    int n= arr.size();
    int low= 0;
    int high= n-1;
    int floor= -1, ceil= -1;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]==x){
            floor= arr[mid];
            ceil= arr[mid];
            break;
        }
        else if(arr[mid]<x){
            floor= arr[mid];
            low= mid+1;
        }
        else{
            ceil= arr[mid];
            high= mid-1;
        }
    }
    return {floor, ceil};
}

// First and last occurrence
// brtf-> below, tc-> O(n) & sc-> O(1)
vector<int> problem5_1(vector<int> &nums, int target) {
    int n= nums.size();
    int first= -1, last= -1;
    for(int i=0; i<n; i++){
        if(nums[i]==target){
            if(first==-1) first= i;
            last= i;
        }
    }
return {first, last};
}

// First and last occurrence using lb & ub
// opti1-> below, tc-> 2×O(logn) & sc-> O(1)
vector<int> problem5_2(vector<int> &nums, int target) {
    int n= nums.size();
    int first= problem2(nums, target); // lb
    if(nums[first]!= target || first== n) return {-1, -1};
    int last= problem3(nums, target)-1; // ub
return {first, last};
}

// First and last occurrence using simple binary search
// opti2-> below, tc-> 2×O(logn) & sc-> O(1)
int firstOccurence(vector<int> &arr, int target){
    int n= arr.size();
    int first= -1;
    int low= 0;
    int high= n-1;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]==target){
            first= mid;
            high= mid-1;
        }
        else if(target>arr[mid]) low= mid+1;
        else high= mid-1;
    }
return first;
}
int lastOccurence(vector<int> &arr, int target){
    int n= arr.size();
    int last= -1;
    int low= 0;
    int high= n-1;
    while(low<=high){
        int mid= (low + high)/2;
        if(arr[mid]==target){
            last= mid;
            low= mid+1;
        }
        else if(target>arr[mid]) low= mid+1;
        else high= mid-1;
    }
return last;
}
vector<int> problem5_3(vector<int>& arr, int target){
    int first= firstOccurence(arr, target);
    if(first==-1) return {-1, -1};
    int last= lastOccurence(arr, target);
return {first, last};
}

// Count occurrences of a number in an sorted array with duplicates, tc-> 2×O(logn) & sc-> O(1)
int problem6(vector<int> &arr, int target){
    vector<int> ans= problem5_3(arr, target);
    if(ans[0]==-1) return 0;
return ans[1]-ans[0]+1;
}

// Search Element in Rotated Sorted Array - I(with uniques), tc-> O(logn) & sc-> O(1)
int problem7(vector<int> &arr, int target){
    int n= arr.size();
    int low= 0, high= n-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]==target) return mid;
        // Identify the sorted half
        else{
            if(arr[low]<=arr[mid]){
                if(arr[low]<= target && target<= arr[mid]) high= mid-1;
                else low= mid+1;
            }
            else{
                if(arr[mid]<= target && target<= arr[high]) low= mid+1;
                else high= mid-1;
            }
        }
    }
return -1;
}

// Search Element in Rotated Sorted Array - II(with duplicates), tc(at avg.)-> O(logn) & tc(at worst)-> O(n/2) & sc-> O(1)
int problem8(vector<int> &arr, int target){
    int n= arr.size();
    int low= 0, high= n-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++, high--;
            continue;
        }
        // Identify the sorted half
        if(arr[low]<=arr[mid]){
            if(arr[low]<= target && target<= arr[mid]) high= mid-1;
            else low= mid+1;
        }
        else{
            if(arr[mid]<= target && target<= arr[high]) low= mid+1;
            else high= mid-1;
        }
    }
return -1;
}

// Minimum in Rotated Sorted Array, tc-> O(logn) & sc-> O(1)
int problem9(vector<int> &arr){
    int n= arr.size();
    int low= 0, high= n-1;
    int mini= INT_MAX;
    while(low<=high){
        int mid= (low+high)/2;
        // Search space is already sorted
        // then always arr[low] is will be smaller
        // in that search space
        if(arr[low]<arr[high]){
            mini= min(mini, arr[low]);
            break;
        }
        // handling duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){             
            mini = min(mini, arr[low]);             
            low++;             
            high--;             
            continue;         
        }   
        if(arr[low]<=arr[mid]){
            mini= min(mini, arr[low]);
            low= mid+1;
        }
        else{
            mini= min(mini, arr[mid]);
            high= mid-1;
        }
    }
return mini;
}

// Find out how many times array has been rotated, tc-> O(logn) & sc-> O(1)
int problem10(vector<int> &arr){
    int n= arr.size();
    int low= 0, high= n-1;
    int mini= INT_MAX;
    int index= -1;
    while(low<=high){
        int mid= (low+high)/2;
        // Search space is already sorted
        // then always arr[low] is will be smaller
        // in that search space
        if(arr[low]<arr[high]){
            if(arr[low]<mini){
                mini= arr[low];
                index= low;
            }
            break;
        }
        // handling duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){             
            if(arr[low]<mini){
                mini= arr[low];
                index= low;
            }           
            low++;             
            high--;             
            continue;         
        }   
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini= arr[low];
                index= low;
            }
            low= mid+1;
        }
        else{
            if(arr[mid]<mini){
                mini= arr[mid];
                index= mid;
            }
            high= mid-1;
        }
    }
return index;
}

// Single element in an array, tc-> O(n) & sc-> O(1) 
int problem11_1(vector<int> &arr){
    int n= arr.size();
    for(int i=0; i<n; i++){
        if(i==0){
            if(arr[i]!=arr[i+1]) return arr[i];
        }
        else if(i==n-1){
            if(arr[i]!=arr[i-1]) return arr[i];
        }
        else{
            if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]) return arr[i];
        }
    }
}

// Single element in an array, tc-> O(logn) & sc-> O(1) 
int problem11_2(vector<int> &arr){
    int n= arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-2]!=arr[n-1]) return arr[n-1];
    int low= 1, high= n-2;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        // We are on left
        else if((mid%2==1 && arr[mid]==arr[mid-1]) 
            || (mid%2==0 && arr[mid]==arr[mid+1])){
            low= mid+1;
        }
        // We are on right
        else high= mid-1;     
    }
return -1;
}

// Find Peak Element, tc-> O(n) & sc-> O(1)  
int problem12_1(vector<int> &arr){
    int n= arr.size();
    for(int i=0; i<n; i++){
        if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])) return i;
    }
return -1;
}

// Find Peak Element, tc-> O(logn) & sc-> O(1) 
int problem12_2(vector<int> &arr){
    int n= arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low= 1, high= n-2;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        // We are on left
        else if(arr[mid]>arr[mid-1]){
            low= mid+1;
        }
        // We are on right
        else if(arr[mid]>arr[mid+1]){
            high= mid-1;
        }     
        else  high= mid-1;
    }
return -1;
}

// Koko Eating Bananas, tc-> O(max(piles) × n) & sc-> O(1)
int maxElement(vector<int> &arr){
    int n= arr.size();
    int maxi= arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>maxi) maxi= arr[i];
    }
return maxi;
}
int totalHours(vector<int> &arr, int hourly){
    int n= arr.size();
    int total_hours= 0;
    for(int i=0; i<n; i++){
        total_hours+= ceil(arr[i]/(double)hourly);
    }
return total_hours;
}
int problem13_1(vector<int> &piles, int hours){
    int n= maxElement(piles);
    for(int i=1; i<=n; i++){
        int reqTime= totalHours(piles ,i);
        if(reqTime<=hours) return i;
    }
return -1;
}

// Koko Eating Bananas, tc-> O(log max(piles) × n) & sc-> O(1)
int problem13_2(vector<int>& piles, int hours){
    int n= maxElement(piles);
    int low= 1;
    int high= n;
    while(low<=high){
        int mid= (low + high)/2;
        int reqTime= totalHours(piles ,mid);
        if(reqTime<=hours) high= mid-1;
        else low= mid+1;
    }
return low;
}

// Minimum days to make M bouquets, tc-> O((max-min+1) × n) & sc-> O(1)
int minElement(vector<int> &arr){
    int n= arr.size();
    int mini= arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<mini) mini= arr[i];
    }
return mini;
}
bool minPossibleDay(vector<int> &arr, int day, int m, int k){
    int n= arr.size();
    int cnt= 0;
    int nBouquets= 0;
    for(int i=0; i<n; i++){
        if(arr[i]<=day) cnt++;
        else{
            nBouquets+= (cnt/k);
            cnt= 0;
        }
    }
    nBouquets+= (cnt/k);
    if(nBouquets>=m) return true;
return false;
}
int problem14_1(vector<int> &bloomDay, int m, int k){
    int n= bloomDay.size();
    if(n < m*k) return -1;
    int min= minElement(bloomDay);
    int max= maxElement(bloomDay);
    for(int i= min; i<=max; i++){
        if(minPossibleDay(bloomDay, i, m, k) == true) return i;
    }
return -1;
}

// Minimum days to make M bouquets, tc-> O(log(max-min+1) × n) & sc-> O(1)
int problem14_2(vector<int>& bloomDay, int m, int k){
    int n= bloomDay.size();
    if(n < m*k) return -1;
    int min= minElement(bloomDay);
    int max= maxElement(bloomDay);
    int low= min;
    int high= max;
    while(low<=high){
        int mid= (low + high)/2;
        int possibleDay= minPossibleDay(bloomDay, mid, m, k);
        if(possibleDay == true) high= mid-1;
        else low= mid+1;
    }
return low;
}

// Find the Smallest Divisor Given a Threshold, tc-> O(max(arr) × n) & sc-> O(1)
bool possibleDivisor(vector<int> &arr, int divisor, int threshold){
    int n= arr.size();
    int sum= 0;
    for(int i=0; i<n; i++){
        sum+= ceil(arr[i]/(double)divisor);
    }
    if(sum <= threshold) return true;
return false;
}
int problem15_1(vector<int> &arr, int threshold){
    int n= arr.size();
    if(n>threshold) return -1;
    int max= maxElement(arr);
    for(int i=1; i<=max; i++){
        if(possibleDivisor(arr, i, threshold) == true) return i;
    }
return -1;
}

// Find the Smallest Divisor Given a Threshold, tc-> O(log(max(arr)) × n) & sc-> O(1)
int problem15_2(vector<int> &arr, int threshold){
    int n= arr.size();
    if(n>threshold) return -1;
    int max= maxElement(arr);
    int low= 1;
    int high= max;
    while(low<=high){
        int mid= (low+high)/2;
        if(possibleDivisor(arr, mid, threshold) == true) high= mid-1;
        else low= mid+1;
    }
return low;
}

// Capacity to Ship Packages within D Days, tc-> O((sum-max+1) × n) & sc-> O(1)
int arraySum(vector<int> &arr){
    int n= arr.size();
    int sum= 0;
    for(int i=0; i<n; i++) sum+= arr[i];
return sum;
}
int daysReq(vector<int> &arr, int capacity){
    int n= arr.size();
    int days= 1, load= 0;
    for(int i=0; i<n; i++){
        if(load + arr[i] > capacity){
            days+= 1;
            load= arr[i];
        }
        else{
            load+= arr[i];
        }
    }
return days;
}
int problem16_1(vector<int> &weights, int days){
    int n= weights.size();
    int max= maxElement(weights);
    int sum= arraySum(weights);
    for(int capacity=max; capacity<=sum; capacity++){
        int reqDays= daysReq(weights, capacity);
        if(reqDays <= days) return capacity;
    }
return -1;
}

// Capacity to Ship Packages within D Days, tc-> O(log(sum-max+1) × n) & sc-> O(1)
int problem16_2(vector<int> &weights, int days){
    int n= weights.size();
    int max= maxElement(weights);
    int sum= arraySum(weights);
    int low= max;
    int high= sum;
    while(low<=high){
        int mid= (low+high)/2;
        int reqDays= daysReq(weights, mid);
        if(reqDays <= days) high= mid-1;
        else low= mid+1;
    }
return low;
}

// Kth Missing Positive Number | Maths, tc-> O(n) & sc-> O(1)
int problem17_1(vector<int> &arr, int k){
    int n= arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]<=k) k++;
        else break;
    }
return k;
}

// Kth Missing Positive Number | Binary Search, tc-> O(logn) & sc-> O(1)
int problem17_2(vector<int> &arr, int k){
    int n= arr.size();
    int low= 0, high= n-1;
    while(low<=high){
        int mid= (low+high)/2;
        int missing= arr[mid]-(mid+1);
        if(missing<k) low= mid+1;
        else high= mid-1;
    }
return low+k;
}





















int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // int target;
    // cin>>target;
    // cout<<problem1_1(arr, target);
    // cout<<problem1_2(arr, target, 0, n-1);
    // int x;
    // cin>>x;
    // cout<<problem2(arr, x);
    // cout<<problem3(arr, x);
    // vector<int> res= problem4(arr, x);
    // vector<int> res= problem5_1(arr, target);
    // vector<int> res= problem5_2(arr, target);
    // vector<int> res= problem5_3(arr, target);
    // cout<<res[0]<<" "<<res[1];
    // cout<<problem6(arr, target);
    // cout<<problem7(arr, target);
    // cout<<problem8(arr, target);
    // cout<<problem9(arr);
    // cout<<problem10(arr);
    // cout<<problem11_1(arr);
    // cout<<problem11_2(arr);
    // cout<<problem12_1(arr);
    // cout<<problem12_2(arr);
    // int hr; 
    // cin>>hr; 
    // cout<<problem13_1(arr, hr);
    // cout<<problem13_2(arr, hr);
    // int m, k; // where, m -> no. of bouquets, k -> adjacent flowers req. 
    // cin>>m; cin>>k;
    // cout<<problem14_1(arr, m ,k);
    // cout<<problem14_2(arr, m ,k);
    // int threshold;
    // cin>>threshold;
    // cout<<problem15_1(arr, threshold);
    // cout<<problem15_2(arr, threshold);
    // int days;
    // cin>>days;
    // cout<<problem16_1(arr, days);
    // cout<<problem16_2(arr, days);
    int k;
    cin>>k;
    // cout<<problem17_1(arr, k);
    cout<<problem17_2(arr, k);

return 0;
}