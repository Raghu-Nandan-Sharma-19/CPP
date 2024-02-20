#include<bits/stdc++.h>
using namespace std;
int main() {
    string s = "Raghu";
    cout<<s[0]<<endl;
    int len = s.size();
    cout<<"Length : "<<len<<endl;
    s[len-1] = 'x';
    cout<<"Modified string : "<<s[len-1]<<endl;
    return 0;
}