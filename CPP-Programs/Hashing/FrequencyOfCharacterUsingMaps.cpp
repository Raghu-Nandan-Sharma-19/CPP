#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    // pre compute
    unordered_map<char, int> mpp;
    for(int i=0; i<s.size(); i++) {
        mpp[s[i]]++;
    }
    int q;
    cin>>q;
    while(q--) {
        char number;
        cin>>number;
        // fetch
        cout<<mpp[number]<<endl;
    }
    return 0;
}