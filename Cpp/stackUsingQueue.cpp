#include<bits/stdc++.h>
using namespace std;

class StackImpl{                               // Overall, tc-> O(n) & sc-> O(dynamic)
    public:
    queue<int> q;                          
    
    void push(int val){                        // O(n)
        q.push(val);
        int length = q.size();
        for(int i = 0; i < length - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int top(){                                 // O(1)       
        return q.front();
    }

    void pop(){                                // O(1)
        q.pop();
    }

    int size(){                                // O(1)
        return q.size();
    }
};

int main(){
    StackImpl st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    st.push(5);
    cout << st.top() << endl;

    return 0;
}