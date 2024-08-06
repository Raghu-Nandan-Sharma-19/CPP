#include<bits/stdc++.h>
using namespace std;
int main() {
    int temperature;
    cout<<"Enter temperature (in farenheit) : ";
    cin>>temperature;

    if(temperature>70 && temperature<90) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}