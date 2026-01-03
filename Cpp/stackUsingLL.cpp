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

class StackImpl{  // Overall, tc-> O(1) & {sc-> O(dynamic), as LL is dynamic in nature} 
    public:
    Node* topNode = nullptr;
    int length = 0;

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        length++;
    }

    int top(){
        if(topNode == nullptr){
            cout << "Stack is empty: "; 
            return -1;
        }
        else return topNode->data;
    }

    void pop(){
        if(topNode == nullptr) cout << "Stack Underflow" << "\n";
        else{
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            length--;
        }
    }

    int size(){
        return length;
    }
};

int main(){
    StackImpl st;
    st.push(4);
    cout << st.top() << endl;
    st.push(2);
    st.push(3);
    st.push(1);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.push(7);
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.push(7);
    st.push(8);
    cout << st.size() << endl;

    return 0;
}
