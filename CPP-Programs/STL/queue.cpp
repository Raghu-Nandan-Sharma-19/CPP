#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<string> q;
    q.push("Raghu");
    q.push("Sharma");
    q.push("Nandan");
    cout<<"First element--> "<<q.front()<<endl;
    cout<<"Size before pop--> "<<q.size()<<endl;
    q.pop();
    cout<<"First element--> "<<q.front()<<endl;
    cout<<"Size after pop--> "<<q.size()<<endl;
    return 0;
}