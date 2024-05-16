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
Node* findIntersection(Node* head1, Node* head2) {
    // If either of the linked lists is empty, there can't be any intersection
    if(head1 == NULL || head2 == NULL) return NULL;
    // Initialize two pointers to traverse the linked lists
    Node* t1 = head1; // Pointer for the first linked list
    Node* t2 = head2; // Pointer for the second linked list
    // Traverse the linked lists until either they intersect or reach the end
    while(t1 != t2) {
        // Move the pointers to the next nodes
        t1 = t1->next;
        t2 = t2->next;
        // If the pointers meet, it means an intersection is found
        if(t1 == t2) return t1;
        // If any pointer reaches the end of its list, reset it to the head of the other list
        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    // If there's no intersection, return NULL
    return t1;
}
void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}
int main() {
    // Create linked list 1: 1->2->3->4->5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    // Create linked list 2: 6->7->8->9->4->5
    Node* head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = head1->next->next->next; // Intersection point
    // Find the intersection point of the two linked lists
    Node* intersection = findIntersection(head1, head2);
    // Print the linked lists
    cout << "Linked List 1: ";
    printList(head1);
    cout << "Linked List 2: ";
    printList(head2);

    if (intersection != NULL) {
        cout << "Intersection Point: " << intersection->data << endl;
    } else {
        cout << "No intersection point found." << endl;
    }
    return 0;
}