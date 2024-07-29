#include<bits/stdc++.h>
using namespace std;
int main() {
    int number;
    cout<<"Enter a month (in numbers) : ";
    cin>>number;
    if(number == 1) cout<<"January"<<endl;
    else if(number == 2) cout<<"February"<<endl;
    else if(number == 3) cout<<"March"<<endl;
    else if(number == 4) cout<<"April"<<endl;
    else if(number == 5) cout<<"May"<<endl;
    else if(number == 6) cout<<"June"<<endl;
    else if(number == 7) cout<<"July"<<endl;
    else if(number == 8) cout<<"August"<<endl;
    else if(number == 9) cout<<"September"<<endl;
    else if(number == 10) cout<<"October"<<endl;
    else if(number == 11) cout<<"November"<<endl;
    else if(number == 12) cout<<"December"<<endl;
    else cout<<"Please enter a valid month"<<endl;
    return 0;
}