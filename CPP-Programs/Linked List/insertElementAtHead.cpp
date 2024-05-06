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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node* insertHead(Node* head, int val) {
    Node* temp =  new Node(val); // create a new node with value val
    temp->next = head; // make the next of temp to head
    return temp; // return the new head
}
int main() {
    vector<int> arr = {5, 2, 3, 1, 8};
    Node* head = convertArr2LL(arr);
    head = insertHead(head, 4);
    print(head);
    return 0;
}