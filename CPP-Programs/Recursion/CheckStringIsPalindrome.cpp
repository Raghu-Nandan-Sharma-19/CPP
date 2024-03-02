#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(int i, string &name) {
    if(i>=name.size()/2) return true;
    if(name[i]!=name[name.size()-i-1]) {
        return false;
    }
    return checkPalindrome(i+1, name);
}
int main() {
    string name;
    cout<<"Enter anything : "<<endl;
    getline(cin, name);
    cout<<"You have entered : "<<endl<<name<<endl;
    cout<<"After reversing : "<<endl;
    for(int i=name.size()-1; i>=0; i--) {
        cout<<name[i];
    } cout<<endl;
    if(checkPalindrome(0, name)) {
        cout<<"The entered string is a palindrome"<<endl;
    } else {
        cout<<"The entered string is not a palindrome"<<endl;
    }
    return 0;
}