#include<bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<char> arr;
    cout<<"Enter "<<size<<" characters : "<<endl;
    unordered_map<char, int> mpp;
    for(int i=0; i<size; i++) {
        char x;
        cin>>x;
        arr.push_back(x);
        // pre-compute
        mpp[arr[i]]++;
    }
    /* pre-compute
    unordered_map<char, int> mpp;
    for(char i=0; i<size; i++) {
        mpp[arr[i]]++;
    }    
    */
    cout<<"Enter the number of character for which you want to count the frequencies : "<<endl;
    int noOfCharacters;
    cin>>noOfCharacters;
    cout<<"Enter "<<noOfCharacters<<" characters to find frequency : "<<endl;
    while(noOfCharacters--) {
        char ch;
        cin>>ch;
        // fetch
        cout<<ch<<" appears "<<mpp[ch]<<" times"<<endl;
    }
    return 0;
}