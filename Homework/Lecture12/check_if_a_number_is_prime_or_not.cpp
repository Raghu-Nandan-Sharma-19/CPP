#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    if (num < 2) {
        cout<<num<<" is not a prime number"<<endl;
    }
    for(int count = 2; count <= num; count++)
    {
        if(num % count == 0)
        {
            cout<<num<<" is not a prime number"<<endl;
            break;
        }
        cout<<num<<" is a prime number"<<endl;
        break;
    }
    return 0;
}