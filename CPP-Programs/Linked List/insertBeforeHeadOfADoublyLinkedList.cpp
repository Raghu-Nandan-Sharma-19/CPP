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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {2, 3, 4, 1};
    Node* head = convertArr2DLL(arr);
    head = insertBeforeHead(head, 10);
    print(head);
    return 0;
}