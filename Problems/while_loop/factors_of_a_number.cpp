#include<bits/stdc++.h>
using namespace std;
int main() {
    int number;
    cout<<"Enter number : ";
    cin>>number;
    int count = 1;
    cout<<"Factors of "<<number<<" are : "<<endl;
    while(count <= number) {
        if(number % count == 0) {
            cout<<count<<endl;
        }
        count++;
    }
    return 0;
}