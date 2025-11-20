#include<iostream>
using namespace std;

// printing nos. from n to 1 using backtracking, tc & sc = O(n)
int problem1(int i, int n){
    if(i>n) return 0;
    problem1(i+1,n);
    cout<< i<< endl;
}
// sum of first n nos.(parameterized way), tc & sc = O(n)
int problem2(int i, int sum){
    if(i<1) {
        cout << sum << endl;
        return 0;
    }
    problem2(i-1,sum+i);
}
// sum of first n nos.(functional way), tc & sc = O(n)
int problem3(int i){
    if(i==0) return 0;
    return i + problem3(i-1);
}
//factorial of n, tc & sc = O(n)
int problem4(int i){
    if(i==0) return 1;
    return i * problem4(i-1);
}
// reverse an array using two pointers
int problem5(int arr[], int l, int r){
    if(l>=r) return 0;
    swap(arr[l],arr[r]);
    return problem5(arr, l+1, r-1);
}
// reverse an array using one pointer or one variable
void problem6(int arr[], int l, int n){
    if(l>=n/2) return;
    swap(arr[l],arr[n-l-1]);
    problem6(arr, l+1, n);
}
// 1. checking if a given string is palindrome using one pointer or one variable
void problem7(string &str, int i, int s){
    if(i>=s/2) return;
    swap(str[i],str[s-i-1]);
    problem7(str, i+1, s);
}
// 2. checking if a given string is palindrome (functional way)
bool problem8(string &str, int i, int s){
    if(i>=s/2) return true;
    if (str[i]!=str[s-i-1]) return false;
    problem8(str, i+1, s);
    if (str[i]==str[s-i-1]) return true; 
}
// Fibonacci number using for loop tc= O(n)
void problem9(int fib[], int n){
        for (int i=2; i<=n; i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
}
// Fibonacci number using functional recursion tc≈ O(2∧n)
int problem10(int n){
    if(n<=1) return n;
    int last= problem10(n-1);
    int secondLast= problem10(n-2);
    return last + secondLast;
}

int main(){
    int n;
    cin>>n;
    //problem1(1,n);
    //problem2(n,0);
    //cout<<problem3(n);
    //cout<<problem4(n);

    //int arr[n];
    //for(int i=0; i<n; i++) cin>>arr[i];
    //problem5(arr, 0, n-1);
    //problem6(arr, 0, n);
    //for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    

    /*string s;
    cin>>s;
    string dup= s;
    problem7(s, 0, s.size());
    if(dup==s) cout<<"string is palindrome";
    else cout<<"string is not palindrome";*/
    //cout<<problem8(s, 0, s.size());

    /*int fib[n];
    fib[0]=0;
    fib[1]=1;
    problem9(fib, n);
    for(int i=0; i<=n; i++) cout<<fib[i]<<" ";
    cout<<endl<<fib[n];*/

    cout<<problem10(n);
       
    return 0;
}