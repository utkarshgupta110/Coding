#include<bits/stdc++.h>
using namespace std;

string decimal2Binary(int n){ // tc-> O(logn) & sc-> O(logn)
    if(n == 0) return "0";
    if(n < 0) return "-" + decimal2Binary(-n);
    string res;
    while(n != 1){
        res += (n % 2 ? '1' : '0');
        n = n/2;
    }
    res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

int binary2Decimal(string st){ // tc-> O(len(st)) & sc-> O(1)
    int num = 0;
    int powerof2 = 1;
    int len = st.length();
    for(int i = len-1; i >= 0; i--){
        if(st[i] == '1') num += powerof2;
        powerof2 *= 2;
    }
    return num;
}

void swapTw0Nums(int a, int b){ // tc & sc-> O(1)
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<a<<" "<<b;
}

// Approach-> using left shift, Check if the ith bit is set or not, tc & sc-> O(1)
bool problem1_1(int n, int i){
    if((n & (1 << i)) != 0) return true;
    else return false; 
}

// Approach-> using right shift, Check if the ith bit is set or not, tc & sc-> O(1)
bool problem1_2(int n, int i){
    if(((n >> i) & 1) != 0) return true;
    else return false; 
}

// Set the ith bit i.e. converting 0 -> 1 on index i only, tc & sc-> O(1)
int problem2(int n, int i){
    return (1 << i) | n;
}

// Clear the ith bit i.e. converting 1 -> 0 on index i only, tc & sc-> O(1)
int problem3(int n, int i){
    return ~(1 << i) & n;
}

// Toggle the ith bit i.e. converting 1 -> 0 (vice-versa) on index i, tc & sc-> O(1)
int problem4(int n, int i){
    return (1 << i) ^ n;
}

// Remove the last set bit(Rightmost), tc & sc-> O(1)
int problem5(int n){
    return n & (n-1);
}

// Check if the number is a power of 2 or not, tc & sc-> O(1)
bool problem6(int n){
    if((n & (n-1)) == 0) return true;
    else return false;
}

// Approach 1, Count the number of set bits, tc-> O(logn) & sc-> O(1)
int problem7_1(int n){
    int cnt = 0;
    while(n > 1){
        cnt += n & 1;                // if (n % 2 == 1) cnt++;
        n = n >> 1;                  // n /= 2;
    }
    if (n == 1) cnt += 1;
    return cnt;
}

// Approach 2, Count the number of set bits, tc-> O(no. of set bits) & sc-> O(1)
int problem7_2(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

// Minimum Bit Flips to Convert Number, tc-> O(logn) & sc-> O(1)
int problem8(int start, int goal){
    int ans = start ^ goal;
    return problem7_1(ans);
}

// Power Set, tc-> O(n × 2^n) & sc-> O(2^n)
vector<vector<int>> problem9(vector<int> &arr){
    vector<vector<int>> res;
    int n = arr.size();
    int subsets = 1 << n;
    for(int num = 0; num < subsets; num++){
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(num & (1 << i)) temp.push_back(arr[i]);
        }
        res.push_back(temp);
    }
    return res;
}

//  Single Number-I, tc-> O(n) & sc-> O(1)
int problem10(vector<int> &arr){
    int xorr = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) xorr = xorr ^ arr[i];
    return xorr;
}

//  Single Number-II, tc-> O(n × 32) & sc-> O(1)
int problem11_1(vector<int> &arr){
    int ans = 0;
    int n = arr.size();
    for(int bitIndex = 0; bitIndex < 31; bitIndex++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & (1 << bitIndex)) cnt++;
        }
        if(cnt % 3 == 1) ans = ans | (1 << bitIndex);
    }
    return ans;
}

//  Single Number-II, tc-> O(nlogn) + O(n/3) & sc-> O(1)
int problem11_2(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());  // O(nlogn)
    for(int i = 1; i < n; i+= 3){  // O(n/3)
        if(arr[i-1] != arr[i]) return arr[i-1];
    }
    return arr[n-1];
}

int main(){
    int n;
    cin>>n;
    // cout<<decimal2Binary(n);

    // string st;
    // cin>>st;
    // cout<<binary2Decimal(st);

    // int a, b;
    // cin>>a;
    // cin>>b;
    // swapTw0Nums(a, b);

    // int i;
    // cin>>i;
    // cout<<problem1_1(n, i);
    // cout<<problem1_2(n, i);
    // cout<<problem2(n, i);
    // cout<<problem3(n, i);
    // cout<<problem4(n, i);
    // cout<<problem5(n);
    // cout<<problem6(n);
    // cout<<problem7_1(n);
    // cout<<problem7_2(n);

    // int start, goal;
    // cin>>start;
    // cin>>goal;
    // cout<<problem8(start, goal);

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    // vector<vector<int>> res = problem9(arr);
    // for(int i = 0; i < res.size(); i++){
    //     for(int j = 0; j < res[i].size(); j++){
    //         cout<<res[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    
    // cout<<problem10(arr);
    // cout<<problem11_1(arr);
    cout<<problem11_2(arr);

    return 0;
}