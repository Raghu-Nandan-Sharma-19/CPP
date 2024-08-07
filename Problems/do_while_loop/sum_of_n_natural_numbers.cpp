#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0, count = 1;
    cout<<"Enter n : ";
    cin>>n;
    do {
        sum += count;
        count++;
    } while(count <= n);
    cout<<sum;
    return 0;
}