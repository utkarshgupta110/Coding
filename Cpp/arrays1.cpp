#include<bits/stdc++.h>
using namespace std;

// brf-> by using sorting tc -> O(nlogn), betr-> no, opti-> below
// Finding largest element in an array, tc -> O(n)
void problem1(int ar[], int n){
    int largest= ar[0];
    for(int i=0;i<n;i++){
        if(ar[i]>largest) largest= ar[i];
    }
    cout<<largest;
}

// brf-> by using sorting, tc -> O(nlogn+n) 
//betr-> below, tc -> O(n+n) i.e. O(2n) i.e. O(n)
// Second largest element in an array without sorting 
void problem2_1(int ar[], int n){
    int largest= ar[0];
    for(int i=0;i<n;i++){
        if(ar[i]>largest) largest= ar[i];
    }
    int sLargest=-1;// Assuming all the elements in an array are positive
    for(int i=0;i<n;i++){
        if(ar[i]>sLargest && ar[i]!=largest) sLargest= ar[i];
    }
    cout<<sLargest;
}

// opti -> O(n)
// Second largest and second smallest element in an array
int secondLargest(vector<int> &arr, int n){
    int largest= arr[0];
    int slargest= -1;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            slargest= largest;
            largest= arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest= arr[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &arr, int n){
    int smallest= arr[0];
    int sSmallest= INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            sSmallest= smallest;
            smallest= arr[i];
        }
        else if(arr[i]>smallest && arr[i]<sSmallest){
            sSmallest= arr[i];
        }
    }
    return sSmallest;
}
vector<int> problem2_2(vector<int> arr, int n){
    int sLargest= secondLargest(arr, n);
    int sSmallest= secondSmallest(arr, n);
    return {sLargest, sSmallest};
}

// To check whether a given array is sorted or not, tc -> O(n)
int problem3(int ar[], int n){
    int counter=0;
    for(int i=0; i<n-1; i++){
        if(ar[i]<=ar[i+1]) counter+=1;
    }
    if(counter==n-1) cout<<"sorted array";
    else cout<<"unsorted array";
    // for(int i=0; i<n-1; i++){
    //     if(ar[i]<=ar[i+1]) {}
    //     else{
    //         return false;
    //     }
    // }
    // return true;
}

// To remove duplicates in an array using set data structure which contains only unique elements
// brtf ->below, tc -> O(nlogn+n) & sc-> O(n)
int problem4_1(set<int> &st, int ar[], int n){
    for(int i=0; i<n; i++){
        st.insert(ar[i]);
    }
    int index=0;
    for(auto it : st){
        ar[index]=it;
        index++;
    }
    return index;
}

// To remove duplicates in-place in an sorted array
// opti-> tc -> O(n) & sc-> O(1)
int problem4_2(int ar[], int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(ar[i]!=ar[j]){
            ar[i+1]=ar[j];
            i++;
        }
    }
    return i+1;
}

// Left rotate an array by one place, tc -> O(n)
// If someone says what is the space in your algorithm, then it is O(n)
// But, If someone says what is the extra space you are using, then it is O(1)
void problem5_1(int ar[], int n){
    int temp=ar[0];
    for(int i=1; i<n; i++){
        ar[i-1]=ar[i];
    }
    ar[n-1]=temp;
}

// Left rotate an array by D(can be anything) place
// brtf-> below, tc-> O(d)+O(n-d)+(d)-> O(n+d) & sc-> O(d)
void problem5_2(int ar[], int n, int d){
    d= d%n;
    // storing
    int temp[n];
    for(int i=0; i<d; i++){
        temp[i]=ar[i];
    }
    // shifting
    for(int i=d; i<n; i++){
        ar[i-d]=ar[i];
    }
    // put back temp elements
    for(int i=n-d; i<n; i++){
        ar[i]=temp[i-(n-d)];
    }
}

// Left rotate an array by D(can be anything) place
// opti-> below, tc-> O(d)+O(n-d)+(n)-> O(2n)-> O(n) & sc-> O(1)
void problem5_3(int ar[], int n, int d){
    reverse(ar, ar+d); //-> O(d)
    reverse(ar+d, ar+n);  //-> O(n-d)
    reverse(ar, ar+n);  //-> O(n)
}

