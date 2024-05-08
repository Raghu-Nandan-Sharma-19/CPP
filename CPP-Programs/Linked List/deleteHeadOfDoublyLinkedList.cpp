#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
// Function to delete the head node of a singly linked list
Node* deleteHead(Node* head) {
    // Check if the list is empty or has only one node
    if(head == NULL || head->next == NULL) {
        return NULL; // Return NULL indicating empty list or list with one node
    }
    
    // Store the reference to the current head node
    Node* prev = head;
    
    // Move the head pointer to the next node
    head = head->next;
    
    // Update the back pointer of the new head node to NULL (assuming it's a doubly linked list)
    head->back = nullptr;
    
    // Disconnect the previous head node from the list by setting its next pointer to NULL
    prev->next = nullptr;

    // Delete the previous head node to free up memory
    delete prev;
    
    // Return the new head node
    return head;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {2, 3, 4, 1};
    Node* head = convertArr2DLL(arr);
    head = deleteHead(head);
    print(head);
}