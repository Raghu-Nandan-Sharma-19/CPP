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
    }
}
Node* deleteK(Node* head, int k) {
    if(head == NULL) return head; // if linked list is empty
    if(k == 1) { // if k is 1 then delete the first element
        Node* temp = head; // store the head in temp
        head = head->next; // move head to next element
        free(temp); // free the memory of temp
        return head; // return the new head
    }
    int cnt = 0; // count the number of elements
    Node* temp = head; // store the head in temp
    Node* prev = NULL; // store the previous element
    while(temp != NULL) { // iterate through the linked list
        cnt++; // increment the count
        if(cnt == k) { // if count is equal to k
            prev->next = prev->next->next; // make the next of previous element to next of next element
            free(temp); // free the memory of temp
            break; // break the loop
        }
        prev = temp; // store the temp in prev
        temp = temp->next; // move temp to next element
    }
    return head; // return the head
}
int main() {
    vector<int> arr = {1, 8, 9, 3};
    Node* head = convertArr2LL(arr);
    head = deleteK(head, 2);
    print(head);
    return 0;
}