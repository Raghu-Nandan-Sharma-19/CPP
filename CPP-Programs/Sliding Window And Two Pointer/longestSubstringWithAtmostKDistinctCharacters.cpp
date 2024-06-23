#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str) {
    int maxLen = 0;
    map<char, int> mpp;
    for(int i = 0; i < str.size(); i++) {
        mpp.clear();
        for(int j = i; j < str.size(); j++) {
            mpp[str[j]]++;
            if(mpp.size() <= k) maxLen = max(maxLen, j - i + 1);
            else break;
        }
    }
    return maxLen;
}
int main() {
    string s = "aaabbccd";
    int k = 2;
    cout<<kDistinctChars(k, s)<<endl;
    return 0;
}