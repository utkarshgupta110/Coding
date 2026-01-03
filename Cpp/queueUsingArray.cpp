#include<bits/stdc++.h>
using namespace std;

class QueueImpl{              // Overall, tc-> O(1) but {sc-> O(capacity)[drawback-> might take some extra space]}
    public:
    int start;
    int end;
    int capacity;
    int currSize;
    vector<int> q;

    QueueImpl(int val){
        capacity = val;
        q.resize(capacity);
        start = end = -1;
        currSize = 0;
    }

    void push(int val){                           // O(1)
        if(currSize < capacity){
            if(currSize == 0) start = end = 0;
            else end = (end + 1) % capacity;
            q[end] = val;
            currSize++;
        } 
        else {
            cout<<"Queue Overflow"<<"\n";
        }
    }

    int top(){                                    // O(1)
        if(currSize == 0){
            cout<<"Queue is empty"<<"\n";
            return -1;
        }
        return q[start];
    }

    int pop(){                                    // O(1)
        if(currSize == 0){
            cout<<"Queue Underflow"<<"\n";
            return -1;
        }
        int element = q[start];
        if(currSize == 1){
            start = end = -1;
            currSize = 0;
        }
        else{
            start = (start + 1) % capacity;
            currSize--;
        }
        return element;
    }

    int size(){                                   // O(1)
        return currSize;
    }
};

int main(){
    int size;
    cin>>size;
    QueueImpl q = QueueImpl(size);
    q.push(3);
    q.push(2);
    q.push(4);
    q.push(4);
    q.push(4);
    cout << q.size() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    
    return 0;
}