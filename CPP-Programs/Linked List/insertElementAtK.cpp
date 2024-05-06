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
// Function to insert a node with value 'element' at position 'k' in a linked list
Node* insertK(Node* head, int element, int k) {
    // If the list is empty
    if(head == NULL) { 
        // If the position to insert is the first position
        if(k == 1) { 
            // Create a new node with 'element' and return it as the new head
            return new Node(element); 
        } else {
            // If the position is not the first and the list is empty, return NULL
            return head;
        }
    }
    
    // If the position to insert is the first position
    if(k == 1) { 
        // Create a new node with 'element'
        Node* newNode = new Node(element); 
        // Set the new node's next pointer to the current head
        newNode->next = head; 
        // Return the new node as the new head
        return newNode; 
    }
    
    // Counter to track the position while traversing the list
    int cnt = 0; 
    // Temporary pointer to traverse the list
    Node* temp = head;
    
    // Traverse the list
    while(temp != NULL) { 
        // Increment the counter
        cnt++; 
        // If the next position is the one before the target position 'k'
        if(cnt == (k-1)) { 
            // Create a new node with 'element'
            Node* x = new Node(element); 
            // Set the new node's next pointer to the next node after the current position
            x->next = temp->next;
            // Set the current position's next pointer to the new node
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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {3, 1, 5, 8};
    Node* head = convertArr2LL(arr);
    head = insertK(head, 100, 1);
    print(head);
    return 0;
}