#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;
int next(int price) {
    int span = 1;
    while (!s.empty() && s.top().first <= price) {
        span += s.top().second;
        s.pop();
    }
    s.push({price, span});
    return span;
}
int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans;
    for (int price : prices) {
        spans.push_back(next(price));
    }
    cout << "Stock Span: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;
    return 0;
}