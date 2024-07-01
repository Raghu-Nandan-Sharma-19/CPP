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
vector<int> inorderTraversal(Node *root) {
    stack<Node*> st;
    Node *node = root;
    vector<int> inOrder;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> res = inorderTraversal(root);
    for(auto ele : res) {
        cout<<ele<<" ";
    } cout<<endl;
    return 0;
}