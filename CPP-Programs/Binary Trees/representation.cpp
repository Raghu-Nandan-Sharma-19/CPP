#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void printTree(Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    printTree(root);

    return 0;
}