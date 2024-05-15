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
// // Brute force approach
// Node* sort0s1sAnd2s(Node* head) {
//     // Initialize a temporary pointer to traverse the linked list
//     Node* temp = head;
//     // Initialize counters for each digit
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//     // Count the occurrences of 0s, 1s, and 2s in the linked list
//     while(temp != NULL) {
//         // Increment the corresponding counter based on the current node's data
//         if(temp->data == 0) cnt0++;
//         else if(temp->data == 1) cnt1++;
//         else cnt2++;
//         // Move to the next node
//         temp = temp->next;
//     }
//     // Reset temp to the head of the linked list
//     temp = head;
//     // Update the data of each node based on the counts of 0s, 1s, and 2s
//     while(temp != NULL) {
//         // Assign 0 if there are remaining 0s to be placed
//         if(cnt0) {
//             temp->data = 0;
//             cnt0--;
//         }
//         // Assign 1 if there are remaining 1s to be placed
//         else if(cnt1) {
//             temp->data = 1;
//             cnt1--;
//         }
//         // Assign 2 if there are remaining 2s to be placed
//         else {
//             temp->data = 2;
//             cnt2--;
//         }
//         // Move to the next node
//         temp = temp->next;
//     }
//     // Return the head of the sorted linked list
//     return head;
// }
// Optimal approach below 
Node* sort0s1sAnd2s(Node* head) {
    // Check if the linked list is empty or has only one node
    if(head == NULL || head->next == NULL) return head;
    // Create three dummy nodes to hold nodes with values 0, 1, and 2 respectively
    Node* zeroHead = new Node(-1);  // Head for nodes with value 0
    Node* oneHead = new Node(-1);   // Head for nodes with value 1
    Node* twoHead = new Node(-1);   // Head for nodes with value 2
    // Pointers to traverse the three lists
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    // Pointer to traverse the original linked list
    Node* temp = head;
    // Traverse the original list and segregate nodes into three separate lists
    while(temp != NULL) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        } else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        } else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    // Connect the lists of 0s, 1s, and 2s
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    // Get the head of the sorted linked list
    Node* newHead = zeroHead->next;
    // Free the memory occupied by the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    // Return the head of the sorted linked list
    return newHead;
}
int main() {
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node* head = convertArr2LL(arr);
    cout<<"Before sorting 0's 1's and 2's : "<<endl;
    print(head);
    cout<<"After sorting 0's 1's and 2's : "<<endl;
    head = sort0s1sAnd2s(head);
    print(head);
    return 0;
}