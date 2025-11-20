#include<bits/stdc++.h>
using namespace std;

void markRows(vector<vector<int>>& arr, int i, int m){
    for(int j=0; j<m; j++){
        if(arr[i][j]!=0) arr[i][j]=-1;
    }
}
void markColumns(vector<vector<int>>& arr, int j, int n){
    for(int i=0; i<n; i++){
        if(arr[i][j]!=0) arr[i][j]=-1;
    }
}
// Set matrix zeroes
// brut-> below, tc-> O(n×m) × O(n+m) + O(n×m) & sc-> O(1)
// overall tc-> is near about O(n∧3)
vector<vector<int>> problem23_1(vector<vector<int>>& arr, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]==0){
                markRows(arr, i, m);
                markColumns(arr, j, n);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]==-1) arr[i][j]=0;
        }
    }
    return arr;
}

// Set matrix zeroes
// betr-> below, tc-> O(2×n×m) & sc-> O(n)+O(m)
vector<vector<int>> problem23_2(vector<vector<int>>& arr, int n, int m){
    int hashaArrayRow[n]={0};
    int hashaArrayColumn[m]={0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]==0){
                hashaArrayRow[i]=1;
                hashaArrayColumn[j]=1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(hashaArrayRow[i] || hashaArrayColumn[j]){
                arr[i][j]=0;
            }
        }
    }

    return arr;
}

// Set matrix zeroes
// opti-> below, tc-> O(2×n×m) & sc-> O(1)
vector<vector<int>> problem23_3(vector<vector<int>>& arr, int n, int m){
    // int hashaArrayRow[n]={0}; arr[0][...]
    // int hashaArrayColumn[m]={0}; arr[...][0]
    int col0=1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
                }
            }
        }
    }
    if(arr[0][0]==0){
        for(int i=0; i<m; i++) arr[0][i]=0;
    }
    if(col0==0){
        for(int i=0; i<n; i++) arr[i][0]=0;
    }
    return arr;
}

// Rotate matrix by 90 degrees
// brtf-> below, tc-> O(n∧2) & sc-> O(n∧2)
vector<vector<int>> problem24_1(vector<vector<int>>& arr, int n, int m){
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[j][n-i-1]=arr[i][j];
        }
    }
    return matrix;
}

// Rotate matrix by 90 degrees
// opti-> below, tc-> O(n/2 × n/2) + O(n × n/2) & sc-> O(1)
vector<vector<int>> problem24_2(vector<vector<int>>& arr, int n, int m){
    // Transpose, tc-> O(n/2 × n/2)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < m; j++){
                swap(arr[i][j], arr[j][i]);
        }
    }
    // Reverse, tc-> O(n × n/2)
    for(int i=0; i<n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    return arr;
}

// Print the matrix in spiral manner 
// opti-> below, tc-> O(n×m) & sc-> O(n×m)
vector<int> problem25(vector<vector<int>>& arr, int n, int m){
    int left= 0, right= m-1;
    int top= 0, bottom= n-1;
    vector<int> ans;

    while(top <=bottom && left<=right){
        for (int i = left; i <=right; i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <=bottom; i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top <=bottom){
            for (int i = right; i>=left; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i>=top; i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

// Merge overlapping intervals
// brtf-> below, tc-> O(n log n) + O(2n) & sc-> O(n)
vector<vector<int>> problem32_1(vector<vector<int>> &nums){
    int n= nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        int start= nums[i][0];
        int end= nums[i][1];
        if(!(ans.empty()) && end<=ans.back()[1]) continue;
        for(int j=i+1; j<n; j++){
            if(nums[j][0] <= end){
                end=max(end, nums[j][1]);
            }
            else break;
        }
        ans.push_back({start, end});
    }
return ans;
}

// Merge overlapping intervals
// opti-> below, tc-> O(n log n) + O(n) & sc-> O(n)
vector<vector<int>> problem32_2(vector<vector<int>> &nums){
    int n= nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int start= INT_MIN;
    int end= INT_MIN;
    for(int i=0; i<n; i++){
        if(ans.empty() && i<=0){
            start= nums[i][0];
            end= nums[i][1];   
        }
        else{
            if(nums[i][0] <= end){
                end=max(end, nums[i][1]);
            }
            else{
                ans.push_back({start, end});
                start= nums[i][0];
                end= nums[i][1];
            }
        }
    }
ans.push_back({start, end});
return ans;
// vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
//     if (intervals.empty()) return {};
//     sort(intervals.begin(), intervals.end());
//     vector<vector<int>> merged;
//     merged.push_back(intervals[0]);
//     for (int i = 1; i < intervals.size(); ++i) {
//         if (intervals[i][0] <= merged.back()[1]) {
//             merged.back()[1] = max(merged.back()[1], intervals[i][1]);
//         } else {
//             merged.push_back(intervals[i]);
//         }
//     }
//     return merged;
// }
}


int main(){
    int n, m; // rows and columns
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m)); // allocate n rows and m columns

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // vector<vector<int>> res=problem23_1(arr, n ,m);
    // vector<vector<int>> res=problem23_2(arr, n ,m);
    // vector<vector<int>> res=problem23_3(arr, n ,m);

    // vector<vector<int>> res=problem24_1(arr, n ,m);
    // vector<vector<int>> res=problem24_2(arr, n ,m);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << res[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    // vector<int> res=problem25(arr, n , m);
    // for(auto it : res){
    //     cout<<it<<"\t";
    // }

    // vector<vector<int>> res = problem32_1(arr);
    vector<vector<int>> res = problem32_2(arr);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}