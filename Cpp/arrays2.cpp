#include<bits/stdc++.h>
using namespace std;

// Find the union of two sorted arrays
// brtf-> below using set ds, tc-> O(n1 logn + n2 logn) + O(n1 + n2)
// sc-> O(n1 + n2) + ..[in order to return the answer]..O(n1 + n2)
void problem8_1(set<int>&st, int arr1[], int arr2[], int n1, int n2){
    
    for(int i=0;i<n1;i++) st.insert(arr1[i]);
    for(int i=0;i<n2;i++) st.insert(arr2[i]);
    int union_result[st.size()];
    int i=0;
    for(auto it : st){
        union_result[i++]=it;
    }
    for(int i=0;i<st.size();i++) cout<<union_result[i]<<" ";
}

// Find the union of two sorted arrays
// opti-> below, tc-> O(n1 + n2)
// sc-> O(n1 + n2)..[in order to return the answer]
void problem8_2(int arr1[], int arr2[], int n1, int n2){
    int i=0;
    int j=0;
    list<int>ls;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(ls.empty() || ls.back() != arr1[i]){
                ls.push_back(arr1[i]);
            }
        i++;
        }
        else{
            if(ls.empty() || ls.back() != arr2[j]){
                ls.push_back(arr2[j]);
            }
        j++;
        }
    }
    while(i<n1){
        if(ls.empty() || ls.back() != arr1[i]){
            ls.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(ls.empty() || ls.back() != arr2[j]){
            ls.push_back(arr2[j]);
        }
        j++;
    }
    for(auto it : ls){
        cout<<it<<" ";
    }
}

// Find the intersection of two sorted arrays
// brtf-> below, tc O(n1×n2), sc-> O(n2) or can be O(n1) based on which is smaler, as we assign visited array to the smaller-sized array
void problem9_1(int arr1[], int arr2[], int n1, int n2){
    list<int>intersectionList;
    int visitedArr[n2]={0};
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(arr2[j]==arr1[i] && visitedArr[j]==0){
                intersectionList.push_back(arr1[i]);
                visitedArr[j]=1;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }
    for(auto it : intersectionList){
        cout<<it<<" ";
    }
}

// Find the intersection of two sorted arrays
// opti-> below, tc-> O(n1+n2), sc-> O(1) and also sc-> O(n1+n2) in order to store and return the answer
void problem9_2(int arr1[], int arr2[], int n1, int n2){
    int i=0;
    int j=0;
    list<int>ls;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ls.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(auto it : ls){
        cout<<it<<" ";
    }
}
  
// Merge Sorted Arrays Without Extra Space
// brtf-> below, tc-> O(n1+n2) + O(n1+n2) & sc-> O(n1+n2)
vector<vector<int>> problem33_1(int arr1[], int arr2[], int n1, int n2){
    vector<vector<int>> ans;
    vector<int> arr3;
    int i= 0;
    int j= 0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
        }
        else{
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        arr3.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        arr3.push_back(arr2[j]);
        j++;
    }
    for(int i=0; i<n1+n2; i++){
        if(i<n1) arr1[i]= arr3[i];
        else arr2[i-n1]= arr3[i];
    }
    vector<int> merged1;
    vector<int> merged2;
    for(int i=0; i<n1+n2; i++){
        if(i<n1) merged1.push_back(arr1[i]);
        else merged2.push_back(arr2[i-n1]);
    }
    ans.push_back(merged1);
    ans.push_back(merged2);
return ans;
}

// Merge Sorted Arrays Without Extra Space
// opti1-> below, tc-> O(min(n1, n2)) + O(n1 log n1) + O(n2 log n2) & sc-> O(1)
vector<vector<int>> problem33_2_1(int arr1[], int arr2[], int n1, int n2){
    vector<vector<int>> ans;
    int i= n1-1;
    int j= 0;
    while(i>=0 && j<n2){
        if(arr2[j]<arr1[i]){
            swap(arr1[i], arr2[j]);
            i--; j++;
        }
        else{
            break;
        }
    }

    sort(arr1, arr1+n1);
    sort(arr2, arr2+n2);

    vector<int> sorted1;
    vector<int> sorted2;
    for(int i=0; i<n1+n2; i++){
        if(i<n1) sorted1.push_back(arr1[i]);
        else sorted2.push_back(arr2[i-n1]);
    }
    ans.push_back(sorted1);
    ans.push_back(sorted2);
return ans;
}

// Merge Sorted Arrays Without Extra Space
// opti2-> below, using "gap method" or "shell sort technique" tc-> O(log(n1+n2)) × O(n1+n2) & sc-> O(1)
void swapGreater(int arr1[], int arr2[], int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}
vector<vector<int>> problem33_2_2(int arr1[], int arr2[], int n1, int n2){
    vector<vector<int>> ans;
    int len= n1+n2;
    int gap= (len/2) + (len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<n1 && right>=n1){
                swapGreater(arr1, arr2, left, right-n1);
            }
            else if(left>=n1){
                swapGreater(arr2, arr2, left-n1, right-n1);
            }
            else{
                swapGreater(arr1, arr1, left, right);
            }
            left++; right++;
        }
        if(gap==1) break;
        gap= (gap/2) + (gap%2);
    }
    vector<int> sorted1;
    vector<int> sorted2;
    for(int i=0; i<n1+n2; i++){
        if(i<n1) sorted1.push_back(arr1[i]);
        else sorted2.push_back(arr2[i-n1]);
    }
    ans.push_back(sorted1);
    ans.push_back(sorted2);
return ans;
}

int main(){
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;

    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++) cin>>arr1[i];
    for(int i=0;i<n2;i++) cin>>arr2[i];

    set<int>st;

    // problem8_1(st, arr1, arr2, n1, n2);
    // problem8_2(arr1, arr2, n1, n2);

    // problem9_1(arr1, arr2, n1, n2);
    // problem9_2(arr1, arr2, n1, n2);

    // vector<vector<int>> res= problem33_1(arr1, arr2, n1, n2);
    // vector<vector<int>> res= problem33_2_1(arr1, arr2, n1, n2);
    vector<vector<int>> res= problem33_2_2(arr1, arr2, n1, n2);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}
