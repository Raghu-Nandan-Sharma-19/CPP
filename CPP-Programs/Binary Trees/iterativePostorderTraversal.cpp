#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
vector<int> postorderTraversal(Node* root) {
    vector<int> postOrder;
    if(root == NULL) return postOrder;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }
    while(!st2.empty()) {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrder;
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> res = postorderTraversal(root);
    for(auto ele : res) {
        cout<<ele<<" ";
    } cout<<endl;
    return 0;
}