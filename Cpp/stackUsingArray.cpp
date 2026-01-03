#include<bits/stdc++.h>
using namespace std;

class StackImpl{                      // Overall, tc-> O(1) but {sc-> O(n)[drawback-> might take some extra space]}
    public:
    int topIndex = -1; 
    int n;
    vector<int> st;
    StackImpl(int val){
        n = val;
        st.resize(n);
    }
    
    void push(int val){                            // O(1)
        if(topIndex >= n -1) {
            cout<<"Stack Overflow"<<"\n"; 
            return; 
        }
        st[topIndex + 1] = val;
        topIndex += 1;
    }

    int top(){                                     // O(1)
        if(topIndex == -1) {
            cout<<"Stack is empty"<<"\n"; 
            return -1; 
        }
        return st[topIndex];
    }

    void pop(){                                    // O(1)
        if(topIndex == -1) {
            cout<<"Stack Underflow"<<"\n"; 
            return; 
        }
        topIndex -= 1;
    }

    int size(){                                    // O(1)
        return topIndex + 1;
    }
};

int main(){
    int n;
    cin>>n;
    StackImpl st = StackImpl(n);
    st.push(4);
    st.pop();
    st.pop();
    cout << st.top() << endl;
    
    return 0;
}