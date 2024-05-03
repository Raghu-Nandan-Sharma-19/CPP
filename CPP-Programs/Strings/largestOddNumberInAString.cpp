#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string num) {
    for(int i=num.length()-1; i>=0; i--) {
        if(num[i] % 2 == 1) {
            return num.substr(0, i+1);
        }
    }
    return "";
}
int main() {
    string str = "52";
    cout<<"Largest odd number in string is : "<<largestOddNumber(str)<<endl;
    return 0;
}