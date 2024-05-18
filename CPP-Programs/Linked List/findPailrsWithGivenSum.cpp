#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
// // Brute force approach below
// vector<pair<int, int>> findPairs(Node* head, int sum) {
//     Node* temp1 = head; // Initialize temp1 to point to the head of the list
//     vector<pair<int, int>> result; // Initialize a vector to store the result pairs
//     while (temp1 != NULL) { // Traverse the list with temp1
//         Node* temp2 = temp1->next; // Initialize temp2 to point to the node after temp1
//         while (temp2 != NULL) { // Traverse the list with temp2 starting from temp1->next
//             // Check if the sum of data in temp1 and temp2 equals the target sum
//             if (temp1->data + temp2->data == sum) {
//                 result.push_back({temp1->data, temp2->data}); // Add the pair to the result
//             }
//             temp2 = temp2->next; // Move temp2 to the next node
//         }
//         temp1 = temp1->next; // Move temp1 to the next node
//     }
//     return result; // Return the result vector containing all pairs with the given sum
// }
// Optimal Approach below
Node* findTail(Node* head) {
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairs(Node* head, int sum) {
    vector<pair<int, int>> result; // Initialize a vector to store the result pairs
    if (head == NULL) return result; // Return empty result if the list is empty
    Node* left = head; // Initialize left pointer to the head of the list
    Node* right = findTail(head); // Initialize right pointer to the tail of the list
    // Loop until the data in the left pointer is less than the data in the right pointer
    while (left->data < right->data) {
        if (left->data + right->data == sum) { // If the sum of left and right data equals the target sum
            result.push_back({left->data, right->data}); // Add the pair to the result
            left = left->next; // Move the left pointer to the next node
            right = right->back; // Move the right pointer to the previous node
        } else if (left->data + right->data < sum) { // If the sum of left and right data is less than the target sum
            left = left->next; // Move the left pointer to the next node
        } else { // If the sum of left and right data is greater than the target sum
            right = right->back; // Move the right pointer to the previous node
        }
    }
    return result; // Return the result vector containing all pairs with the given sum
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 9};
    Node* head = convertArr2DLL(arr);
    cout<<"List is : "<<endl;
    print(head);
    int sum = 5;
    cout<<"The pairs with sum = "<<sum<<" are : "<<endl;
    vector<pair<int, int>> result = findPairs(head, sum);
    for(auto p : result) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}