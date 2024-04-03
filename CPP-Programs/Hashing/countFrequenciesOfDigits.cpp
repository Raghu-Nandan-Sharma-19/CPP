#include<bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
        // you can pre-compute here just declare map before for loop
        // mpp[arr[i]]++;
    }
    // pre-compute
    unordered_map<int, int> mpp;
    for(int i=0; i<size; i++) {
        mpp[arr[i]]++;
    }
    // iterate in the map
    // for(auto it:mpp) {
    //     cout<<it.first<<" --> "<<it.second<<endl;
    // }
    cout<<"Enter the number of elements for which you want to find frequencies : "<<endl;
    int noOfElements;
    cin>>noOfElements;
    cout<<"Enter "<<noOfElements<<" elements : "<<endl;
    while(noOfElements--) {
        int number;
        cin>>number;
        // fetch
        cout<<number<<" appears "<<mpp[number]<<" times"<<endl;
    }
    return 0;
}