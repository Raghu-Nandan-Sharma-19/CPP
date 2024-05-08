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
// Function to delete the tail node of a doubly linked list
Node* deleteTail(Node* head) {
    // Check if the list is empty or has only one node
    if(head == NULL || head->next == NULL) {
        return NULL; // Return NULL indicating empty list or list with one node
    }
    
    // Create a pointer 'tail' and set it to the head of the list
    Node* tail = head;
    
    // Traverse the list until the 'tail' node points to NULL (reaches the end of the list)
    while(tail->next != NULL) {
        tail = tail->next;
    }
    
    // Once the loop exits, 'tail' points to the last node in the list
    
    // Create a pointer 'newTail' and set it to the node before the current tail
    Node* newTail = tail->back;
    
    // Set the next pointer of 'newTail' to NULL, indicating it's now the new tail
    newTail->next = nullptr;
    
    // Set the back pointer of the current tail to NULL, disconnecting it from the list
    tail->back = nullptr;
    
    // Delete the current tail node to free up memory
    delete tail;
    
    // Return the head of the list
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
    head = deleteTail(head);
    print(head);
    return 0;
}