#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    bool isNegative = false;
    int i = 0, n = s.size();
    //ignore spaces
    while (s[i] == ' ' ) i++;
    //process signs
    if (s[i] == '-' || s[i] == '+') {
        isNegative = (s[i] == '-');
        i++;
    }
    //process number : using just int
    int ans = 0;
    while(i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i]-'0';
        //check for overflow before inserting digit
        if (ans > (INT_MAX-digit)/10){
            return isNegative ? INT_MIN : INT_MAX;
        }
        //insert digit to ans
        ans = ans*10 + digit;
        i++;
    }
    //process number:  using long or double 
    /*
    long ans = 0;
    while(i < n && s[i] >= '0' && s[i] <= '9'){
        ans = ans*10 + (s[i]-'0');
        //handle overflow after adding digit
        if (ans > INT_MAX) return negative ? INT_MIN : INT_MAX;
        i++;
    }
    */
    //handle negative 
    if (isNegative) ans *= -1;
    return ans;
}
int main() {
    string s = "42";
    cout<<"Integer value of the string "<<s<<" is : "<<myAtoi(s)<<endl;
    return 0;
}