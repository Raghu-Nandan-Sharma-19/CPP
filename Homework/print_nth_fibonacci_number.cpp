#include<bits/stdc++.h>
using namespace std;
int main() {
    int last = 0, prev = 1, n, curr;
    cout<<"Enter n : ";
    cin>>n;
    for(int count=2; count<=n; ++count) {
        curr = last+prev;
        last = prev;
        prev = curr;
    }
    cout<<last<<endl;
    return 0;
}