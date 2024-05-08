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
void deleteNode(Node* temp) {
    // Get the previous and next nodes of the node to be deleted
    Node* prev = temp->back;
    Node* front = temp->next;
    
    // Check if the next node is NULL, meaning the node to be deleted is the last node
    if(front == NULL) {
        // If the node to be deleted is the last node, update the previous node's next pointer to NULL
        prev->next = nullptr;
        // Update the deleted node's back pointer to NULL
        temp->back = nullptr;
        // Free the memory occupied by the node to be deleted
        free(temp);
        return;
    }
    
    // If the node to be deleted is not the last node,
    // adjust pointers of the previous and next nodes to remove the node to be deleted
    prev->next = front;
    front->back = prev;
    
    // Update the deleted node's pointers to NULL
    temp->next = temp->back = nullptr;
    
    // Free the memory occupied by the node to be deleted
    free(temp);
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
    deleteNode(head->next);
    print(head);
    return 0;
}