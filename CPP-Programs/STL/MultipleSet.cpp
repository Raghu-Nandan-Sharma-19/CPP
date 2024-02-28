#include<bits/stdc++.h>
#include<set>
using namespace std;
int main() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.erase(1);
    int cnt=ms.count(1);
    ms.erase(ms.find(1));
    // rest all functions are same as set
    return 0;
}