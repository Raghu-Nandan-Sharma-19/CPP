#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
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
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head; // Start with the head of the list
    while (temp != NULL) { // Traverse the entire list
        if (temp->data == k) { // Check if the current node's data matches k
            if (temp == head) { // Special case: if the current node is the head
                head = head->next; // Update the head to the next node
                if (head != NULL) { // If the new head is not null
                    head->prev = NULL; // Set its prev pointer to null
                }
            }
            Node* nextNode = temp->next; // Store the next node
            Node* prevNode = temp->prev; // Store the previous node
            if (nextNode) nextNode->prev = prevNode; // Update next node's prev pointer
            if (prevNode) prevNode->next = nextNode; // Update previous node's next pointer
            delete temp; // Delete the current node
            temp = nextNode; // Move to the next node in the list
        } else {
            temp = temp->next; // Move to the next node if data does not match k
        }
    }
    return head; // Return the potentially new head of the list
}
int main() {
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    Node* head = convertArr2DLL(arr);
    int k = 10;
    cout<<"Before deleting occurances of "<<k<<" list is : "<<endl;
    print(head);
    cout<<"After deleting all occurances of "<<k<<" list is : "<<endl;
    head = deleteAllOccurrences(head, k);
    print(head);
    return 0;
}