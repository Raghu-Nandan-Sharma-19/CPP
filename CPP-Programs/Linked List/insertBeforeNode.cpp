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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
// Function to insert a new node with value 'val' before the given 'node' in a doubly linked list
void insertBeforeNode(Node* node, int val) {
    // Store the reference to the previous node
    Node* prev = node->back;
    // Create a new node with the given value 'val'
    Node* newNode = new Node(val, node, prev);
    // Update the 'next' pointer of the previous node to point to the new node
    prev->next = newNode;
    // Update the 'back' pointer of the given 'node' to point to the new node
    node->back = newNode;
}
int main() {
    vector<int> arr = {2, 3, 4, 1};
    Node* head = convertArr2DLL(arr);
    insertBeforeNode(head->next, 100);
    print(head);
    return 0;
}