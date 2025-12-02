#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    if(arr.size() == 0) return NULL;
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for(int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i]); 
        mover-> child= temp; // link
        mover= temp;
    }
    return head;
}

Node* convertLL2branchLL(Node* head1, Node* head2, Node* head3, Node* head4, Node* head5){
    Node* head = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    return head;
}

vector<vector<int>> traversalBranchLL(Node* head){
    vector<vector<int>> res;
    Node* temp1 = head;
    while(temp1 != nullptr){
        Node* temp2 = temp1;
        vector<int> res1;
        while(temp2 != nullptr){
            res1.push_back(temp2->data);
            temp2 = temp2->child;
        }
        res.push_back(res1);
        temp1 = temp1->next;
    }
    return res;
}

vector<int> traversal_LL(Node* head){
    vector<int> ans;
    Node* temp = head;
    while(temp != nullptr){
        ans.push_back(temp->data);
        temp = temp->child;
    }
    return ans;
}

// Approach-> brut, Flattening a LinkedList, tc-> O(2X) + O(X logX) & sc-> O(2X)
Node* problem21_1(Node* head){
    vector<int> res;
    Node* temp1 = head;
    while(temp1 != nullptr){                       // O(N × M) i.e. O(X)
        Node* temp2 = temp1;
        while(temp2 != nullptr){
            res.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp1 = temp1->next;
    }
    sort(res.begin(), res.end());                  // O(X logX) 
    head = convertArr2LL(res);                     // O(X), where X-> N × M
    return head;
}

// Approach-> opti, Flattening a LinkedList, tc-> O(2NM) & {sc-> O(N) i.e. recursive stack space}
// here, assuming that, N-> length of vertical line (recursion happens N times)
// and M-> length of horizontal line (and at each N time merge happens 2M times) hence, tc is approx O(2NM)
Node* merge2Lists(Node* head1, Node* head2){ // O(2M)
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            temp->child = temp1;
            temp = temp1;
            temp1 = temp1->child;
        }
        else{
            temp->child = temp2;
            temp = temp2;
            temp2 = temp2->child;
        }
    }
    while(temp1){
        temp->child = temp1;
        temp = temp1;
        temp1 = temp1->child;
    }
    while(temp2){
        temp->child = temp2;
        temp = temp2;
        temp2 = temp2->child;
    }
    return dummyNode->child;
}
Node* problem21_2(Node* head){ // O(N)
    if(head == nullptr || head->next == nullptr) return head;
    Node* mergedHead = problem21_2(head->next);
    return merge2Lists(mergedHead, head);
}

vector<Node*> listOfHeads(Node* head1, Node* head2, Node* head3, Node* head4, Node* head5){
    vector<Node*> ls;
    ls.push_back(head1);
    ls.push_back(head2);
    ls.push_back(head3);
    ls.push_back(head4);
    ls.push_back(head5);
    return ls;
}
// Approach-> brut, Merge K Sorted Lists, tc-> O(2X) + O(X logX) & sc-> O(2X)
Node* problem22_1(vector<Node*> &lists){
    vector<int> res;
    for(int i=0; i<lists.size(); i++){           // O(K × N) i.e. O(X) where, K-> no. of lists
        Node* temp = lists[i];                                      // and, N-> size of each lists
        while(temp != nullptr){
            res.push_back(temp->data);
            temp = temp->child;
        }
    }
    sort(res.begin(), res.end());                // O(X logX) 
    Node* head = convertArr2LL(res);             // O(X)
    return head;
}

// Approach-> betr, Merge K Sorted Lists, tc-> O(N∧3) & sc-> O(1)
Node* problem22_2(vector<Node*> &lists){
    Node* head = lists[0];
    for(int i=1; i<lists.size(); i++){
        head = merge2Lists(head, lists[i]);
    }
    return head;
}

// Approach-> opti, Merge K Sorted Lists, tc-> O(N∧2) & sc-> O(k)
Node* problem22_3(vector<Node*> &lists){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    for(int i=0; i<lists.size(); i++){
        if(lists[i]) pq.push({lists[i]->data, lists[i]});
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->child) pq.push({it.second->child->data, it.second->child});
        temp->child = it.second;
        temp = it.second;
    }
return dummyNode->child;
}



int main(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++) cin>>arr1[i];

    int n2;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++) cin>>arr2[i];

    int n3;
    cin>>n3;
    vector<int> arr3(n3);
    for(int i = 0; i < n3; i++) cin>>arr3[i];

    int n4;
    cin>>n4;
    vector<int> arr4(n4);
    for(int i = 0; i < n4; i++) cin>>arr4[i];

    int n5;
    cin>>n5;
    vector<int> arr5(n5);
    for(int i = 0; i < n5; i++) cin>>arr5[i];
    
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* head3 = convertArr2LL(arr3);
    Node* head4 = convertArr2LL(arr4);
    Node* head5 = convertArr2LL(arr5);

    // Node* head = convertLL2branchLL(head1, head2, head3, head4, head5);

    // cout<<"Branched Linked List:"<<"\n";
    // vector<vector<int>> res = traversalBranchLL(head);
    // for(int i=0; i<res.size(); i++){
    //     for(int j=0; j<res[i].size(); j++){
    //         cout<<res[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"Flattened Linked List:"<<"\n";
    // // head = problem21_1(head);
    // head = problem21_2(head);

    vector<Node*> lists = listOfHeads(head1, head2, head3, head4, head5);
    // Node* head = problem22_1(lists);
    // Node* head = problem22_2(lists);
    Node* head = problem22_3(lists);

    vector<int> res1 = traversal_LL(head);
    for(int i=0; i<res1.size(); i++) cout<<res1[i]<<" ";

    return 0;
}