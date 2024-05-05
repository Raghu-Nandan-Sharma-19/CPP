#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
    unordered_map<char,int> digits; // create a map to store the values of the roman digits
    digits['M'] = 1000; // assign the values to the respective roman digits
    digits['D'] = 500; // assign the values to the respective roman digits
    digits['C'] = 100; // assign the values to the respective roman digits
    digits['L'] = 50; // assign the values to the respective roman digits
    digits['X'] = 10;
    digits['V'] = 5;
    digits['I'] = 1;
    int ans = 0;  // initialize the answer
    for(int i=s.length()-1; i>=0; i--) { // iterate through the string from the end
        if(digits[s[i]] < digits[s[i+1]]) { // if the value of the current digit is less than the value of the next digit
            ans -= digits[s[i]]; // subtract the value of the current digit from the answer
        } else { // if the value of the current digit is greater than or equal to the value of the next digit
            ans += digits[s[i]]; // add the value of the current digit to the answer
        }
    }
    return ans; // return the answer
}
int main() {
    string s = "IV";
    cout<<"Integer value of the roman number "<<s<<" is : "<<romanToInt(s)<<endl;
    return 0;
}