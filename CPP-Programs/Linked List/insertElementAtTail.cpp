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
Node* insertTail(Node* head, int val) {
    if(head == NULL) { // if linked list is empty
        return new Node(val); // create a new node with value val
    }
    Node* temp = head; // store the head in temp
    while(temp->next != NULL) { // iterate through the linked list
        temp = temp->next; // move temp to next element
    } 
    Node* newNode = new Node(val); // create a new node with value val
    temp->next = newNode; // make the next of temp to newNode
    return head; // return the head
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {2, 3, 1, 8};
    Node* head = convertArr2LL(arr);
    head = insertTail(head, 100);
    print(head);
    return 0;
}