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
// Function to find the k-th node in the linked list
Node* findNthNode(Node* temp, int k) {
    int cnt = 1;  // Initialize a counter starting from 1
    while(temp != NULL) {  // Traverse the linked list
        if(cnt == k) return temp;  // If counter matches k, return the current node
        cnt++;  // Increment the counter
        temp = temp->next;  // Move to the next node
    }
    return temp;  // Return the node (or NULL if the end is reached without finding the k-th node)
}

// Function to rotate the linked list to the right by k places
Node *rotate(Node *head, int k) {
    // If the list is empty or no rotation is needed, return the head as it is
    if(head == NULL || k == 0) return head;

    // Calculate the length of the linked list
    int len = 1;  // Start with length 1 since we are at the head node
    Node* tail = head;  // Start from the head node
    while(tail->next != NULL) {  // Traverse the list to find the last node
        len++;
        tail = tail->next;  // Move to the next node
    }

    // If k is a multiple of the length of the list, the list remains unchanged
    if(k % len == 0) return head;

    // Adjust k to ensure it's within the range of the list length
    k = k % len;

    // Connect the last node to the head to make it a circular linked list
    tail->next = head;

    // Find the new last node, which is (len - k)th node from the beginning
    Node* newLastNode = findNthNode(head, len - k);

    // The new head is the next node of the new last node
    head = newLastNode->next;

    // Break the circular link to finalize the rotation
    newLastNode->next = NULL;

    // Return the new head of the rotated list
    return head;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
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
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);
    print(head);
    head = rotate(head, 2);
    print(head);
    return 0;
}
// Time Complexity: O(N)