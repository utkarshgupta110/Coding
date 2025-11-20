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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    Node* newTail = temp->prev;
    newTail->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteAt_pos(Node* head, int pos){
    if(head == NULL) return NULL;
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    if(temp == nullptr) return head; // for pos>n
    Node* back = temp->prev;
    Node* front = temp->next;
    if(back == nullptr && front == nullptr){
        delete temp;
        return NULL;
    }
    else if(back == nullptr) return deleteHead(head);
    else if(front == nullptr) return deleteTail(head);
    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

void deleteNode(Node* temp){
    Node* back = temp->prev;
    Node* front = temp->next;
    if(front == NULL){
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;
    temp->next = temp->prev = nullptr;
    delete temp;
}

Node* insertAt_pos(Node* head, int element, int pos){
    if(head == NULL && pos == 1) return new Node(element);
    if(pos == 1){
        Node* newNode = new Node(element, head, nullptr);
        head->prev = newNode;
        return newNode;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos-1){
            Node* newNode = new Node(element, temp->next, temp);
            temp->next = newNode;
            if(newNode->next != nullptr) newNode->next->prev = newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    Node* head = convertArr2DLL(arr);
    // head= deleteHead(head);
    // head= deleteTail(head);
    int pos;
    cin>>pos;
    // head= deleteAt_pos(head, pos);
    // deleteNode(head->next);
    int element;
    cin>>element;
    head= insertAt_pos(head, element, pos);
    vector<int> res1 = traversal_DLL(head);
    for(int i=0; i<res1.size(); i++) cout<<res1[i]<<"\t";
    // return 0;
}