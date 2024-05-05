#include<bits/stdc++.h>
using namespace std;
int countSubStrings(string str, int k) {
    int find = 0; //initialize the count of substrings
    for(int i=0; i<str.size(); i++) {   // iterate through the string
        int cnt = 0; //reset the cnt for every substring
        int charcount[26] = {0}; //initialize the count of characters
        for(int j= i;j<str.size();j++){ // iterate through the string
            int charindex = str[j] - 'a'; // get the index of the character
            if(charcount[charindex] == 0){ // if the character is not present in the substring
                charcount[charindex]++; // increment the count of the character
                cnt++; // increment the count of distinct characters
            }
            if(cnt == k){ // if the count of distinct characters is equal to k
                find++; // increment the count of substrings
            } else if (cnt > k) { // if the count of distinct characters is greater than k
                break; // break the loop
            }
        }
    }
    return find; // return the count of substrings
}
int main() {
    string str = "abcabc";
    int k = 3;
    cout<<"Number of substrings with exactly "<<k<<" distinct characters are : "<<countSubStrings(str, k)<<endl;
    return 0;
}