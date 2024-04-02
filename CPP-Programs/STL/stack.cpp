#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<string> s;
    s.push("Raghu");
    s.push("Sharma");
    s.push("Nandan");
    cout<<"Top element--> "<<s.top()<<endl;
    s.pop();
    cout<<"Top element--> "<<s.top()<<endl;
    cout<<"Size of stack--> "<<s.size()<<endl;
    cout<<"Empty or not--> "<<s.empty()<<endl;
    return 0;
}