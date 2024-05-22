#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    string data;
    Node * next;
    Node * prev;
    Node(string & val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    Node(string &val, Node * next1 , Node * prev1){
        data = val;
        next = next1;
        prev = prev1;
    }
};
class Browser {
public:
    Node* current; // Pointer to the current page
    // Constructor to initialize the browser with the homepage
    Browser(string &homepage) {
        current = new Node(homepage); // Create a new Node for the homepage
    }
    // Method to visit a new URL
    void visit(string &url) {
        Node* newNode = new Node(url); // Create a new Node for the visited URL
        current->next = newNode;       // Link the current page to the new page
        newNode->prev = current;       // Link the new page back to the current page
        current = newNode;             // Update the current page to the new page
    }
    // Method to move back a certain number of steps in the browsing history
    string back(int steps) {
        while(steps) {                 // Loop for the specified number of steps
            if(current->prev) {        // Check if there is a previous page
                current = current->prev; // Move to the previous page
                steps--;                 // Decrement the steps
            } else {
                break;                   // Stop if there is no previous page
            }
        }
        return current->data;          // Return the URL of the current page
    }
    // Method to move forward a certain number of steps in the browsing history
    string forward(int steps) {
        while(steps) {                 // Loop for the specified number of steps
            if(current->next) {        // Check if there is a next page
                current = current->next; // Move to the next page
                steps--;                 // Decrement the steps
            } else {
                break;                   // Stop if there is no next page
            }
        }
        return current->data;          // Return the URL of the current page
    }
};
int main() {
    string homepage = "leetcode.com";
    Browser* browser = new Browser(homepage);
    string url1 = "google.com";
    browser->visit(url1);
    string url2 = "facebook.com";
    browser->visit(url2);
    cout << browser->back(1) << endl;
    cout << browser->back(1) << endl;
    cout << browser->forward(1) << endl;
    string url3 = "youtube.com";
    browser->visit(url3);
    cout << browser->forward(1) << endl;
    cout << browser->back(1) << endl;
    cout << browser->back(1) << endl;
    cout << browser->forward(1) << endl;
    return 0;
}
