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
// Function to insert a new node with the given value before the current head node in a doubly linked list
Node* insertBeforeHead(Node* head, int val) {
    // Create a new node with the given value, setting its next pointer to 
    // the current head and its previous pointer to nullptr
    Node* newHead = new Node(val, head, nullptr);
    // Update the previous pointer of the current head to point to the new head
    head->back = newHead;
    // Return the new head, effectively making the newly created node the new head of the list
    return newHead;
}
// Function to insert a new node with the given value before the current tail node in a doubly linked list
Node* insertBeforeTail(Node* head, int val) {
    // Check if the list is empty (only the head node exists)
    if(head->next == NULL) {
        // If the list is empty, insert the new node before the head
        return insertBeforeHead(head, val);
    }
    // Initialize a pointer to traverse the list and find the current tail node
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    // Once the tail node is found, store a pointer to its previous node
    Node* prev = tail->back;
    // Create a new node with the given value, setting its next pointer to the tail
    // and its previous pointer to the previous node of the current tail
    Node* newNode = new Node(val, tail, prev);
    // Update the next pointer of the previous node of the tail to point to the new node
    prev->next = newNode;
    // Update the previous pointer of the tail to point to the new node
    tail->back = newNode;
    // Return the head of the list (unchanged)
    return head;
}
// Function to insert a new node with the given value before the kth node in a doubly linked list
Node* insertBeforeKthNode(Node* head, int k, int val) {
    // If k is 1, insert the new node before the head
    if(k == 1) {
        return insertBeforeHead(head, val);
    }
    // Initialize a pointer to traverse the list and find the kth node
    Node* temp = head;
    int cnt = 0; // Counter to keep track of the current node index
    while(temp != NULL) {
        cnt++;
        if(cnt == k) break; // Break the loop when kth node is found
        temp = temp->next;
    } 
    // Store a pointer to the previous node of the kth node
    Node* prev = temp->back;
    // Create a new node with the given value, setting its next pointer to the kth node
    // and its previous pointer to the previous node of the kth node
    Node* newNode = new Node(val, temp, prev);
    // Update the next pointer of the previous node of the kth node to point to the new node
    prev->next = newNode;
    // Update the previous pointer of the kth node to point to the new node
    temp->back = newNode;
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
    head = insertBeforeKthNode(head, 2, 10);
    print(head);
    return 0;
}