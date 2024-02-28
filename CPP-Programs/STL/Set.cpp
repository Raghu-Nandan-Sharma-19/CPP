#include<bits/stdc++.h>
#include<set>
using namespace std;
int main() {
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3);
    // Functionality of insert in vector
    // can be used also, that only increases efficiency
    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above
    auto it=st.find(3);
    auto it1=st.find(6);
    st.erase(5);
    int cnt=st.count(1);
    auto it3=st.find(3);
    st.erase(it);
    auto it=st.lower_bound(2);
    auto it=st.upper_bound(3);
    return 0;
}