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

// Add two numbers in linked list, tc-> O(max(n1, n2)) & sc-> O(max(n1, n2))
Node* problem2(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;
    while(temp1 != nullptr || temp2 != nullptr){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = newNode;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

// Approach-> brut, Seggregate odd/even nodes of a linked list, tc-> O(2N) & sc-> O(N)
Node* problem3_1(Node* head){
    vector<int> list;
    Node* temp = head;
    if(head == NULL || head->next == nullptr) return head;

    // collecting odd nodes data
    while(temp != nullptr && temp->next != nullptr){  // O(N/2)
        list.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) list.push_back(temp->data);

    // collecting even nodes data
    temp = head->next;
    while(temp != nullptr && temp->next != nullptr){  // O(N/2)
        list.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) list.push_back(temp->data);

    // seggregation of both
    int i = 0;
    temp = head;
    while(temp != nullptr){  // O(N)
        temp->data = list[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// Approach-> opti, Seggregate odd/even nodes of a linked list, tc-> O(N) & sc-> O(1)
Node* problem3_2(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    if(head == NULL || head->next == nullptr) return head;
    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// Approach-> brut, Sort a linked list of 0's, 1's and 2's, tc-> O(2N) & sc-> O(1)
Node* problem4_1(Node* head){
    if(head == nullptr) return head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;
    // Counting no. of 0's, 1's and 2's
    while(temp != nullptr){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    // Data replacement(sorting)
    temp = head;
    while(temp != nullptr){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

// Approach-> opti, Sort a linked list of 0's, 1's and 2's, tc-> O(N) & sc-> O(1)
Node* problem4_2(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* temp = head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    // Seggregation of 0's, 1's and 2's(link change)
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    // link change
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = nullptr;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

// Approach-> brut, Remove nth node from the back of the linked list, tc-> O(len) + O(len - n) & sc-> O(1), if n = 1 then tc at worst case is O(2*len)
Node* problem5_1(Node* head, int n){
    if(head == nullptr) return head;

    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }

    if(cnt == n){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    int res = cnt - n;
    temp = head;
    while(temp != nullptr){
        res--;
        if(res == 0) break;
        temp = temp->next;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

// Approach-> opti, Remove nth node from the back of the linked list, tc-> O(N) & sc-> O(1)
Node* problem5_2(Node* head, int n){
    if(head == nullptr) return head;
    Node* fast = head;
    Node* slow = head;

    for(int i=0; i<n; i++) fast = fast->next;

    if(fast == nullptr){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}

// Approach-> brut, reverse a linked list(iterative), tc-> O(2N) & sc-> O(N)
Node* problem6_1_1(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    stack<int> st;
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

// Approach-> opti, reverse a linked list(iterative), tc-> O(N) & sc-> O(1)
Node* problem6_1_2(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;
    while(temp != nullptr){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Approach-> recursive, reverse a linked list, tc-> O(N) & sc-> O(N)
Node* problem6_2(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* newHead = problem6_2(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// Approach-> brut, Find the middle of a linked list, tc-> O(N + N/2) & sc-> O(1)
Node* problem7_1(Node* head){ 
    if(head == nullptr) return head;
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    int mid = (cnt/2)+1;
    temp = head;
    while(temp != nullptr){
        mid--;
        if (mid == 0) break;
        temp = temp->next;
    }
    return temp;
}

// Approach-> opti(Hare & Tortrise Method), Find the middle of a linked list, tc-> O(N) & sc-> O(1)
Node* problem7_2(Node* head){
    if(head == nullptr) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Approach-> brut, Check if a linked list is palindrome or not, tc-> O(2N) & sc-> O(N)
bool problem8_1(Node* head){
    if(head == nullptr || head->next == nullptr) return true;
    Node* temp = head;
    stack<int> st;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

// Approach-> opti, Check if a linked list is palindrome or not, tc-> O(2N) & sc-> O(1)
bool problem8_2(Node* head){
    if(head == nullptr || head->next == nullptr) return true;
    // finding middle
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse from middle
    Node* revNewHead = problem6_1_2(slow->next); 

    // comparing
    Node* first = head;
    Node* second = revNewHead;
    while(second != nullptr){
        if(first->data != second->data){
            problem6_1_2(revNewHead);
            return false;
        }
        second = second->next;
        first = first->next;
    }

    // Reversing again to get back original linked list
    problem6_1_2(revNewHead);
    return true; 
}

// Approach-> brut, Add 1 to a number represented by a linked list, tc-> O(3N) & sc-> O(1)
Node* problem9_1(Node* head){
    if(head == nullptr) return head;
    Node* newHead = problem6_1_2(head);
    int sum = 1;
    int carry = 1;
    Node* temp = newHead;
    while(temp != nullptr){
        sum = carry;
        sum+= temp->data;
        temp->data = sum%10;
        carry = sum/10;
        if(temp->next == nullptr && carry == 1){
            Node* carryNode = new Node(carry);
            temp->next = carryNode;
            break;
        }
        temp = temp->next;
    }
    newHead = problem6_1_2(newHead);
    return newHead;
}

// Approach-> opti, Add 1 to a number represented by a linked list, tc-> O(N) & sc-> O(N)
int helper(Node* temp){
    if(temp == nullptr) return 1;
    int carry = helper(temp->next);
    int sum = temp->data + carry;
    temp->data = sum%10;
    carry = sum/10;
    return carry;
}
Node* problem9_2(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newHead = new Node(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}

// Approach-> brut, Find the intersection point of Y linked list(hashing), tc-> O(log N1) + O(log N2) & sc-> O(N1)
void yLinkedList(Node* head1, Node* head2){
    Node* temp = head1;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head2->next->next;
}
Node* problem10_1(Node* head1, Node* head2){
    Node* temp = head1;
    map<Node*, int> mpp;
    while(temp != nullptr){
        mpp[temp] = 0;
        temp = temp->next;
    }
    temp = head2;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return temp; 
        temp = temp->next;
    }
    return NULL;
}

// Approach-> betr, Find the intersection point of Y linked list, tc-> O(N1 + 2×N2) 0r O(2×N1 + N2) & sc-> O(1)
Node* collisionPoint(Node* temp1, Node* temp2, int d){
    while(d){                     // O(d) i.e. N2-N1 or N1-N2
        d--;
        temp2 = temp2->next;
    }
    while(temp1 != temp2){        // O(min(N1, N2))
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}
Node* problem10_2(Node* head1, Node* head2){
    Node* temp1 = head1;
    int cnt1 = 0;
    while(temp1 != nullptr){         // O(N1)
        cnt1++;
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    int cnt2 = 0;
    while(temp2 != nullptr){         // O(N2)
        cnt2++;
        temp2 = temp2->next;
    }
    if(cnt1 < cnt2) return collisionPoint(head1, head2, cnt2 - cnt1);
    else collisionPoint(head2, head1, cnt1 - cnt2);
}

// Approach-> opti, Find the intersection point of Y linked list, tc-> O(N1 + N2) & sc-> O(1)
Node* problem10_3(Node* head1, Node* head2){
    if(head1 == nullptr || head2 ==  nullptr) return nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){    
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return temp1;
}

// Approach-> brut, Detect a loop or cycle in linked list(hashing), tc-> O(N × 2log N) & sc-> O(N)
void circularLL(Node* head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp =temp->next;
    }
    temp->next = head->next;
}
bool problem11_1(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// Approach-> opti, Detect a loop or cycle in linked list(Hare & Tortrise Method), tc-> O(N) & sc-> O(1)
bool problem11_2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Approach-> brut, Find the length of the loop or cycle in linked list(hashing), tc-> O(N × 2log N) & sc-> O(N)
int problem12_1(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

// Approach-> opti, Find the length of the loop or cycle in linked list(Hare & Tortrise Method), tc-> O(2N) & sc-> O(1)
int fastLength(Node* slow, Node* fast){
    int cnt = 1; 
    fast = fast->next;
    while(slow != fast){
        fast = fast->next;
        cnt++;
    }
    return cnt;
}
int problem12_2(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt = 0;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return fastLength(slow, fast);
    }
    return 0;
}

// Approach-> brut, Find the starting point of the loop or cycle in linked list(hashing), tc-> O(N × 2log N) & sc-> O(N)
Node* problem13_1(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

// Approach-> opti, Find the starting point of the loop or cycle in linked list(Hare & Tortrise Method), tc-> O(N + L1) & sc-> O(1)
// where L1 is the distance from the head to the point where loop/cycle in the linked list begins.
Node* problem13_2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

// Approach-> opti, Delete the middle node of the linked list(Hare & Tortrise Method), tc-> O(N/2) & sc-> O(1)
Node* problem14(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

// Approach-> opti, Reverse Nodes in K Group Size of LinkedList, tc-> O(N/2) & sc-> O(1)
Node* problem18(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        
        temp = temp->next;
    }
    return head;
}








int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    // int n2;
    // cin>>n2;
    // vector<int> arr2(n2);
    // for(int i=0; i<n2; i++) cin>>arr2[i];

    // Node* head1 = convertArr2LL(arr);
    // Node* head2 = convertArr2LL(arr2);
    // Node* head = problem2(head1, head2);

    Node* head = convertArr2LL(arr);
    // head = problem3_1(head);
    // head = problem3_2(head);
    // head = problem4_1(head);
    // head = problem4_2(head);
    // int N; cin>>N;
    // head = problem5_1(head, N);
    // head = problem5_2(head, N);
    // head = problem6_1_1(head);
    // head = problem6_1_2(head);
    // head = problem6_2(head);
    // cout<<problem7_1(head)->data<<endl;
    // cout<<problem7_2(head)->data<<endl;
    // cout<<problem8_1(head)<<endl;
    // cout<<problem8_2(head)<<endl;
    // head = problem9_1(head);
    // head = problem9_2(head);
    // yLinkedList(head1, head2);
    // Node* head = problem10_1(head1, head2);
    // Node* head = problem10_2(head1, head2);
    // Node* head = problem10_3(head1, head2);
    // circularLL(head);
    // cout<<problem11_1(head);
    // cout<<problem11_2(head);
    // cout<<problem12_1(head);
    // cout<<problem12_2(head);
    // cout<<problem13_1(head)->data;
    // cout<<problem13_2(head)->data;
    head = problem14(head);
    
    vector<int> res1 = traversal_LL(head);
    for(int i=0; i<res1.size(); i++) cout<<res1[i]<<"\t";
    return 0;
}