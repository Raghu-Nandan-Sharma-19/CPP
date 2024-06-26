#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
void inorderTraversal(Node *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorderTraversal(root);
    cout<<endl;
    return 0;
}