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
// // Brute force approach
// // Function to merge two sorted linked lists into a single sorted linked list
// Node* mergeSortedLL(Node* head1, Node* head2) {
//     // Initialize a vector to store the data of merged nodes
//     vector<int> arr;
//     // Temporary pointers to traverse the input linked lists
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     // Traverse the first linked list and store its data in the vector
//     while(temp1 != NULL) {
//         arr.push_back(temp1->data);
//         temp1 = temp1->next;
//     }
//     // Traverse the second linked list and store its data in the vector
//     while(temp2 != NULL) {
//         arr.push_back(temp2->data);
//         temp2 = temp2->next;
//     }
//     // Sort the vector containing merged data
//     sort(arr.begin(), arr.end());
//     // Convert the sorted vector into a new linked list
//     Node* head = convertArr2LL(arr);
//     // Return the head of the merged sorted linked list
//     return head;
// }
// optimal solution below
// Function to merge two sorted linked lists into a single sorted linked list
Node* mergeSortedLL(Node* head1, Node* head2) {
    // Initialize pointers to traverse the two input linked lists and a dummy node
    // to build the merged list
    Node* t1 = head1;        // Pointer for traversing the first linked list
    Node* t2 = head2;        // Pointer for traversing the second linked list
    Node* dummyNode = new Node(-1); // Dummy node to facilitate the merging process
    Node* temp = dummyNode;  // Pointer to the current node in the merged list
    // Traverse both input linked lists until one of them reaches its end
    while(t1 != NULL && t2 != NULL) {
        // Compare the data of the current nodes in the two lists
        if(t1->data < t2->data) {
            // If the data in the first list is smaller, append it to the merged list
            temp->next = t1;
            temp = t1;
            t1 = t1->next;  // Move to the next node in the first list
        } else {
            // If the data in the second list is smaller or equal, append it to the merged list
            temp->next = t2;
            temp = t2;
            t2 = t2->next;  // Move to the next node in the second list
        }
    }
    // Append the remaining nodes of the non-empty list to the merged list
    if(t1 != NULL) {
        temp->next = t1;    // If the first list has remaining nodes
    } else {
        temp->next = t2;    // If the second list has remaining nodes
    }
    // Return the head of the merged sorted linked list (skip the dummy node)
    return (dummyNode->next);
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
int main() {
    vector<int> arr1 = {2, 4, 8, 10};
    vector<int> arr2 = {1, 3, 3, 6, 11, 14};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    cout<<"Before merging : "<<endl;
    cout<<"Linked List 1 : "<<endl;
    print(head1);
    cout<<"Linked List 2 : "<<endl;
    print(head2);
    cout<<"After merging both Linked List : "<<endl;
    Node* head = mergeSortedLL(head1, head2);
    print(head);
    return 0;   
}