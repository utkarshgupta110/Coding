#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    // constructor 1
    Node(int Data, Node* Next, Node* Prev){
        data= Data;
        next= Next;
        prev= Prev;
    }

    // constructor 2
    Node(int Data){
        data= Data;
        next= nullptr;
        prev= nullptr;
    }

};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

vector<int> traversal_DLL(Node* head){
    vector<int> ans;
    Node* temp = head;
    while(temp != nullptr){
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return ans;
}

// Approach-> brut, Reverse a doubly linked list, tc-> O(2N) & sc-> O(N)
Node* problem1_1(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Approach-> opti, Reverse a doubly linked list, tc-> O(N) & sc-> O(1)
Node* problem1_2(Node* head){
    Node* last = nullptr;
    Node* temp = head;
    while(temp != nullptr){
        last = temp->prev;
        temp->prev = temp-> next;
        temp->next = last;
        temp = temp->prev;
    }
    return last->prev;
}

// Delete all the occurences of a key in the doubly linked list, tc-> O(N) & sc-> O(1)
Node* problem15(Node* head, int key){
    if(head->data == key){
        Node* deleteHead = head;
        head = head->next;
        head->prev =nullptr;
        free(deleteHead);
    }
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            Node* deleteTemp = temp;
            temp->prev->next = temp->next;
            if(temp->next != nullptr) temp->next->prev = temp->prev;
            temp = temp->prev;
            free(deleteTemp);
        }
        temp = temp->next;
    }
    return head;
}

// Approach-> brut, Find pairs with given sum in sorted doubly linked list(2 sum), tc-> O(N^2) & sc-> O(1)
vector<vector<int>> problem16_1(Node* head, int sum){
    vector<vector<int>> ans;
    Node* temp1 = head;
    while(temp1 != nullptr){
        Node* temp2 = temp1->next;
        while(temp2 != nullptr && temp1->data + temp2->data <= sum){
            if(temp1->data + temp2->data == sum) ans.push_back({temp1->data, temp2->data});
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

// Approach-> opti, Find pairs with given sum in sorted doubly linked list(2 sum), tc-> O(2N) & sc-> O(1)
Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    return tail;
}
vector<vector<int>> problem16_2(Node* head, int sum){
    vector<vector<int>> ans;
    if(head == nullptr) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data){
        if(left->data + right->data < sum) left = left->next;
        else if(left->data + right->data > sum) right = right->prev;
        else{
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
    }
    return ans;
}

// Remove duplicates from sorted DLL, tc-> O(N) & sc-> O(1)
Node* problem17(Node* head){
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && temp->data == nextNode->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = nextNode;
    }
    return head;
}









int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    Node* head = convertArr2DLL(arr);

    // head= problem1_1(head);
    // head= problem1_2(head);
    // int key; cin>>key;
    // head = problem15(head, key);
    // int sum; cin>>sum;
    // vector<vector<int>> res = problem16_1(head, sum);
    // vector<vector<int>> res = problem16_2(head, sum);
    // for(int i=0; i<res.size(); i++){
    //     for(int j=0; j<res[i].size(); j++) {
    //         cout<<res[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    head= problem17(head);

    vector<int> res1 = traversal_DLL(head);
    for(int i=0; i<res1.size(); i++) cout<<res1[i]<<"\t";
    // return 0;
}











