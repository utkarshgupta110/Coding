#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data= val;
        next= nullptr;
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

vector<int> traversal_LL(Node* head){
    vector<int> ans;
    Node* temp = head;
    while(temp != nullptr){
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return ans;
}

int length_LL(Node* head){
    Node* temp= head;
    int cnt=0;
    while(temp != nullptr){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int search){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == search) return 1;
        temp = temp->next;
    }
    return 0;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);  // delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp= head;
    while(temp->next->next != nullptr){
        temp= temp->next;
    }
    free(temp->next);
    temp-> next= nullptr;
    return head;
}

// Remove element at given position k
Node* remove_k(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        head =removeHead(head);
        return head;
    }
    int cnt =0;
    Node* temp= head;
    Node* prev= nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev= temp;
        temp= temp->next;
    }
    return head;
}

// Remove given element k
Node* remove_el_k(Node* head, int k){
    if(head == NULL) return head;
    if(head->data == k){
        head =removeHead(head);
        return head;
    }
    Node* temp= head;
    Node* prev= nullptr;
    while(temp != nullptr){
        if(temp->data == k){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev= temp;
        temp= temp->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int k){ // tc-> O(1)
    if(head == NULL) return new Node(k);
    Node* newHead = new Node(k);
    newHead->next = head;
    return newHead;
}

Node* insertAtTail(Node* head, int k){
    if(head == NULL) return new Node(k);
    Node* temp = head;
    Node* newTail = new Node(k);
    while(temp->next != nullptr){
        temp =temp->next;
    }
    temp->next = newTail;
    return head;
}

// Insert element at given position k
Node* insertAt_kth_pos(Node* head, int element, int k){
    if(head == NULL && k == 1) return new Node(element);
    if(k == 1){
        head =insertAtHead(head, element);
        return head;
    }
    int cnt =0;
    Node* temp= head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(element);
            newNode->next= temp->next;
            temp->next= newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

// Insert element before the value k
Node* insertAt_el_k(Node* head, int element, int k){
    if(head == NULL) return NULL;
    if(k == head->data){
        head =insertAtHead(head, element);
        return head;
    }
    Node* temp= head;
    while(temp->next != nullptr){
        if(temp->next->data == k){
            Node* newNode = new Node(element);
            newNode->next= temp->next;
            temp->next= newNode;
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
 /* Node x= Node(arr[2]);
    cout << x.data;

    Node* y= &x;
    cout << y->data;
    
    Node n(arr[4]);
    cout << n.data; */

    Node* head = convertArr2LL(arr);
    // cout<<head->data;

    // vector<int> res = traversal_LL(head);
    // for(int i=0; i<res.size(); i++) cout<<res[i]<<"\t";
    // cout<<endl;

    // cout<<length_LL(head);

    // int search;
    // cin>>search;
    // cout<<checkIfPresent(head, search);
     
    // head= removeHead(head);
    // head= removeTail(head);
    int k; cin>>k;
    // head= remove_k(head, k);
    // head= remove_el_k(head, k);
    // head= insertAtHead(head, k);
    // head= insertAtTail(head, k);
    int element; cin>>element;
    // head= insertAt_kth_pos(head, element, k);
    head= insertAt_el_k(head, element, k);
    vector<int> res1 = traversal_LL(head);
    for(int i=0; i<res1.size(); i++) cout<<res1[i]<<"\t";
    return 0;
}