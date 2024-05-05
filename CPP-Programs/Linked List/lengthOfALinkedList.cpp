#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthOfLL(Node* head) {
    int cnt = 0; // initialize count
    Node* temp = head; // initialize temp
    while(temp) { // iterate through the linked list
        temp = temp->next; // update temp
        cnt++; // increment count
    }
    return cnt; // return count
}
int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    // Node* temp = head;
    // cout<<"The linked list is : "<<endl;
    // while(temp) {
    //     cout<<temp->data<<" ";
    //     temp->next;
    // }
    cout<<"Length of linked list is : "<<lengthOfLL(head)<<endl;;
    return 0;
}