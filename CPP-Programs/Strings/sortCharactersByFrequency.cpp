#include<bits/stdc++.h>
using namespace std;
string sortByFrequency(int n, string s) {
    string ans = ""; // initialize the answer string
	unordered_map<char, int> mpp; // create a map to store the frequency of characters
	for(int i=0; i<n; i++) { // iterate through the string
		mpp[s[i]]++; // increment the frequency of the character
	}
	for(auto it:mpp) { // iterate through the map
		int I = it.second; // get the frequency of the character
		for(int i=0; i<I; i++) { // iterate through the frequency
			ans += it.first; // append the character to the answer string
		}
	}
	return ans; // return the answer string
}
int main() {
    string s = "abcAbc"; // initialize the string
    int n = s.length(); // get the length of the string
    cout<<"The string after sorting characters by frequency is : "<<sortByFrequency(n, s)<<endl; // print the sorted string
    return 0;
}