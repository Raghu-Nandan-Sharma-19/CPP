#include<bits/stdc++.h>
using namespace std;
// // //  brute force approach
// int numberOfSubstrings(string s) {
//     int cnt = 0;
//     for(int i = 0; i < s.size(); i++) {
//         vector<int> hash(3, 0);
//         for(int j = i; j < s.size(); j++) {
//             hash[s[j] - 'a'] = 1;
//             if(hash[0] + hash[1] + hash[2] == 3) cnt = cnt + 1; 
//         }
//     }
//     return cnt;
// }
// // optimal approach
int numberOfSubstrings(string s) {
    int cnt = 0;
    vector<int> lastSeen(3, -1);
    for(int i = 0; i < s.size(); i++) {
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
    }
    return cnt;
}
int main() {
    string s = "bbacba";
    cout<<numberOfSubstrings(s)<<endl;
    return 0;
}