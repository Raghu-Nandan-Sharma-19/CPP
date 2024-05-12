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
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// Function to reverse a linked list recursively
Node* reverseLL(Node* head) {
    // Check if the current node is NULL or if it is the last node in the list
    if(head == NULL || head->next == NULL) {
        // If so, return the current node as it's either NULL or the last node in the list
        return head;
    }
    // Recursive call to reverse the rest of the linked list
    Node* newHead = reverseLL(head->next);
    // At this point, 'newHead' points to the head of the reversed list
    // Get the next node after the current 'head' node
    Node* front = head->next;
    // Reverse the link between 'head' and its next node
    front->next = head;
    // Set the next pointer of 'head' to NULL to make it the new tail of the list
    head->next = NULL;
    // Return the new head of the reversed list
    return newHead;
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
    head = reverseLL(head);
    cout<<"After reversing using recursion : "<<endl;
    print(head);
    return 0;
}