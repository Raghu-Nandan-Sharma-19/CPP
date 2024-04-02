#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    cout<<"Enter " <<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int element;
    cout<<"Enter an element to find : "<<endl;
    cin>>element;
    cout<<"Found or not--> "<<binary_search(v.begin(), v.end(), element)<<endl;
    return 0;
}