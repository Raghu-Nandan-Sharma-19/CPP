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
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}
// // brute force approach
// // Function to merge two sorted subarrays within the array 'arr'
// void merge(vector<int> &arr, int low, int mid, int high) {
//     // Create a temporary vector to store merged elements
//     vector<int> temp;
//     // Initialize pointers for the left and right subarrays
//     int left = low, right = mid + 1;
//     // Merge the two sorted subarrays into the temporary vector
//     while (left <= mid && right <= high) {
//         // Compare elements from both subarrays and append the smaller one to the temp vector
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     // Append remaining elements from the left subarray to the temp vector
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     // Append remaining elements from the right subarray to the temp vector
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     // Copy the merged elements from the temp vector back to the original array 'arr'
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }
// // Function to perform merge sort on the array 'arr'
// void mergeSort(vector<int> &arr, int low, int high) {
//     // Base case: if the range contains only one element or less, return
//     if (low >= high) return;
//     // Calculate the middle index of the range
//     int mid = (low + high) / 2;
//     // Recursively sort the left and right halves of the array
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     // Merge the sorted halves
//     merge(arr, low, mid, high);
// }
// Node* sortLL(Node* head) {
//     // Create a vector to store the elements of the linked list
//     vector<int> arr;
//     // Initialize a temporary pointer to traverse the linked list starting from the head
//     Node* temp = head;
//     // Traverse the linked list and store the data of each node in the vector
//     while(temp != NULL) {
//         arr.push_back(temp->data); // Store the data in the vector
//         temp = temp->next; // Move to the next node
//     }
//     // Call merge sort function to sort the elements in the vector
//     mergeSort(arr, 0, arr.size()-1);
//     // Initialize an index variable for traversing the sorted array
//     int i = 0; 
//     // Reset the temporary pointer to the head of the linked list
//     temp = head;
//     // Traverse the linked list again and update each node with the sorted values
//     while(temp != NULL) {
//         temp->data = arr[i]; // Update the data of the current node with the sorted value
//         i++; // Move to the next element in the sorted array
//         temp = temp->next; // Move to the next node in the linked list
//     }
//     // Return the head of the sorted linked list
//     return head;
// }
// Optimal solution below
// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    // Initialize two pointers, one moves one step at a time, the other moves two steps at a time
    Node* slow = head;
    Node* fast = head->next;
    // Move until the fast pointer reaches the end of the list or the second last node
    while(fast != NULL && fast->next != NULL) {
        // Move the slow pointer one step
        slow = slow->next;
        // Move the fast pointer two steps
        fast = fast->next->next;
    }
    // Return the middle node
    return slow;
}
// Function to merge two sorted linked lists
Node* merge2List(Node* leftHead, Node* rightHead) {
    // Initialize pointers for traversing both lists
    Node* t1 = leftHead;
    Node* t2 = rightHead;
    // Create a dummy node to simplify the code
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    // Merge the two lists while they both have elements
    while(t1 != NULL && t2 != NULL) {
        // Compare values of nodes and link them accordingly
        if(t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    // Append remaining nodes if any
    if(t1 != NULL) {
        temp->next = t1;
    } else {
        temp->next = t2;
    }
    // Return the merged list
    return dummyNode->next;
}
// Function to sort a linked list using merge sort
Node* sortLL(Node* head) {
    // Base case: if the list is empty or has only one element, it is already sorted
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Find the middle node of the list
    Node* middle = findMiddle(head);
    // Divide the list into two halves
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL; // Separate the two halves
    // Recursively sort the two halves
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    // Merge the sorted halves
    return merge2List(leftHead, rightHead);
}
int main() {
    vector<int> arr = {3, 4, 2, 1, 5};
    Node* head = convertArr2LL(arr);
    cout<<"Before sorting : "<<endl;
    print(head);
    cout<<"After sorting : "<<endl;
    sortLL(head);
    print(head);
    return 0;
}