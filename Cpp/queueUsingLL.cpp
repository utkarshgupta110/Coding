#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class QueueImpl{  // Overall, tc-> O(1) & {sc-> O(dynamic), as LL is dynamic in nature} 
    public:
    Node* start = nullptr;
    Node* end = nullptr;
    int currSize = 0;

    void push(int val){                                               // O(1)
        Node* newNode = new Node(val);
        if(start == nullptr && end == nullptr){
            start = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end = newNode;
        }
        currSize++;
    }

    int top(){                                                        // O(1)
        if(currSize == 0){
            cout << "Queue is empty: "; 
            return -1;
        }
        return start->data;
    }

    void pop(){                                                       // O(1)
        if(currSize == 0) cout << "Queue Underflow" << "\n";
        else{
            Node* temp = start;
            start = start->next;
            delete temp;
            currSize--;
        }
        if(start == nullptr) end = nullptr;
    }

    int size(){                                                       // O(1)
        return currSize;
    }
};

int main(){
    QueueImpl q;
    q.push(7);
    q.push(2);
    q.push(3);
    q.push(5);
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.size() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    q.pop();
    cout << q.top() << endl;
    
    return 0;
}