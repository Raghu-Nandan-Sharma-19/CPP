#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// // Function to reverse a linked list
// Node* reverseLL(Node* head) {
//     // Initialize a temporary pointer to traverse the linked list
//     Node* temp = head;
//     // Create a stack to store the data of each node in the linked list
//     stack<int> st;
//     // Traverse the linked list and push the data of each node onto the stack
//     while(temp != NULL) {
//         st.push(temp->data); // Push the data onto the stack
//         temp = temp->next;   // Move to the next node
//     }
//     // Reset the temporary pointer to the head of the linked list
//     temp = head;
//     // Traverse the linked list again and pop the data from the stack to reverse the list
//     while(temp != NULL) {
//         temp->data = st.top(); // Update the data of the current node with the top element of the stack
//         st.pop();              // Pop the top element from the stack
//         temp = temp->next;     // Move to the next node
//     }
//     // Return the head of the reversed linked list
//     return head;
// }
// Function to reverse a singly linked list
Node* reverseLL(Node* head) {
    // Initialize two pointers: temp to iterate through the list,
    // and prev to keep track of the reversed part of the list
    Node* temp = head;
    Node* prev = NULL;
    // Traverse the list until the end (temp reaches NULL)
    while(temp != NULL) {
        // Store the next node of the current node in front
        Node* front = temp->next;
        // Reverse the pointer of the current node to point to the previous node
        temp->next = prev;
        // Move prev to current node and temp to the next node (front)
        prev = temp;
        temp = front;
    }
    // Return the new head of the reversed list (which is the last node of the original list)
    return prev;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {1, 3, 2, 5};
    Node* head = convertArr2DLL(arr);
    cout<<"Before reversing : "<<endl;
    print(head);
    cout<<endl;
    cout<<"After reversing : "<<endl;
    head = reverseLL(head);
    print(head);
    return 0;
}