#include<bits/stdc++.h>
using namespace std;

int capacity;
int minFreq;
unordered_map<int, pair<int,int>> keyVal;
unordered_map<int, list<int>> freqList;
unordered_map<int, list<int>::iterator> pos;

void LFUCache(int capacity) {
    capacity = capacity;
    minFreq = 0;
}

int get(int key) {
    if(keyVal.find(key) == keyVal.end()) return -1;

    freqList[keyVal[key].second].erase(pos[key]);
    keyVal[key].second++;
    freqList[keyVal[key].second].push_back(key);
    pos[key] = --freqList[keyVal[key].second].end();

    if(freqList[minFreq].empty()) minFreq++;
    return keyVal[key].first;
}

void put(int key, int value) {
    if(!capacity) return;

    if(keyVal.find(key) != keyVal.end()) {
        keyVal[key].first = value;
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty()) minFreq++;
        return;
    }

    if(keyVal.size() == capacity) {
        int delKey = freqList[minFreq].front();
        keyVal.erase(delKey);
        pos.erase(delKey);
        freqList[minFreq].pop_front();
    }

    keyVal[key] = {value,1};
    freqList[1].push_back(key);
    pos[key] = --freqList[1].end();
    minFreq = 1;
}
int main() {
    // Test the LFUCache implementation
    int capacity = 3;
    LFUCache(capacity);

    // Perform cache operations
    put(1, 10);
    put(2, 20);
    put(3, 30);
    put(4, 40);

    int value = get(2);
    cout << "Value of key 2: " << value << endl;

    value = get(3);
    cout << "Value of key 3: " << value << endl;

    put(5, 50);

    value = get(1);
    cout << "Value of key 1: " << value << endl;

    value = get(4);
    cout << "Value of key 4: " << value << endl;

    value = get(5);
    cout << "Value of key 5: " << value << endl;

    return 0;
}
