// Binary Search On Answers
#include<bits/stdc++.h>
using namespace std;

// Finding floorSqrt of a number using brute approach, tc-> O(n) & sc-> O(1)
int problem1_1(int n){
    int ans=1;
    for(int i=1; i<=n; i++){
        long long sqr= i*i;
        if(sqr<=n) ans= i;
        else break;
    }
return ans;
}

// Finding floorSqrt of a number using Binary Search, tc-> O(logn) & sc-> O(1)
int problem1_2(int n){
    int low= 1, high= n;
    while(low<=high){
        long long mid= (low+high)/2;
        long long sqr= mid*mid;
        if(sqr<=n) low= mid+1;
        else high= mid-1;
    }
return high;
}

// Find the Nth root of an Integer using brute approach, tc-> O(m × n) & sc-> O(1)
int power(int num, int times){
    long long ans= 1;
    for(int i=1; i<=times; i++){
        ans*= num;
    }
return ans;
}
int problem2_1(int n, int m){
    for(int i=1; i<=m; i++){
        if(power(i, n)== m) return i;
        else if(power(i, n)> m) break;
    }
return -1;
}

// Find the Nth root of an Integer, tc-> O(logm × n) & sc-> O(1)
int power1(int num, int times, int answer){
    long long ans= 1;
    for(int i=1; i<=times; i++){
        ans*= num;
        if(ans>answer) return 2;
    }
if(ans==answer) return 1;
return 0;
}
int problem2_2(int n, int m){
    int low= 1, high= m;
    while(low<=high){
        long long mid= (low+high)/2;
        int midN= power1(mid, n, m);
        if(midN==1) return mid;
        else if(midN==2) high= mid-1;
        else low= mid+1; 
    }
return -1;
}


































int main(){
    int n; cin>>n;
    // cout<<problem1_1(n);
    // cout<<problem1_2(n);
    int m; cin>>m;
    // cout<<problem2_1(n, m);
    cout<<problem2_2(n, m);
    return 0;
}