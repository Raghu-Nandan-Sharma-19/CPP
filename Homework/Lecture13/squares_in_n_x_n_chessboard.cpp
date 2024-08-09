#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    
    int ans = (n * (n + 1) * (2 * n + 1)) / 6;
    cout<<"Squares in "<<n<<" * "<<n<<" chessboard are : "<<ans<<endl;

    return 0;
}