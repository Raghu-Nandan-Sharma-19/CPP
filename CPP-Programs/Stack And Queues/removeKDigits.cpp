#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    if(k == num.size()) return "0";
    stack<char> stk;
    for(auto c :num){
        while(k > 0 && !stk.empty() && stk.top() > c){
            stk.pop();
            k -= 1;
        }
        stk.push(c);
    }
    while(!stk.empty() && k > 0){
        stk.pop();
        k--;
    }
    string ret = "";
    while(!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }
    reverse(ret.begin(), ret.end());
    int a = 0;
    while(ret[a] == '0' && a < ret.size()){
        a++;
    }
    if(a == ret.size()) return "0";
    string res = "";
    for(int i = a; i < ret.size(); i++){
        res += ret[i];
    }
    return res;
}
int main() {
    string num = "1432219";
    int k = 3;
    cout << removeKdigits(num, k);
    return 0;
}