// Move all the zeros to the end of an array
// brtf-> below, tc-> O(n)+O(x)+O(n-x)-> O(2n)-> O(n) & sc-> O(n)
void problem6_1(int ar[], int n){
    vector<int> vc;
    for(int j=0; j<n; j++){
        if(ar[j]!=0){
            vc.push_back(ar[j]);
        }
    }
    for(int j=0; j<vc.size(); j++){
        ar[j]=vc[j];
    }
    for(int j=vc.size(); j<n; j++){
        ar[j]=0;
    }
}

// Move all the zeros to the end of an array
// opti-> below, tc-> O(x)+O(n-x)-> O(n) & sc-> O(1)
void problem6_2(int ar[], int n){
    int i=-1;
    for(int j=0; j<n; j++){
        if(ar[j]==0){
            i=j;
            break;
        }
    }

    // no zeros found, nothing to do
    if (i==-1) return;

    for(int j=i+1; j<n; j++){
        if(ar[j]!=0){
            swap(ar[j],ar[i]);
            i++;
        }
    }
}

// Linear search, tc-> O(n)
bool problem7(int ar[], int n, int num){
    for (int i=0; i<n; i++){
        if(ar[i]==num) return true;
    }
    return false;
}

// find the missing no in the given array
// brtf-> below, tc-> O(n×n) & sc-> O(1)
int problem10_1(int ar[], int n){
    for(int i=1; i<=n; i++){
        int flag=0;
        for(int j=0; j<n-1; j++){
            if(ar[j]==i){
                flag=1;
                break;
            }
        }
    if(flag==0) return i;
    }
}

// find the missing no in the given array
// betr-> below using hashing, tc-> O(n+n) & sc-> O(n)
int problem10_2(int ar[], int n){
    int hash[n+1]={0};
    for(int i=0; i<n-1; i++){
        hash[ar[i]]=1;
    }
    for(int i=1; i<=n; i++){
        if(hash[i]==0) return i;
    }
}

// find the missing no in the given array
// opti_1-> below using sum concept, tc-> O(n) & sc-> O(1)
int problem10_3(int ar[], int n){
    int sum2=(n*(n+1))/2;
    int sum1=0;
    for(int i=0; i<n-1; i++){
        sum1+=ar[i];
    }
    return sum2-sum1;
}

// find the missing no in the given array
// opti_2-> below using xor concept, tc-> O(n) & sc-> O(1) this approach is slightly better then sum concept
int problem10_4(int ar[], int n){
    int xor1=0;
    int xor2=0;
    for(int i=0; i<n-1; i++){
        xor1=xor1^ar[i];
        xor2=xor2^(i+1);
    }
    xor2=xor2^n;
    return xor1^xor2;
}

// maximum consecutive ones
// int problem11(int ar[], int n){
//     int maximum=0;
//     int cnt=0;
//     for(int i=0; i<n; i++){
//         if(ar[i]==1){
//             cnt+=1;
//         }
//         else{
//             if(cnt>maximum) maximum=cnt;
//             cnt=0;
//         }
//     }
//     if(cnt>maximum) maximum=cnt;
//     return maximum;
// }
int problem11(int ar[], int n){
    int maximum=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(ar[i]==1){
            cnt+=1;
            maximum=max(maximum,cnt);
        }
        else{
            cnt=0;
        }
    }
    return maximum;
}

// Find the number that appears once, and other numbers twice
// brtf-> below, tc-> O(n×n) & sc-> O(1)
int problem12_1(int ar[], int n){
    for(int i=0; i<n; i++){
        int num=ar[i];
        int cnt=0;
        for(int j=0; j<n; j++){
            if(ar[j]==num){
                cnt+=1;
            }
        }
    if(cnt==1) return num;
    }
}

// Find the number that appears once, and other numbers twice
// betr-> below using array hashing, tc-> O(n+n+n) & sc-> O(n)
int problem12_2_1(int ar[], int n){
    int max=ar[0];
    for(int i=0; i<n; i++){
        if(ar[i]>max) max=ar[i];
    }
    int hash[max+1]={0};
    for(int i=0; i<max+1; i++){
        hash[ar[i]]+=1;
    }
    for(int i=0; i<max+1; i++){
        if(hash[i]==1) return i;
    }
}

// Find the number that appears once, and other numbers twice
// betr-> below using map hashing, tc-> O(nlogm) + O(n/2 +1) & sc-> O(n/2 +1)
int problem12_2_2(int ar[], int n){
    map<long long,int>mpp;
    for(int i=0; i<n; i++){
        mpp[ar[i]]++;
    }
    for(auto it: mpp){
        if(it.second==1){
            return it.first;
        }
    }
}

