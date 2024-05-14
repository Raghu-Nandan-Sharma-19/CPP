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
Node* deleteMiddle(Node* head) {
    // Check if the list is empty or contains only one node
    if(head == NULL || head->next == NULL) {
        return NULL; // There's no middle to delete, return NULL
    }
    // Initialize two pointers: slow and fast
    Node* slow = head; // Slow pointer initially points to the head
    Node* fast = head; // Fast pointer initially points to the head
    // Move fast pointer two nodes ahead initially
    fast = head->next->next;
    // Move both pointers until the fast pointer reaches the end of the list
    // or the node just before the end of the list
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next; // Move slow pointer one node forward
        fast = fast->next->next; // Move fast pointer two nodes forward
    }
    // Now, slow pointer is pointing to the node just before the middle node
    // Save the middle node to be deleted
    Node* middle = slow->next;
    // Delete the middle node by adjusting pointers
    slow->next = slow->next->next;
    // Free the memory allocated to the middle node
    delete middle;
    // Return the head of the modified linked list
    return head;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);
    cout<<"Before deleting middle : "<<endl;
    print(head);
    cout<<"After deleting middle : "<<endl;
    head = deleteMiddle(head);
    print(head);
    return 0;
}