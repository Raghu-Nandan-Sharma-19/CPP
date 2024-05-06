#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr) { // convert array to linked list
    Node* head = new Node(arr[0]); // create a new node with first element of array
    Node* mover = head; // create a mover node and store the head in it
    for(int i=1; i<arr.size(); i++) { // iterate through the array
        Node* temp = new Node(arr[i]); // create a new node with ith element of array
        mover->next = temp; // make the next of mover to temp
        mover = temp; 
    }
    return head;
}
Node* deleteElement(Node* head, int el) { // delete element from linked list
    if(head == NULL) return head; // if linked list is empty
    if(head->data == el) { // if head is the element to be deleted
        Node* temp = head; // store the head in temp
        head = head->next; // move head to next element
        free(temp); // free the memory of temp
        return head; // return the new head
    }
    Node* temp = head; // store the head in temp
    Node* prev = NULL; // store the previous element
    while(temp != NULL) { // iterate through the linked list
        if(temp->data == el) { // if element is found
            prev->next = prev->next->next; // make the next of previous element to next of next element
            free(temp); // free the memory of temp
            break; // break the loop
        }
        prev = temp; // store the temp in prev
        temp = temp->next; // move temp to next element
    }
    return head; // return the head
}
void print(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main() {
    vector<int> arr = {1, 8, 9, 3};
    Node* head = convertArr2LL(arr);
    head = deleteElement(head, 9);
    print(head);
    return 0;
}