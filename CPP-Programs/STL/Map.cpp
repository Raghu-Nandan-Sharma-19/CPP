#include<bits/stdc++.h>
#include<map>
using namespace std;
int main() {
    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;
    mpp[1]=2;
    mpp.emplace(3);
    mpp.insert({2, 4});
    for(auto it:mpp) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mpp[1];
    cout<<mpp[5];
}