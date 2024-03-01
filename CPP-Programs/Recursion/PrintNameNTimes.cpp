#include<bits/stdc++.h>
using namespace std;
void printNameNTimes(int i, int n) {
    if(i>n) {
        return;
    }
    cout<<"Raghu"<<endl;
    printNameNTimes(i+1, n);
}
int main() {
    int n;
    cin>>n;
    printNameNTimes(1, n);
    return 0;
}