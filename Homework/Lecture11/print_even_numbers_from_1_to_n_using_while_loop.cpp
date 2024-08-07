#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int count = 1;
    cout<<"Even numbers from 1 to "<<n<<" are : "<<endl;
    while(count <= n) {
        if(count % 2 == 0) {
            cout<<count<<" ";
        }
        count++;
    }
    return 0;
}