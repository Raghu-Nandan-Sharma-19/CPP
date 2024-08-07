#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    
    int fact = 1, count = 1;
    
    while (count <= num)
    {
        fact *= count;
        count++;
    }
    cout<<"Factorial of "<<num<<" is : "<<fact<<endl;
    
    return 0;
}