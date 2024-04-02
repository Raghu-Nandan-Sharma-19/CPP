#include<bits/stdc++.h>
using namespace std;
int main() {
    map<int, string> mpp;
    mpp[1] = "Sharma";
    mpp[2] = "Raghu";
    mpp[13] = "Nandan";
    mpp.insert({5, "bheem"});
    cout<<"Before erase : "<<endl;
    for(auto i:mpp) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"Finding 13--> "<<mpp.count(13)<<endl;
    mpp.erase(13);
    cout<<"After erase : "<<endl;
    for(auto i:mpp) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    auto it = mpp.find(5);
    for(auto i=it; i!=mpp.end(); i++) {
        cout<<(*i).first<<endl;
    }
    return 0;
}