#include<bits/stdc++.h>
using namespace std;

class QueueImpl{  // Overall, tc-> O(2n) & sc-> O(2 × dynamic)
    public:
    stack<int> s1, s2;

    void push(int val){                        // O(2n)
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int top(){                                 // O(1)
        return s1.top();
    }

    void pop(){                                // O(1)
        s1.pop();
    }

    int size(){                                // O(1)
        return s1.size();
    }
};

class QueueImpl_Optimal{  // Overall, tc-> O(n) & sc-> O(2 × dynamic)
    public:
    stack<int> s1, s2;

    void push(int val){                          // O(1)
        s1.push(val);
    }

    int top(){
        if(!s2.empty()) return s2.top();
        else{
            while(s1.size()){                    // Ocassionaly, tc-> O(n)
                s2.push(s1.top());
                s1.pop();   
            }
            return s2.top();
        }
        return -1;
    }

    void pop(){
        if(!s2.empty()) s2.pop();
        else{
            while(s1.size()){                    // Ocassionaly, tc-> O(n) i.e. not always taking that time
                s2.push(s1.top());
                s1.pop();   
            }
            s2.pop();
        }
    }

    int size(){                                  // O(1)
        return s1.size() + s2.size();
    }
};

int main(){
    QueueImpl q;
    q.push(4);
    q.push(2);
    q.push(3);
    q.push(5);
    cout << q.top() << endl;
    q.pop();
    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;
    q.push(6);
    cout << q.top() << endl;
    cout << q.size() << endl;

    cout << endl;

    QueueImpl_Optimal Q;
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    cout << Q.top() << endl;
    cout << Q.top() << endl;
    Q.pop();                                                                                                                        
    Q.push(1);
    Q.push(1);
    cout << Q.size() << endl;
    Q.pop();                                                                                                                        
    Q.pop();                                                                                                                        
    Q.pop();                                                                                                                        
    cout << Q.top() << endl;
    Q.pop();   
    cout << Q.size() << endl;             

    return 0;
}