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
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
// // Brute force approach below
// Node* reverseLL(Node* head) {
//     Node* temp = head;
//     Node* prev = NULL;
//     while(temp != NULL) {
//         Node* front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }
// Node* add1ToLL(Node* head) {
//     // Reverse the linked list to start processing from the least significant digit
//     head = reverseLL(head);
//     // Initialize temporary pointer to traverse the linked list
//     Node* temp = head;
//     // Initialize carry to 1 since we are adding 1 to the linked list
//     int carry = 1;
//     // Traverse the linked list
//     while(temp != NULL) {
//         // Add carry to the current node's data
//         temp->data += carry;
//         // If the data of the current node is less than 10, break the loop as there's no need for further carry
//         if(temp->data < 10) {
//             carry = 0;
//             break;
//         } else {
//             // If the data of the current node is 10 or greater, set it to 0 and update carry to 1
//             temp->data = 0;
//             carry = 1;
//         }
//         // Move to the next node in the linked list
//         temp = temp->next;
//     }
//     // If there's still a carry after traversing the entire list, add a new node with data 1 at the end
//     if(carry == 1) {
//         Node* newNode = new Node(1);
//         // Reverse the linked list again to make the newly created node the head
//         head = reverseLL(head);
//         // Connect the new node to the head of the reversed linked list
//         newNode->next = head;
//         // Return the new head of the linked list
//         return newNode;
//     }
//     // Reverse the linked list again to restore its original order
//     head = reverseLL(head);
//     // Return the head of the modified linked list
//     return head;
// }
// Optimal Approach using recursion
// Helper function to recursively add 1 to the linked list
int addHelper(Node* temp) {
    // Base case: if we reach the end of the list, return 1 (carry)
    if(temp == NULL) {
        return 1;
    }
    // Recursively call addHelper for the next node
    int carry = addHelper(temp->next);
    // Add the carry to the current node's data
    temp->data = temp->data + carry;
    // If the sum is less than 10, no carry is needed
    if(temp->data < 10) {
        return 0;
    }
    // If the sum is 10 or more, set current node's data to 0 and return carry 1
    temp->data = 0;
    return 1;
}
// Function to add 1 to a number represented by a linked list
Node* add1ToLL(Node* head) {
    // Call the helper function to add 1 starting from the head of the list
    int carry = addHelper(head);
    // If there is a carry left after the entire addition,
    // it means we need to add a new node at the beginning of the list
    if(carry == 1) {
        // Create a new node with data 1
        Node* newNode = new Node(1);
        // Set the new node's next to the current head
        newNode->next = head;
        // The new node becomes the new head of the list
        return newNode;
    }
    // If there is no carry, return the original head
    return head;
}
int main() {
    vector<int> arr = {1, 5, 9};
    Node* head = convertArr2LL(arr);
    cout<<"Before adding 1 Linked List is : "<<endl;
    print(head);
    cout<<"After adding 1 Linked List is : "<<endl;
    head = add1ToLL(head);
    print(head);
    return 0;
}