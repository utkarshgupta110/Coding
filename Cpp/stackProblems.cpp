#include<bits/stdc++.h>
using namespace std;

// Check for Balanced Parentheses, tc-> O(n) & sc-> O(n)
bool problem1(string s){
    stack<char> st;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top(); st.pop();
            if(!((ch == '(' && s[i] == ')') || (ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']')))
                return false;
        }
    }
    return st.empty();
}















int main(){
    string str;
    cin >> str;
    cout << problem1(str);

    return 0;
}