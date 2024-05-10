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
// Define a function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Initialize a pointer to store the last node (which will be the new head after reversal)
    Node* last = NULL;
    // Initialize a pointer to traverse the list, starting from the head
    Node* current = head;
    // Traverse the list until the current pointer reaches the end (NULL)
    while(current != NULL) {
        // Store the previous node of the current node
        last = current->back;
        // Swap the pointers of the current node to reverse its direction
        current->back = current->next;
        current->next = last;
        // Move the current pointer to the previous node (which is now the next node after reversal)
        current = current->back;
    }
    // Return the last node of the original list, which is now the new head after reversal
    return (last->back);
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {4, 2, 3, 1};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}