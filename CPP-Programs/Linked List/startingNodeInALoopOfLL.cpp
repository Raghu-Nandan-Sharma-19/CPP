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
// // Function to detect the starting node of a cycle in a linked list
// Node* detectStartingNode(Node* head) {
//     // Create a map to store visited nodes
//     map<Node*, int> nodeMap;
//     // Initialize a temporary pointer to traverse the linked list
//     Node* temp = head;
//     // Traverse the linked list until reaching the end
//     while(temp != NULL) {
//         // If the current node is already in the map, it means it's the starting node of the cycle
//         if(nodeMap.find(temp) != nodeMap.end()) {
//             return temp;
//         }
//         // Mark the current node as visited by adding it to the map
//         nodeMap[temp] = 1;
//         // Move to the next node in the linked list
//         temp = temp->next;
//     }
//     // If no cycle is detected, return NULL
//     return NULL;
// }
// Optimal approach --> tortoise and hare method
// Function to detect the starting node of a cycle in a linked list
Node* detectStartingNode(Node* head) {
    // Initialize two pointers, slow and fast, both pointing to the head of the linked list
    Node* slow = head;
    Node* fast = head;
    // Traverse the linked list using the slow and fast pointers
    while(fast != NULL && fast->next != NULL) {
        // Move the slow pointer one step forward
        slow = slow->next;
        // Move the fast pointer two steps forward
        fast = fast->next->next;
        // If slow and fast pointers meet at the same node, it indicates the presence of a cycle
        if(slow == fast) {
            // Reset the slow pointer to the head of the linked list
            slow = head;
            // Move both slow and fast pointers at the same pace until they meet again
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            // The node where slow and fast pointers meet again is the starting node of the cycle
            return slow;
        }
    }
    // If no cycle is detected, return NULL
    return NULL;
}
int main() {
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = detectStartingNode(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}