#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
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
    }
}
// Function to insert a node with value 'element' before the first occurrence of 'value' in a linked list
Node* insertBeforeValue(Node* head, int element, int value) {
    // If the list is empty
    if(head == NULL) { 
        // Return NULL as there's no node to insert before
        return NULL;
    }
    
    // If the value to insert before is found at the beginning of the list
    if(head->data == value) { 
        // Create a new node with 'element'
        Node* newNode = new Node(element); 
        // Set the new node's next pointer to the current head
        newNode->next = head; 
        // Return the new node as the new head
        return newNode; 
    }
    
    // Temporary pointer to traverse the list
    Node* temp = head;
    
    // Traverse the list
    while(temp != NULL) {  
        // If the next node contains the value to insert before
        if(temp->next->data == value) { 
            // Create a new node with 'element'
            Node* x = new Node(element); 
            // Set the new node's next pointer to the node containing the value
            x->next = temp->next;
            // Set the current node's next pointer to the new node
            temp->next = x;
            // Exit the loop after insertion
            break;
        }
        // Move to the next node
        temp = temp->next;
    }
    // Return the head of the list
    return head;
}
int main() {
    vector<int> arr = {3, 1, 5, 8};
    Node* head = convertArr2LL(arr);
    head = insertBeforeValue(head, 100, 8);
    print(head);
    return 0;
}