#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int count = 1;
    cout<<"Even numbers from 1 to "<<n<<" are : "<<endl;
    do 
    {
        if(count % 2 == 0) 
        {
            cout<<count<<" ";
        }
        count++;
    } while(count <= n);
    return 0;
}