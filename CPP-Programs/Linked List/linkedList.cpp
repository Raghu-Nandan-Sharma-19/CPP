#include<bits/stdc++.h>
using namespace std;
// Node class
class Node {
    public:
    // data and next pointer
    int data;
    Node* next;
    public: 
    Node(int data1) { // constructor
        data = data1; // initialize data
        next = nullptr; // initialize next
    }
};
// function to convert array to linked list
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]); // initialize head
    Node* mover = head; // initialize mover
    for(int i=1; i<arr.size(); i++) { // iterate through the array
        Node* temp = new Node(arr[i]); // create a new node
        mover->next = temp; // set the next pointer of mover to temp
        mover = temp; // update mover
    }
    return head; // return head
}
int main() { // main function
    vector<int> arr = {2, 5, 8, 7}; // vector of integers
    Node* head = convertArr2LL(arr); // convert array to linked list
    Node* temp = head; // initialize temp
    while(temp) { // iterate through the linked list
        cout<<temp->data<<" "; // print the data
        temp = temp->next; // update temp
    }
    return 0; // return 0
}