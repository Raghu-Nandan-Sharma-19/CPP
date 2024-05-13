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
// // brute force approach
// Node* oddEvenList(Node* head) {
//     // If the linked list is empty or has only one node, return it as it is
//     if(head == NULL || head->next == NULL) {
//         return head;
//     }
//     // Vector to store the values of the nodes in the linked list
//     vector<int> arr;
//     // Traverse the linked list to extract the values of nodes at odd positions
//     Node* temp = head;
//     while(temp != NULL && temp->next != NULL) {
//         arr.push_back(temp->data); // Store the data of the current node
//         temp = temp->next->next; // Move temp pointer two steps ahead
//     }
//     // If there is a single remaining node, add its data to the vector
//     if(temp) arr.push_back(temp->data);
//     // Move temp to the second node to traverse the even positions
//     temp = head->next;
//     // Traverse the linked list to extract the values of nodes at even positions
//     while(temp != NULL && temp->next != NULL) {
//         arr.push_back(temp->data); // Store the data of the current node
//         temp = temp->next->next; // Move temp pointer two steps ahead
//     }
//     // If there is a single remaining node, add its data to the vector
//     if(temp) arr.push_back(temp->data);
//     // Reassign values from the vector to the nodes of the linked list
//     int i = 0; // Index to iterate through the vector
//     temp = head; // Reset temp to the head of the linked list
//     while(temp != NULL) {
//         temp->data = arr[i]; // Assign the value from the vector to the current node
//         i++; // Move to the next element in the vector
//         temp = temp->next; // Move temp pointer to the next node in the linked list
//     }
//     // Return the modified head of the linked list
//     return head;
// }
// OPTIMAL SOLUTION
Node* oddEvenList(Node* head) {
    // Check if the linked list is empty or contains only one node
    if(head == NULL || head->next == NULL) return head;
    // Initialize pointers for odd and even nodes
    Node* odd = head;       // Points to the current odd node
    Node* even = head->next;// Points to the current even node
    Node* evenHead = head->next; // Save the head of the even list
    // Traverse the linked list and rearrange nodes
    while(even != NULL && even->next != NULL) {
        // Move the odd pointer to the next odd node
        odd->next = odd->next->next;
        // Move the even pointer to the next even node
        even->next = even->next->next;
        // Move to the next odd and even nodes
        odd = odd->next;
        even = even->next;
    }
    // Connect the last odd node to the head of the even list
    odd->next = evenHead;
    // Return the head of the modified linked list
    return head;
}
int main() {
    vector<int> arr = {2, 3, 1, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    head = oddEvenList(head);
    print(head);
    return 0;
}