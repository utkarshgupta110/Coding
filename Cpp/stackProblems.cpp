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

// Infix to Postfix conversion, tc-> O(n) + O(n) & sc-> O(n) + O(n)
int priority(char op){
    if(op == '^') return 3;
    else if((op == '*') || (op == '/')) return 2;
    else if((op == '+') || (op == '-')) return 1;
    else return -1;
}
string problem2(string s){
    stack<char> st;
    string ans = "";
    int n = s.size();
    for(int i = 0; i < n; i++){
        if((s[i] >= 'A' && s[i] <= 'Z') ||
           (s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= '0' && s[i] <= '9')) ans += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!(st.empty()) && (st.top() != '(')){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!(st.empty()) && (priority(s[i]) <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

// Infix to Prefix conversion, tc-> ~ O(4n) & sc-> O(2n)
string problem3(string s){
    int n = s.size();
    reverse(s.begin(), s.end()); // O(n/2)
    for(int i = 0; i < n; i++){  // O(n)
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    stack<char> st;
    string ans = "";
    for(int i = 0; i < n; i++){  // O(n)
        if((s[i] >= 'A' && s[i] <= 'Z') ||
           (s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= '0' && s[i] <= '9')) ans += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!(st.empty()) && (st.top() != '(')){ // throughout the iteration it is O(n)
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!(st.empty()) && (priority(s[i]) <= priority(st.top()))){  // throughout the iteration it is O(n)
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!(st.empty()) && (priority(s[i]) < priority(st.top()))){  // throughout the iteration it is O(n)
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){  // throughout the iteration it is O(n)
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());  // O(n/2)
    return ans;
}

// Postfix to Infix conversion, tc-> O(n) + O(n) & sc-> O(n)
string problem4(string s){
    int i = 0;
    stack<string> st;
    int n = s.size();
    while(i < n){ // O(n)
        if((s[i] >= 'A' && s[i] <= 'Z') ||
           (s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= '0' && s[i] <= '9')) st.push(string(1, s[i]));
        else{
            // operator: need at least two operands
            if(st.size() < 2){
                // invalid expression
                return "INVALID"; // or throw, or return "INVALID"
            }
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string str = "(" + top2 + string(1, s[i]) + top1 + ")";
            st.push(str);
        }
        i++;
    }
    if(!st.empty()) return st.top();
    return "";
}

int main(){
    string str;
    cin >> str;
    // cout << problem1(str);
    // cout << problem2(str);
    // cout << problem3(str);
    cout << problem4(str);

    return 0;
}