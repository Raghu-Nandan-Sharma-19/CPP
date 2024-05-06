#include<bits/stdc++.h>
using namespace std;
class Node{
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
void print(Node* head) { // function to print linked list
    while(head != NULL) { // iterate through the linked list
        cout<<head->data<<" "; // print the data
        head = head->next; // update head
    }
}
Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL; // if linked list is empty or has only one element return NULL
    Node* temp = head; // initialize temp
    while(temp->next->next != NULL) { // iterate till second last element
        temp = temp->next; // update temp
    }
    free(temp->next); // free the last element
    temp->next = nullptr; // set next of second last element to NULL
    return head; // return head
}
int main() {
    vector<int> arr = {12, 5, 7, 8};
    Node* head = convertArr2LL(arr);
    head = deleteTail(head);
    print(head);
    return 0;
}