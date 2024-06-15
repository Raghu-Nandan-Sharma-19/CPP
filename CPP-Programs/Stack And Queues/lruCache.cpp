#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int key, data;
    Node *next, *prev;
    Node(int k, int v){
        key = k; data = v;
        prev = next = NULL;
    }
};
int size;
unordered_map<int, Node*> mp;
Node *head = NULL, *tail = NULL;

void deleteNode(Node* num){
    int k = num -> key;

    if(num -> prev == NULL) head = head -> next;
    if(num -> next == NULL) tail = tail -> prev;

    if(num -> prev != NULL) num -> prev -> next = num -> next;
    if(num -> next != NULL) num -> next -> prev = num -> prev;

    mp.erase(k);
    delete num;
}

void insert(int k, int v){
    Node* num = new Node(k, v);
    mp[k] = num;

    if(head == NULL) {
        head = tail = num;
        return;
    }

    tail -> next = num;
    num -> prev = tail;
    tail = num;
}
int LRUCache(int capacity) { 
    size = capacity; 
}

int get(int key) {
    if(mp.count(key) == 0) return -1;

    int val = mp[key] -> data;
    deleteNode(mp[key]);
    insert(key, val);
    return val;
}
    
void put(int key, int value) {
    if(mp.count(key) == 0) {
        if(mp.size() == size) deleteNode(head);
    }
    else {
        deleteNode(mp[key]);
    }

    insert(key, value);
}
int main() {
    LRUCache(2);
    put(1, 1);
    put(2, 2);
    cout << get(1) << endl;
    put(3, 3);
    cout << get(2) << endl;
    put(4, 4);
    cout << get(1) << endl;
    cout << get(3) << endl;
    cout << get(4) << endl;
    return 0;
}