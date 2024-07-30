#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, sum = 0;
    cout<<"Enter n : ";
    cin>>n;
    for(int count=1; count<=n; count++) {
        sum += (count*count);
    }
    cout<<"Sum of squares of first "<<n<<" natural numbers is : "<<sum<<endl;
    return 0;
}