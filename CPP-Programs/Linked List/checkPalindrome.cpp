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
// // brute force approach
// // Function to check if a linked list is a palindrome
// bool isPalindrome(Node* head) {
//     // Creating a stack to store the elements of the linked list
//     stack<int> st;
//     // Pointer to traverse the linked list
//     Node* temp = head;
//     // Pushing all elements of the linked list onto the stack
//     while(temp != NULL) {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     // Resetting the pointer to the head of the linked list
//     temp = head;
//     // Traversing the linked list again
//     while(temp != NULL) {
//         // Comparing the data of the current node with the top element of the stack
//         if(temp->data != st.top()) 
//             // If the data doesn't match, the linked list is not a palindrome, return false
//             return false;
        
//         // Moving to the next node in the linked list
//         temp = temp->next;
//         // Removing the top element from the stack as it has been matched with a node
//         st.pop();
//     }
//     // If all elements match (i.e., the linked list is a palindrome), return true
//     return true;
// }
// optimal solution below
Node* reverseLL(Node* head) {
    // Initialize two pointers: temp to iterate through the list,
    // and prev to keep track of the reversed part of the list
    Node* temp = head;
    Node* prev = NULL;
    // Traverse the list until the end (temp reaches NULL)
    while(temp != NULL) {
        // Store the next node of the current node in front
        Node* front = temp->next;
        // Reverse the pointer of the current node to point to the previous node
        temp->next = prev;
        // Move prev to current node and temp to the next node (front)
        prev = temp;
        temp = front;
    }
    // Return the new head of the reversed list (which is the last node of the original list)
    return prev;
}
bool isPalindrome(Node *head) {
    // Initialize two pointers slow and fast to traverse the linked list
    Node* slow = head; // Points to the middle or middle-left node
    Node* fast = head; // Points to the end of the list
    // Move the fast pointer to the end and slow pointer to the middle
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next; // Move slow one step forward
        fast = fast->next->next; // Move fast two steps forward
    }
    // Reverse the second half of the linked list starting from slow->next
    Node* newHead = reverseLL(slow->next); // reverseLL() function reverses the linked list and returns the new head
    // Pointers to traverse the first half (head) and second half (newHead) of the linked list
    Node* first = head;
    Node* second = newHead;
    // Compare elements of first and second halves of the linked list
    while(second != NULL) {
        // If the data of corresponding nodes in the first and second halves are not equal, it's not a palindrome
        if(first->data != second->data) {
            // Since it's not a palindrome, reverse the second half back to its original state
            reverseLL(newHead); // Restore the original order of the second half
            return false; // Return false, indicating it's not a palindrome
        }
        first = first->next; // Move first pointer forward
        second = second->next; // Move second pointer forward
    }
    // If all elements are compared and found to be equal, it's a palindrome
    // So, reverse the second half back to its original state and return true
    reverseLL(newHead); // Restore the original order of the second half
    return true; // Return true, indicating it's a palindrome
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
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
int main() {
    vector<int> arr = {1, 2, 3, 2, 1};
    Node* head = convertArr2DLL(arr);
    cout<<"Linked list is : "<<endl;
    print(head);
    if(isPalindrome(head)) {
        cout<<"The linked list is palindrome"<<endl;
    } else {
        cout<<"The linked list is not palindrome"<<endl;
    }
    return 0;
}