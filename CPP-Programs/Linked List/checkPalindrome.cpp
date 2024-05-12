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
// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    // Creating a stack to store the elements of the linked list
    stack<int> st;
    // Pointer to traverse the linked list
    Node* temp = head;
    // Pushing all elements of the linked list onto the stack
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }
    // Resetting the pointer to the head of the linked list
    temp = head;
    // Traversing the linked list again
    while(temp != NULL) {
        // Comparing the data of the current node with the top element of the stack
        if(temp->data != st.top()) 
            // If the data doesn't match, the linked list is not a palindrome, return false
            return false;
        
        // Moving to the next node in the linked list
        temp = temp->next;
        // Removing the top element from the stack as it has been matched with a node
        st.pop();
    }
    // If all elements match (i.e., the linked list is a palindrome), return true
    return true;
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