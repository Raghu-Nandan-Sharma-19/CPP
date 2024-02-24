#include<bits/stdc++.h>
using namespace std;
void print(int n) {
    for(int i=1; i<=2*n-1; i++) {
        int stars = i;
        if(i>n) stars = 2*n-i;
	    for(int j=2; j<=stars; j++) {
		    cout<<"* ";
	    }
        cout<<endl;
    }
}
int main() {
    int n, t;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        print(n);
    }
    return 0;
}