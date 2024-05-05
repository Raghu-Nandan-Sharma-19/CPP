#include<bits/stdc++.h>
using namespace std;
class Node { // class Node
    public: // access specifier
    int data; // data
    Node* next; // next pointer
    public: // access specifier
    Node(int data1) { // constructor
        data = data1; // initialize data
        next = nullptr; // initialize next
    }
};
Node* convertArr2LL(vector<int> &arr) { // function to convert array to linked list
    Node* head = new Node(arr[0]); // create a new node with first element of array
    Node* mover = head; // create a mover pointer to move through the linked list
    for(int i=1; i<arr.size(); i++) { // iterate through the array
        Node* temp = new Node(arr[i]); // create a new node with array element
        mover->next = temp; // link the new node to the linked list
        mover = temp; // update mover
    }
    return head; // return head of linked list
}
int findElement(Node* head, int val) { // function to find element in linked list
    Node* temp = head; // create a temp pointer to move through the linked list
    while(temp) { // iterate through the linked list
        if(temp->data == val) return 1; // if element is found return 1
        temp = temp->next; // update temp
    }
    return 0; // if element is not found return 0
}
int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    int val = 8;
    if(findElement(head, val) == 1) {
        cout<<val<<" is present in linked list"<<endl;
    } else {
        cout<<val<<" is not present in linked list"<<endl;
    }
    return 0;
}