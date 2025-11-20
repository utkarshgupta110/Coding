#include<bits/stdc++.h>
using namespace std;

// counting frequencies of array elements(number hashing)
void problem1(int arr[], int arr_size, int hash[], int queries){
    for(int i=0; i<arr_size; i++){
        cin>> arr[i];
        // pre-compute
        hash[arr[i]]+=1;
    }
    while(queries--){
        int number;
        cin>> number;
        // fetch
        cout<<hash[number]<<endl;
    }
}
// counting frequencies of array elements(character hashing)
void problem2(string s, int hash[], int queries){
    for(int i=0; i<s.size(); i++){
        // pre-compute
        hash[s[i]-'a']+=1; // logic here is for lowercase : ch-'a'
                           // for uppercase : ch-'A'
                           // if mixed use 256 as size of hash array
    }
    while(queries--){
        char alph;
        cin>> alph;
        // fetch
        cout<<hash[alph-'a']<<endl;
    }
}
// counting frequencies of array elements(number map hashing)
void problem3(map<int, int>& mpp, int arr_size, int arr[], int queries){
    for(int i=0; i<arr_size; i++){
        cin>> arr[i];
        // pre-compute
        mpp[arr[i]]+=1;
    }
    for(auto it : mpp){
        cout<< it.first<< "->"<< it.second << endl;
    }
    while(queries--){
        int number;
        cin>> number;
        // fetch
        cout<<mpp[number]<<endl;
    }
}
// counting frequencies of array elements(character map hashing)
void problem4(string s, map<char, int>& mp, int queries){
    for(int i=0; i<s.size(); i++){
        // pre-compute
        mp[s[i]]+=1;
    }
    while(queries--){
        char alph;
        cin>> alph;
        // fetch
        cout<<mp[alph]<<endl;
    }
}

int main(){
    // declaring array
    int arr_size;
    cin>> arr_size;
    int arr[arr_size];

    // declaring string
    string s;
    cin>> s;

    int queries;
    cin>>queries;

    // declaring hash array
    int hash[26]={0};

    // declaring map for storing intezers as key
    map<int,int> mpp;

    // declaring map for storing characters as key
    map<char,int> mp;

    problem1(arr, arr_size, hash, queries);
    cout<< endl;
    problem2(s, hash, queries);
    cout<< endl;
    problem3(mpp, arr_size, arr, queries);
    cout<< endl;
    problem4(s, mp, queries);
    return 0;
}
