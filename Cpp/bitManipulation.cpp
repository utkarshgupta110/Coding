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
    cout<<problem7_2(n);

    return 0;
}