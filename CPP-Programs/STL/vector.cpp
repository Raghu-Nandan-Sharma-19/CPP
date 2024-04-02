#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;

    vector<int> a(5, 1);
    vector<int> last(a);
    cout<<"Printing last : "<<endl;
    for(int i:last) {
        cout<<i<<" ";
    } cout<<endl;
    cout<<"Printing a : "<<endl;
    for(int i:a) {
        cout<<i<<" ";
    } cout<<endl;

    cout<<"Capacity--> "<<v.capacity()<<endl; // --> returns allocated memory
    v.push_back(1);
    cout<<"Capacity--> "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity--> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity--> "<<v.capacity()<<endl;
    cout<<"Size--> "<<v.size()<<endl; // --> returns number of elements present
    cout<<"Element at second index--> "<<v.at(2)<<endl;

    cout<<"Front--> "<<v.front()<<endl;
    cout<<"Back--> "<<v.back()<<endl;

    cout<<"Before pop : "<<endl;
    for(int i=0; i<=v.size(); i++) {
        cout<<i<<" ";
    } cout<<endl;
    v.pop_back();
    cout<<"After pop : "<<endl;
    for(int i=0; i<=v.size(); i++) {
        cout<<i<<" ";
    } cout<<endl;

    cout<<"Before clear size--> "<<v.size()<<endl;
    v.clear();
    cout<<"After clear size--> "<<v.size()<<endl;
    return 0;
}