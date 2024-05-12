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
// // Function to detect a loop in a linked list
// bool detectLoop(Node* head) {
//     // Create a map to store visited nodes
//     map<Node*, int> mpp;
//     // Initialize a pointer to traverse the linked list
//     Node* temp = head;
//     // Traverse the linked list until the end is reached (NULL)
//     while(temp != NULL) {
//         // Check if the current node is already visited
//         if(mpp.find(temp) != mpp.end()) {
//             // If the current node is already visited, there is a loop
//             return true;
//         }
//         // Mark the current node as visited by adding it to the map
//         mpp[temp] = 1;
//         // Move to the next node in the linked list
//         temp = temp->next;
//     }
//     // If the end of the list is reached without detecting a loop, return false
//     return false;
// }
// optimal approach 
// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    // Initialize two pointers, slow and fast, both pointing to the head of the list
    Node* slow = head;
    Node* fast = head;
    // Traverse the list until either fast reaches the end or fast's next pointer is NULL
    while(fast != NULL && fast->next != NULL) {
        // Move slow pointer one step forward
        slow = slow->next;
        // Move fast pointer two steps forward
        fast = fast->next->next;
        // If slow and fast pointers meet at the same node, there is a loop
        if(slow == fast) return true;
    }
    // If fast reaches the end of the list (NULL), or fast's next pointer is NULL, no loop is detected
    return false;
}
int main() {
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
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}