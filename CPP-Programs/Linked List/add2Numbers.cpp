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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
// Function to add two numbers represented by two linked lists
Node* add2Numbers(Node* head1, Node* head2) {
    Node* t1 = head1;         // Pointer to traverse the first list
    Node* t2 = head2;         // Pointer to traverse the second list
    Node* dummyNode = new Node(-1); // Dummy node to act as the starting point of the result list
    Node* curr = dummyNode;   // Pointer to build the result list
    int carry = 0;            // Variable to store carry during addition
    // Traverse both lists until both are exhausted
    while(t1 != NULL || t2 != NULL) {
        int sum = carry;      // Start with the carry from the previous addition
        // Add the data from the current node of the first list (if it exists)
        if(t1) sum = sum + t1->data;
        // Add the data from the current node of the second list (if it exists)
        if(t2) sum = sum + t2->data;
        // Create a new node with the digit value of the sum (sum % 10)
        Node* newNode = new Node(sum %  10);
        // Calculate the new carry (sum / 10)
        carry = sum / 10;
        // Append the new node to the result list
        curr->next = newNode;
        // Move the current pointer to the new node
        curr = curr->next;
        // Move to the next node in the first list (if it exists)
        if(t1) t1 = t1->next;
        // Move to the next node in the second list (if it exists)
        if(t2) t2 = t2->next;
    }
    // If there is a carry left after the final addition, create a new node for it
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    // Return the next node of the dummy node, which is the head of the result list
    return dummyNode->next;
}
int main() {
    vector<int> arr1 = {2, 4, 6};
    Node* head1 = convertArr2LL(arr1);
    vector<int> arr2 = {3, 8, 7};
    Node* head2 = convertArr2LL(arr2);
    cout<<"Before adding : "<<endl;
    cout<<"List 1 : "<<endl;
    print(head1);
    cout<<"List 2 : "<<endl;
    print(head2);
    cout<<"After adding List is : "<<endl;
    Node* head = add2Numbers(head1, head2);
    print(head);
    return 0;
}