// Find the number that appears once, and other numbers twice
// opti-> below, tc-> O(n) & sc-> O(1)
int problem12_3(int ar[], int n){
    int xorr=0;
    for(int i=0; i<n; i++) xorr=xorr^ar[i];
    return xorr;
}

// Longest subarray with sum k (positives)
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem13_1(int ar[], int n, int k){
    int len=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=ar[j];
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}

// Longest subarray with sum k (positives as well as negatives and zeroes)
// betr-> below using hashmap, tc-> O(n logn) & sc-> O(n)
int problem13_2(int ar[], int n, int k){
    map<long long, int> prefixSumMap;
    long long sum=0;
    int maxLen=0;
    for(int i=0; i<n; i++){
        sum+=ar[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        long long rem=sum-k;
        if(prefixSumMap.find(rem)!=prefixSumMap.end()){
            int len=i-prefixSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(prefixSumMap.find(sum)==prefixSumMap.end()){
            prefixSumMap[sum]=i;
        }
    }
    return maxLen;
}

// Longest subarray with sum k (positives and zeroes)
// opti-> below using two pointers or a greedy or a sliding window approach, tc-> O(n) & sc-> O(1)
int problem13_3(int ar[], int n, int k){
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int sum = ar[0];
    while (right < n) {
        if (sum < k) {
            right++;
            if (right < n) sum += ar[right];
        }
        else if (sum > k) {
            sum -= ar[left];
            left++;
            if (left > right && left < n) {
                right = left;
                sum = ar[left];
            }
        }
        else {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
            right++;
            if (right < n) sum += ar[right];
        }
    }
    return maxLen;
    // while (right < n) {
    //     while(left<=right && sum>k){
    //         sum -= ar[left];
    //         left++;
    //     }
    //     if(sum==k){
    //          int len = right - left + 1;
    //          maxLen = max(maxLen, len);
    //     }
    //     right++;
    //     if (right < n) sum += ar[right];
    // }
    // return maxLen;
}

// 2sum problem
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
string problem14_1(int ar[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ar[i]+ar[j]==target) return "YES";
        }
    }
    return "NO";
}

// 2sum problem
// betr-> below using hashmap, tc-> O(n logn) & sc-> O(n)
vector<int> problem14_2(int ar[], int n, int target){
    map<int,int>mpp;
    for(int i=0; i<n; i++){
        int needMore=target-ar[i];
        if(mpp.find(needMore)!=mpp.end()){
            return{mpp[needMore], i};
        }
        mpp[ar[i]] = i;
    }
    return{-1,-1};
}

// 2sum problem
// opti-> below using two pointers or a greedy approach, tc-> O(n + n logn[for sorting]) & sc-> O(1)or O(n)[for distorted array]
string problem14_3(vector<int> &arr, int n, int target){
    sort(arr.begin(),arr.end());
    int left=0;
    int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum<target) left++;
        else if(sum>target) right++;
        else return "YES";
    }
    return "NO";
}

// Sort an array of 0's, 1's and 2's 
// brtf-> using sorting, betr-> below, tc-> O(2n), & sc-> O(1)
void problem15_1(int ar[], int n){
    int cnt0=0; int cnt1=0; int cnt2=0;
    for(int i=0; i<n; i++){
        if(ar[i]==0) cnt0+=1;
        else if(ar[i]==1) cnt1+=1;
        else cnt2+=1;
    }
    for(int i=0; i<cnt0; i++) ar[i]=0;
    for(int i=cnt0; i<cnt0+cnt1; i++) ar[i]=1;
    for(int i=cnt0+cnt1; i<n; i++) ar[i]=2;
}

// Sort an array of 0's, 1's and 2's 
// opti-> below using "Dutch National Flag Algorithm", tc-> O(n), & sc-> O(1)
void problem15_2(int ar[], int n){
    int a=0; int b=n-1; int c=n-1;
    while(a<=b){
        if(ar[b]==0){
            swap(ar[a], ar[b]);
            a++;
        }
        else if(ar[b]==1){
            b--;
        }
        else{
            swap(ar[b], ar[c]);
            c--;
            b--;
        }
    }
}

// Majority element(>n/2)
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem16_1(int ar[], int n){
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(ar[i]==ar[j]){
                cnt++;
            }
        if(cnt>n/2) return ar[i];
        }
    }
    return -1;
}

