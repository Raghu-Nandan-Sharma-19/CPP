#include<bits/stdc++.h>
using namespace std;
int main() {
    int last=0, prev=1, num;
    cout<<"Enter number : ";
    cin>>num;
    for(int count=1; count<=num; count++) {
        cout<<last<<" ";
        int curr = last+prev;
        last = prev;
        prev = curr;
    }
    return 0;
}