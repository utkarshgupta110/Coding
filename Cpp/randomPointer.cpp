#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int val){
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for(int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i]); 
        mover-> next= temp; // link
        mover= temp;
    }
    return head;
}

void traversal_LL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}

void link_RandomPtr(Node* head){
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
}

// Approach-> brut, Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers, tc-> O(2N) & sc-> O(N) + {O(N).... this is req. in ques i.e. copyNode}
Node* problem24_1(Node* head){
    Node* temp = head;
    map<Node*, Node*> mpp;
    while(temp != nullptr){
        Node* copyNode = new Node(temp->data);
        mpp[temp] = copyNode;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

// Approach-> opti, Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers, tc-> O(3N) & sc-> {O(N).... this is required. in ques i.e. creating copyNodes}
/* Steps:
1. Insert copyNode in between.
2. Connect random pointers.
3. Connect next pointers.
*/
Node* problem24_2(Node* head){
    Node* temp = head;
    // Step 1:
    while(temp != nullptr){
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    // Step 2:
    temp = head;
    while(temp != nullptr){
        if(temp->random) temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    // Step 3:
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    temp = head;
    while(temp != nullptr){
        // Creating new list
        res->next = temp->next;
        temp->next = temp->next->next;

        // Disconnecting and going back initial state of linked list
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}






int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    Node* head = convertArr2LL(arr);
    link_RandomPtr(head);

    // head = problem24_1(head);
    head = problem24_2(head);

    traversal_LL(head);

    return 0;
}