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
        Node* temp = new Node(arr[i], nullptr, prev);
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
Node* removeKthElement(Node* head, int k) {
    // Check if the list is empty
    if(head == NULL) {
        return NULL;
    }
    int cnt = 0; // Counter to track position in the list
    Node* kNode = head; // Pointer to the kth node
    // Traverse the list until kth node is found or end of list
    while(kNode != NULL) {
        cnt++;
        if(cnt == k) break; // If kth node is found, exit loop
        kNode = kNode->next; // Move to the next node
    }
    Node* prev = kNode->back; // Pointer to the node before the kth node
    Node* front = kNode->next; // Pointer to the node after the kth node
    
    // Check if kth node is the only node in the list
    if(prev == NULL && front == NULL) {
        return NULL;
    } 
    // Check if kth node is the head of the list
    else if(prev == NULL) {
        return deleteHead(head); // Call function to delete head
    } 
    // Check if kth node is the tail of the list
    else if(front == NULL) {
        return deleteTail(head); // Call function to delete tail
    }
    // Update pointers to remove kth node from the list
    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode; // Free memory allocated to kth node
    return head; // Return updated head of the list
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
    head = removeKthElement(head, 2);
    print(head);
    return 0;
}