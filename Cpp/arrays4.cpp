#include<bits/stdc++.h>
using namespace std;

// 1. These Pascal Triangle functions are mostly correct for small values of n
long long factorial(long long val){
    long long fact= 1;
    while(val>0){
        fact=fact*val;
        val--;
    }
    return fact;
}
long long nCr(long long R, long long C){
    long long n= factorial(R);
    long long r= factorial(C);
    long long nSubr= factorial(R-C);
    long long ans= n/(r*nSubr);
    return ans;
}

// Pascal Triangle | Finding nCr in minimal time(below all type que(s))
// Type 1: Given r and c tell the element at that place, tc-> O(R) + O(C) + O(R-C) & sc-> O(1)
long long problem27_1(long long r, long long c){
    return nCr(r-1, c-1);
}

// Type 2: Print any Nth row of the Pascal triangle, tc-> O(n×r) & sc-> O(1)
vector<long long> problem27_2(long long n){
    vector<long long> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(problem27_1(n, i));
    }
    return ans;
}

// Type 3: Given N, print the entire Pascal triangle, tc-> O(n∧3) & sc-> O(1)
vector<vector<long long>> problem27_3(long long n){
    vector<vector<long long>> ans;
    for(int i=1; i<=n; i++){
        vector<long long> row;
        for(int j=1; j<=i; j++){
            row.push_back(problem27_1(i, j));
        }
        ans.push_back(row);
    }
    return ans;
}


// -----------------------------------------------------------------------------------------------------------//

// 2. These Pascal Triangle functions are correct for small as well as large values of n
int new_Optimised_nCr(int n, int r){
    long long res=1;
    for(int i=0; i<r; i++){ //tc-> O(r)
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

// Pascal Triangle | Finding nCr in minimal time(below all type que(s))
// Type 1: Given r and c tell the element at that place, tc-> O(r)  & sc-> O(1)
int problem27_1_1(int r, int c){
    return new_Optimised_nCr(r-1, c-1);
}

// Type 2: Print any Nth row of the Pascal triangle, tc-> O(n) & sc-> O(1) 
vector<int> problem27_2_2(int row){
    long long res=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++){
        res=res*(row-col);
        res=res/col;
        ansRow.push_back(res);
    }
    return ansRow;
}

// Type 3: Given N, print the entire Pascal triangle, tc-> O(n∧2) & sc-> O(1)
vector<vector<int>> problem27_3_3(int n){
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(problem27_2_2(i)); 
    }
    return ans;
}








int main(){
    // int r, c;
    // cin>> r >> c;
    // // cout<<problem27_1(r, c);
    // cout<<problem27_1_1(r, c);

    int n;
    cin>> n;
    // // vector<long long> res=problem27_2(n);
    // vector<int> res=problem27_2_2(n);
    // for(auto it : res){
    //     cout<<it<<"\t";
    // }

    // vector<vector<long long>> res=problem27_3(n);
    vector<vector<int>> res=problem27_3_3(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <=i ; j++) {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}




