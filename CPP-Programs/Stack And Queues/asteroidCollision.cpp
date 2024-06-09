#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& astro) {
    stack<int>s;
    for(auto i : astro) {
        if(s.empty()) {
            s.push(i);
        } else if(i>0) {
            s.push(i);
        } else if(i<0) {
            // while(!s.empty()) {
            //     if(s.top()<=abs(i)) {
            //         s.pop();
            //     }
            //     else {
            //         // s.push(i);
            //         break;
            //     }
            // }
            while(!s.empty() && s.top() > 0 && s.top() < abs(i)) {
                s.pop();
            }
            if(!s.empty() && s.top() > 0) {
                if(s.top() == abs(i)) {
                    s.pop();
                }
            }
            else {
                s.push(i);
            }
        }
    }
    vector<int>ans;
    for(;!s.empty();) {
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n = 6;
    vector<int> arr = {5, 10, -5};
    vector<int> ans = asteroidCollision(arr);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}