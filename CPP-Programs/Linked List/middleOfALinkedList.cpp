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
Node* convertArr2LL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// // brute force approach --> O(N + N/2)
// // Define a function to find the middle node of a linked list
// Node* middleNode(Node* head) {
//     // Initialize a temporary pointer to traverse the list, starting from the head
//     Node* temp = head;
//     // Initialize a counter to count the number of nodes in the list
//     int cnt = 0;
//     // Count the number of nodes in the list by traversing it
//     while(temp != NULL) {
//         cnt++;
//         temp = temp->next;
//     }
//     // Reset the temporary pointer to the head of the list
//     temp = head;
//     // Calculate the index of the middle node
//     int midNode = (cnt/2) + 1;
//     // Traverse the list again to find the middle node
//     while(temp != NULL) {
//         midNode = midNode - 1;
//         // If the index reaches 0, it means we've reached the middle node
//         if(midNode == 0) break;
//         // Move the temporary pointer to the next node
//         temp = temp->next;
//     }
//     // Return the pointer to the middle node
//     return temp;
// }
// Optimal approach --> using tortoise and hare method TC --> O(N) 
// Function to find the middle node of a linked list
Node* middleNode(Node* head) {
    // Initialize two pointers, 'slow' and 'fast', both pointing to the head of the list
    Node* slow = head;  // 'slow' moves one step at a time
    Node* fast = head;  // 'fast' moves two steps at a time
    // Loop until 'fast' pointer reaches the end of the list or the second last node
    while(fast != NULL && fast->next != NULL) {
        // Move 'slow' pointer one step forward
        slow = slow->next;
        // Move 'fast' pointer two steps forward
        fast = fast->next->next;
    }
    // At this point, 'slow' points to the middle node of the list
    // if the number of nodes is odd, or to the first middle node if the number of nodes is even
    return slow;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    cout<<"The linked list is : "<<endl;
    print(head);
    cout<<endl;
    Node* ansNode = middleNode(head);
    cout<<"The middle node value is : "<<ansNode->data<<endl;
    return 0;
}