// Majority element(>n/2)
// betr-> below, tc-> O(n logn) + O(n), & sc-> O(n)
int problem16_2(int ar[], int n){
    map<int, int>mpp;
    for(int i=0; i<n; i++){
        mpp[ar[i]]++;
    }
    for(auto it : mpp){
        if(it.second>n/2) return it.first;
    }
    return -1;
}

// Majority element(>n/2)
// opti-> below using "Moore's Voting Algorithm", tc-> O(n) & sc-> O(1)
int problem16_3(int ar[], int n){
    int element = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt == 0){
            element = ar[i];
            cnt = 1;
        } else if(ar[i] == element){
            cnt++;
        } else {
            cnt--;
        }
    }
    // Step 2: Verify if element is actually the majority, it takes tc-> O(n) In only case, if they are stating that array might have or might not have majority element
    // And if the question clearly states that the array must have majority element then there is no need to do this verification step
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] == element) cnt1++;
    }
    if(cnt1 > n/2) return element;
    return -1;
}

// Kadane's Algorithm, maximum subarray sum  
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem17_1(int ar[], int n){
    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=ar[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}

// Kadane's Algorithm, maximum subarray sum
// opti-> below, tc-> O(n)for finding, O(n)for printing & sc-> O(1)
int problem17_2(int ar[], int n){
    // Finding Subarray
    int maxi=INT_MIN; int sum=0; int start; int ansStart= -1; int ansEnd= -1;
    for(int i=0; i<n; i++){
        if(sum==0) start=i;
        sum+=ar[i];
        if(sum>maxi){
            maxi=sum;
            ansStart=start; ansEnd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    // Printing Subarray
    for(int i=ansStart; i<=ansEnd; i++) cout<<ar[i]<<" ";
    cout<<endl;
    // Printing maximum subarray sum
    if(maxi<0) maxi=0;
    return maxi;
}

// Stock buy and sell, tc-> O(n) & sc-> O(1)
int problem18(int prices[], int n){
    int mini=prices[0]; int maxProfit=0; 
    for(int i=1; i<n; i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,prices[i]);
    }
    return maxProfit;
}

// Rearrange the array in alternating positive and negative items
// variety 1: No. of positives and negatives elements in an array are same 
// brtf-> below, tc-> O(n) + O(n/2) & sc-> O(n)
void problem19_1(int ar[], int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(ar[i]>=0){
            pos.push_back(ar[i]);
        }
        else{
            neg.push_back(ar[i]);
        }
    }
    for(int i=0; i<n/2; i++){
        ar[2*i]=pos[i];
        ar[2*i+1]=neg[i];
    }
    // No return needed, as the array is modified in-place
}

// Rearrange the array in alternating positive and negative items
// opti-> below, tc-> O(n) & sc-> O(n)
vector<int> problem19_2(int ar[], int n){
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;
    for(int i=0; i<n; i++){
        if(ar[i]>=0){
            if(posIndex < n) {
                ans[posIndex] = ar[i];
                posIndex += 2;
            }
        }
        else{
            if(negIndex < n) {
                ans[negIndex] = ar[i];
                negIndex += 2;
            }
        }
    }
    return ans;
}

// Rearrange the array in alternating positive and negative items
// variety 2: No. of positives and negatives elements in an array are not same, tc-> O(2n) & sc-> O(n)
void problem19_3(int ar[], int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(ar[i]>=0){
            pos.push_back(ar[i]);
        }
        else{
            neg.push_back(ar[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0; i<neg.size(); i++){
            ar[2*i]=pos[i];
            ar[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            ar[index]=pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            ar[2*i]=pos[i];
            ar[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            ar[index]=neg[i];
            index++;
        }
    }
}

// Next permutation, tc-> O(3n), sc-> O(1)
vector<int> problem20(vector<int> &arr, int n){
    int index=-1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=n-1; i>index; i--){
        if(arr[i]>arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

// Leaders in an array problem
// brtf-> below, tc-> O(n∧2) & sc-> O(n)
// vector<int> problem21_1(vector<int> &arr, int n){
    // vector<int> leaders;
    // for(int i=0; i<n; i++){
    //     int cnt=0;
    //     for(int j=i+1; j<n; j++){
    //         if(arr[j]<arr[i]) cnt++;
    //         else break;
    //     }      
    //     if(cnt==n-1-i){
    //         leaders.push_back(arr[i]);
    //         cnt=0;
    //     }
    // }
    // return leaders;
// }
vector<int> problem21_1(vector<int> &arr, int n){
    vector<int> leaders;
    for(int i=0; i<n; i++){
        bool isLeader = true;
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader) leaders.push_back(arr[i]);
    }
    return leaders;
}

// Leaders in an array problem
// opti-> below, tc-> O(n) & sc-> O(n)
vector<int> problem21_2(vector<int> &arr){
    vector<int>leaders;
    int n=arr.size();
    int maxi=INT_MIN;
    for (int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
            leaders.push_back(arr[i]);
        }
        // Keep track of right maximum
        maxi=max(maxi,arr[i]);
    }
    return leaders;
}

// Longest consecutive sequence in an array
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
// bool problem7(int ar[], int n, int num){
//     for (int i=0; i<n; i++){
//         if(ar[i]==num) return true;
//     }
//     return false;
// }
int problem22_1(int ar[], int n){
    int longest=1;
    for(int i=0; i<n; i++){
        int cnt=1;
        int num=ar[i];
        while(problem7(ar, n, num+1)==true){ // using problem7 as a helper function which is a linear search
            num+=1;
            cnt+=1;
        }
        longest=max(longest, cnt);
    }
    return longest;
}

// Longest consecutive sequence in an array
// betr-> below, tc-> O(n log n) + O(n) & sc-> O(1)
int problem22_2(vector<int>&arr, int n){
    sort(arr.begin(), arr.end());
    int longest=1;
    int lastSmaller=INT_MIN;
    int cntCurrent=0;
    for(int i=0; i<n; i++){
        if(lastSmaller==arr[i]-1){
            lastSmaller=arr[i];
            cntCurrent++;
        }
        else if(lastSmaller!=arr[i]){
            cntCurrent=1;
            lastSmaller=arr[i];
        }
        longest=max(longest, cntCurrent);
    }
    return longest;
}

// Longest consecutive sequence in an array
// opti-> below, tc(best, avg case)-> O(1), tc(for worst case)->O(n)& sc-> O(n)
// overall tc-> O(n)+O(2n)-> O(3n)  & sc->O(n)
int problem22_3(int ar[], int n){
    if(n==0) return 0;
    unordered_set<int>a;
    for(int i=0; i<n; i++){
        a.insert(ar[i]);
    }
    int longest=1;
    for(auto it: a){
        if(a.find(it-1)==a.end()){
            int cnt=1;
            int num=it;
            while(a.find(num+1)!=a.end()){
                num+=1;
                cnt+=1;
            }
            longest=max(longest, cnt);
        }
    }
    return longest;
}

// Count subarray with given sum (positives)
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem26_1(int ar[], int n, int k){
    int cnt=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=ar[j];
            if(sum==k){
                cnt++;
            }
        }
    }
    return cnt;
}

// Count subarray with given sum (positives as well as negatives and zeroes)
// opti-> below using hashmap, tc-> O(n logn) & sc-> O(n)
int problem26_2(int ar[], int n, int k){
    map<int, int> prefixSumMap;
    prefixSumMap[0]=1;
    int presum=0;
    int cnt= 0;
    for(int i=0; i<n; i++){
        presum+=ar[i];
        int remove=presum-k;
        cnt+= prefixSumMap[remove];
        prefixSumMap[presum]+=1;
    }
    return cnt;
}

// Majority element(>n/3)
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
vector<int> problem28_1(int ar[], int n){
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(ans.size()==0 || ans[0]!=ar[i]){
            int cnt= 0;
            for(int j=0; j<n; j++){
                if(ar[i]==ar[j]) cnt++;
            }
            if(cnt>n/3){
                ans.push_back(ar[i]);
            }
            if(ans.size()==2) break;
        }
    }
    return ans;
}

// Majority element(>n/3)
// betr1-> below, tc-> O(n logn) + O(n), & sc-> O(n)
vector<int> problem28_2_1(int ar[], int n){
    vector<int> ans;
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[ar[i]]++;
    }
    for(auto it: mpp){
        if(it.second>n/3) ans.push_back(it.first);
    }
    return ans;
}

