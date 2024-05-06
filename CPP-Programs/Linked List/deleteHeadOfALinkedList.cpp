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
// function to convert array to linked list
Node* convertArrToLL(vector<int> &arr) {
    Node* head = new Node(arr[0]); // create a new node with first element of array
    Node* mover = head; // create a mover pointer to move through the linked list
    for(int i=1; i<arr.size(); i++) { // iterate through the array
        Node* temp = new Node(arr[i]); // create a new node with array element
        mover->next = temp; // link the new node to the linked list
        mover = temp; // update mover
    }
    return head; // return head of linked list
}
void print(Node* head) { // function to print linked list
    while(head != NULL) { // iterate through the linked list
        cout<<head->data<<" "; // print the data
        head = head->next; // update head
    }
}
Node* deleteHead(Node* head) { // function to delete head of linked list
    Node* temp = head;  // create a temp pointer to store head
    head = head->next; // update head
    free(temp); // free the memory
    return head; // return head
}
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArrToLL(arr); // convert array to linked list
    head = deleteHead(head); // delete head of linked list
    print(head); // print linked list
    return 0; 
}