#include<bits/stdc++.h>
using namespace std;
int main() {
    int number;
    cout<<"Enter number : ";
    cin>>number;
    int count = 1;
    do {
        cout<<number<<" * "<<count<<" = "<<number*count<<endl;
        count++;
    } while(count <= 10);
    return 0;
}