// Majority element(>n/3)
// betr2-> below, tc-> O(n logn), & sc-> O(n)
vector<int> problem28_2_2(int ar[], int n){
    vector<int> ans;
    map<int, int> mpp;
    int min=(n/3)+1;
    for(int i=0; i<n; i++){
        mpp[ar[i]]++;
        if(mpp[ar[i]]==min) ans.push_back(ar[i]);
        if(ans.size()==2) break;
    }
    return ans;
}

// Majority element(>n/3)
// opti-> below using "Moore's Voting Algorithm", tc-> O(2n) & sc-> O(1)
vector<int> problem28_3(int ar[], int n){
    int element1 = INT_MIN, cnt1 = 0;
    int element2 = INT_MIN, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && ar[i]!=element2){
            element1 = ar[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && ar[i]!=element1){
            element2 = ar[i];
            cnt2 = 1;
        } 
        else if(ar[i] == element1){
            cnt1++;
        }
        else if(ar[i] == element2){
            cnt2++;
        }
        else {
            cnt1--, cnt2--;
        }
    }
    // Step 2: Verify if element is actually the majority, it takes tc-> O(n) In only case, if they are stating that array might have or might not have majority element
    // And if the question clearly states that the array must have majority element then there is no need to do this verification step
    vector<int> ls;
    int cntt1 = 0, cntt2=0;
    for(int i = 0; i < n; i++){
        if(ar[i] == element1) cntt1++;
        if(ar[i] == element2) cntt2++;
    }
    if(cntt1 > n/3) ls.push_back(element1);
    if(cntt2 > n/3) ls.push_back(element2);
    return ls;
}

