#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
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
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    } cout<<endl;
}
// // brute force approach
// Node* removeNthFromEnd(Node* head, int N) {
//     // If the linked list is empty, return NULL
//     if (head == NULL) {
//         return NULL;
//     }
//     // Counting the number of nodes in the linked list
//     int cnt = 0;
//     Node* temp = head;
//     while (temp != NULL) {
//         cnt++;
//         temp = temp->next;
//     }
//     // If the count of nodes equals N, remove the head node
//     if (cnt == N) {
//         Node* newhead = head->next;
//         delete (head); // Deleting the head node
//         return newhead; // Returning the new head
//     }
//     // Calculate the position of the node to be deleted from the beginning
//     int res = cnt - N;
//     temp = head;
//     while (temp != NULL) {
//         res--;
//         if (res == 0) {
//             break;
//         }
//         temp = temp->next;
//     }
//     // Deleting the Nth node from the end
//     Node* delNode = temp->next;
//     temp->next = temp->next->next; // Reassigning pointers to bypass the node to be deleted
//     delete (delNode); // Deleting the node
//     return head; // Returning the head of the modified linked list
// }
// Optimal Solution Below
Node* removeNthFromEnd(Node* head, int n) {
    // Initialize two pointers fast and slow to head
    Node* fast = head;
    Node* slow = head;
    // Move the fast pointer n nodes ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }
    // If fast becomes NULL, it means the node to be removed is the head node
    if(fast == NULL) {
        return head->next; // Return the next node as the new head
    }
    // Move both fast and slow pointers until fast reaches the end
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // At this point, slow is pointing to the node just before the node to be removed
    // Remove the nth node from the end
    Node* delNode = slow->next; // Store the node to be deleted
    slow->next = slow->next->next; // Redirect the next pointer of the node before the deleted node
    delete (delNode); // Delete the node
    return head; // Return the head of the modified linked list
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);
    cout<<"Before removing : "<<endl;
    print(head);
    cout<<"After removing : "<<endl;
    head = removeNthFromEnd(head, 2);
    print(head);
    return 0;
}