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
// // Function to calculate the length of a linked list until the start of a cycle
// int lengthOfLL(Node* head) {
//     // Create a map to store visited nodes along with their corresponding timer values
//     map<Node*, int> nodeMap;
//     // Initialize a temporary pointer to traverse the linked list
//     Node* temp = head;
//     // Initialize a timer variable to keep track of the position of each node in the linked list
//     int timer = 1;
//     // Traverse the linked list until reaching the end
//     while(temp != NULL) {
//         // If the current node is already in the map, it indicates the presence of a cycle
//         if(nodeMap.find(temp) != nodeMap.end()) {
//             // Retrieve the timer value corresponding to the node where the cycle starts
//             int value = nodeMap[temp];
//             // Calculate the length of the cycle by subtracting the timer value from the current timer
//             return (timer - value);
//         }
//         // Add the current node to the map along with its timer value
//         nodeMap[temp] = timer;
//         // Increment the timer
//         timer++;
//         // Move to the next node in the linked list
//         temp = temp->next;
//     }
//     // If no cycle is detected, return 0 (length of the linked list)
//     return 0;
// }
// Optimal Approach 
// Function to find the length of the cycle when slow and fast pointers meet
int findLength(Node* slow, Node* fast) {
    // Initialize a counter to keep track of the length of the cycle
    int cnt = 1;
    // Move the fast pointer one step forward
    fast = fast->next;
    // Traverse the cycle until the fast pointer meets the slow pointer again
    while(fast != slow) {
        // Move the fast pointer one step forward
        fast = fast->next;
        // Increment the counter
        cnt++;
    }
    // Return the length of the cycle
    return cnt;
}
// Function to calculate the length of a linked list until the start of a cycle
int lengthOfLL(Node *head) {
    // Initialize slow and fast pointers to the head of the linked list
    Node* slow = head;
    Node* fast = head;
    // Traverse the linked list using slow and fast pointers
    while(fast != NULL && fast->next != NULL) {
        // Move the slow pointer one step forward
        slow = slow->next;
        // Move the fast pointer two steps forward
        fast = fast->next->next;
        // If slow and fast pointers meet at the same node, it indicates the presence of a cycle
        if(slow == fast) {
            // Return the length of the cycle by calling the findLength function
            return findLength(slow, fast);
        }
    }
    // If no cycle is detected, return 0 (length of the linked list)
    return 0;
}
int main() {
    // Create a sample linked list
    // with a loop for testing
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third; 
    // Check if there is a loop 
    // n the linked list
    cout << "Length of the loop in the linked list is: " << lengthOfLL(head) << endl;
    return 0;
}