// 3sum problem
// brtf-> below, tc-> O(n∧3 × log(no. of unique triplets)) & sc-> 2 × O(no. of triplets)
vector<vector<int>> problem29_1(int ar[], int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(ar[i]+ar[j]+ar[k]==0){
                    vector<int> temp= {ar[i], ar[j], ar[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 3sum problem
// betr-> below, tc-> O(n∧2 × log m) & sc-> O(n) + O(no. of unique triplets)
vector<vector<int>> problem29_2(int ar[], int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int k= -(ar[i] + ar[j]);
            if(hashSet.find(k)!=hashSet.end()){
                vector<int> temp= {ar[i], ar[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(ar[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 3sum problem
// opti-> below, tc-> O(n log n) + O(n∧2) & sc-> O(no. of unique triplets)
vector<vector<int>> problem29_3(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n-2; ++i) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates for i
        int left = i+1, right = n-1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                // skip duplicates for left and right
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return res;
}

// 4sum problem
// brtf-> below, tc-> O(n∧4 × log(no. of unique quads)) & sc-> 2 × O(no. of quads)
vector<vector<int>> problem30_1(vector<int>& ar, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum= ar[i] + ar[j];
                    sum+= ar[k];
                    sum+= ar[l];
                    if(sum==target){
                        vector<int> temp= {ar[i], ar[j], ar[k], ar[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 4sum problem
// betr-> below, tc-> O(n∧3 × log m) & sc-> O(n) + 2 × O(no. of unique quads)
// where, m-> variable quantity
vector<vector<int>> problem30_2(vector<int> &ar, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int> hashSet;
            for(int k=j+1; k<n; k++){
                int fourth= target-(ar[i] + ar[j] + ar[k]);
                if(hashSet.find(fourth)!=hashSet.end()){
                    vector<int> temp= {ar[i], ar[j], ar[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(ar[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// 4sum problem
// opti-> below, tc-> O(n log n) + O(n∧3) & sc-> O(no. of unique quads)
vector<vector<int>> problem30_3(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates for i
        for(int j=i+1; j<n; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicates for j
            int left = j+1, right = n-1;
            while(left < right) {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // skip duplicates for left and right
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                } else if(sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return res;
}

// Find the Missing and Repeating Number
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
vector<int> problem34_1(int ar[], int n){
    int missing= -1, repeating= -1;
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
           if(ar[j]==i) cnt++;
        }
        if(cnt==0){
            missing= i;
            cout<<"missing no. :"<<missing<<endl;
        }
        else if(cnt==2){
            repeating= i;
            cout<<"repeating no. :"<<repeating<<endl;
        }
        if(missing!= -1 && repeating!= -1) break;
    }
return {missing, repeating};
}

// Find the Missing and Repeating Number
// betr-> below, tc-> O(n logn) + O(n) & sc-> O(n)
vector<int> problem34_2(int ar[], int n){
    map<int, int> mpp;
    int repeating= -1, missing= -1;
    int totalSum=0, nonRepeatingSum=0;
    for(int i=0; i<n; i++){
        mpp[ar[i]]++;
        totalSum+=i+1;
    }
    for(auto it: mpp){
        if(it.second==2){
            repeating=it.first;
            cout<<"repeating no. :"<<it.first<<"\n";
        }
        nonRepeatingSum+=it.first;
    }
    missing= totalSum-nonRepeatingSum;
    if(missing!=0){
        cout<<"missing no. :"<<missing<<"\n";
    }
    if(missing== 0 && repeating== -1){
        return {-1, -1};
    }
    return {repeating, missing};
}

// Find the Missing and Repeating Number 
// opti1-> below, using mathematics, tc-> O(n) & sc-> O(1)
vector<int> problem34_3(int ar[], int n){
    long long sum= (n*(n+1))/2, squareSum= (n*(n+1)*(2*n+1))/6;
    long long arraySum=0, arraySquareSum=0;
    for(int i=0; i<n; i++){
        arraySum+= ar[i];
        arraySquareSum+= (long long)ar[i] * (long long)ar[i];
    }
    long long val1= arraySum-sum;
    long long val2= arraySquareSum-squareSum;
    val2= val2/val1;
    long long x= (val1+val2)/2; // repeating
    long long y= x-val1; // missing
return {(int)x, (int)y};
}

// Find the Missing and Repeating Number 
// opti2-> below, tc-> O(n) & sc-> O(1)
void problem34_4(int ar[], int n){
    cout<<"i will be doing this later when i learn bit manipulation";
}

// Count Inversions in an Array
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem35_1(int ar[], int n){
    int len=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ar[i]>ar[j]) len++;
        }
    }
    return len;
}

// Count Inversions in an Array
// opti-> below, tc-> O(n logn) & sc-> O(n)
int merge(vector<int> &arr, int n, int low, int mid, int high){ 
    int cnt=0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            cnt+= (mid-left+1);
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <=high; i++) {
        arr[i] = temp[i-low];
    }
    return cnt;
}
int problem35_2(vector<int> &arr, int n, int low, int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+= problem35_2(arr, n, low, mid);
    cnt+= problem35_2(arr, n, mid+1, high);
    cnt+= merge(arr, n, low, mid, high);
    return cnt;
}

// Reverse pairs in an Array
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem36_1(int ar[], int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ar[i]>ar[j]*2) cnt++;
        }
    }
    return cnt;
}

// Count Inversions in an Array
// opti-> below, tc-> O(2n logn) & sc-> O(n), distorting the array
int countPairs(vector<int> &arr, int n, int low, int mid, int high){
    int cnt=0;
    int right= mid+1;
    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i]>2*arr[right]) right++; // pause and restart technique
            cnt+= (right-(mid+1)); 
    }
    return cnt;
}
void merge36_2(vector<int> &arr, int n, int low, int mid, int high){ 
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <=high; i++) {
        arr[i] = temp[i-low];
    }
}
int problem36_2(vector<int> &arr, int n, int low, int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+= problem36_2(arr, n, low, mid);
    cnt+= problem36_2(arr, n, mid+1, high);
    cnt+= countPairs(arr, n, low, mid, high);
    merge36_2(arr, n, low, mid, high);
    return cnt;
}

// Maximum Product Subarray
// brtf-> below, tc-> O(n∧2) & sc-> O(1)
int problem37_1(vector<int> &arr, int n){
    int maxi= INT_MIN;
    for(int i=0; i<n; i++){
        int product=1;
        for(int j=i; j<n; j++){
            product*=arr[j];
            maxi=max(product, maxi);
        }
    }
    return maxi;
}

// Maximum Product Subarray
// opti-> below, tc-> O(n) & sc-> O(1)
int problem37_2(vector<int> &arr, int n){
    int maxi= INT_MIN;
    int prefix= 1, suffix= 1;
    for(int i=0; i<n; i++){
        if(prefix==0) prefix= 1;
        if(suffix==0) suffix= 1;
        prefix*= arr[i];
        suffix*= arr[n-i-1];
        maxi= max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;

    // int ar[n];
    // for(int i=0;i<n;i++) cin>>ar[i];

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // problem1(ar,n);
    // cout<<endl;

    // problem2_1(ar,n);
    // cout<<endl;

    // vector<int> res = problem2_2(arr, n);
    // cout << "{" << res[0] << "," << res[1] << "}";

    // problem3(ar, n);

    // set<int> st;
    // cout<<problem4_1(st, ar, n);
    
    // cout<<problem4_2(ar, n);

    // problem5_1(ar, n);
    // int d;
    // cin>>d;
    // problem5_2(ar, n, d);
    // problem5_3(ar, n, d);
    // problem6_1(ar, n);
    // problem6_2(ar, n);
    // for(int i=0; i<n; i++) cout<<ar[i]<<" ";

    // int num;
    // cin>>num;
    // cout<<problem7(ar, n, num);

    // cout<<problem10_1(ar, n);
    // cout<<problem10_2(ar, n);
    // cout<<problem10_3(ar, n);
    // cout<<problem10_4(ar, n);

    // cout<<problem11(ar, n);

    // cout<<problem12_1(ar, n);
    // cout<<problem12_2_1(ar, n);
    // cout<<problem12_2_2(ar, n);
    // cout<<problem12_3(ar, n);

    // int k;
    // cin>>k;
    // cout<<problem13_1(ar, n, k);
    // cout<<problem13_2(ar, n, k);
    // cout<<problem13_3(ar, n, k);

    // cout<<problem26_1(ar, n, k);
    // cout<<problem26_2(ar, n, k);

    // int target;
    // cin>>target;
    // cout<<problem14_1(ar, n, target);
    // vector<int> res = problem14_2(ar, n, target);
    // for (int i = 0; i < res.size(); ++i) {
    //     cout << res[i];
    //     if (i != res.size() - 1) cout << " ";
    // }
    // cout << endl;
    // cout<<problem14_3(arr, n, target);

    // problem15_1(ar, n);
    // problem15_2(ar, n);
    // for(int i=0; i<n; i++) cout<<ar[i]<<" ";

    // cout<<problem16_1(ar, n);
    // cout<<problem16_2(ar, n);
    // cout<<problem16_3(ar, n);

    // cout<<problem17_1(ar, n);
    // cout<<problem17_2(ar, n);

    // cout<<problem18(ar, n);

    // problem19_1(ar, n);
    // problem19_3(ar, n);
    // for(int i=0; i<n; i++) cout<<ar[i]<<" ";

    // vector<int> res=problem19_2(ar, n);
    // for(auto it: res){
    //     cout<<it<<" ";
    // }
    
    // vector<int> res=problem20(arr, n);
    // for(auto it: res){
    //     cout<<it<<" ";
    // }

    // vector<int> res=problem21_1(arr, n);
    // vector<int> res=problem21_2(arr);
    // for(auto it: res){
    //     cout<<it<<" ";
    // }

    // cout<<problem22_1(ar, n);
    // cout<<problem22_2(arr, n);
    // cout<<problem22_3(ar, n);

    // vector<int> res=problem28_1(ar, n);
    // vector<int> res=problem28_2_1(ar, n);
    // vector<int> res=problem28_2_2(ar, n);
    // vector<int> res=problem28_3(ar, n);
    // for(auto it: res){
    //     cout<<it<<" ";
    // }

    // vector<vector<int>> res = problem29_1(ar, n);
    // vector<vector<int>> res = problem29_2(ar, n);
    // vector<vector<int>> res = problem29_3(arr);

    // vector<vector<int>> res = problem30_1(arr, n, k);
    // vector<vector<int>> res = problem30_2(arr, n, k);
    // vector<vector<int>> res = problem30_3(arr, k);

    // cout << res.size() << endl;
    // for (int i = 0; i < res.size(); ++i) {
    //     for (int j = 0; j < res[i].size(); ++j) {
    //         cout << res[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
    // for (auto &triplet : res) {
    //     for (int num : triplet) cout << num << " ";
    //     cout << endl;
    // }
    
    // vector<int> res= problem34_1(ar, n);
    // vector<int> res= problem34_2(ar, n);
    // vector<int> res= problem34_3(ar, n);
    // for(auto it: res){
    //     cout<<it<<" ";
    // }
    // problem34_4(ar, n);

    // cout<<problem35_1(ar, n);
    // int low= 0;
    // int high= n-1;
    // cout<<problem35_2(arr, n, low, high);

    // cout<<problem36_1(ar, n);
    // cout<<problem36_2(arr, n, low, high);

    // cout<<problem37_1(arr, n);
    cout<<problem37_2(arr, n);

    return 0;
}