#include<bits/stdc++.h>
using namespace std;
int bestTimeToBuyAndSellStock(vector<int> &prices) {
    int mini = prices[0], maxProfit = 0;
    for(int i=1; i<prices.size(); i++) {
        int cost = prices[i]-mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
int main() {
    int days;
    cout<<"Enter the number of days: "<<endl;
    cin>>days;
    vector<int> prices;
    cout<<"Enter the prices of the stocks : "<<endl;
    for(int i=0; i<days; i++) {
        int x;
        cin>>x;
        prices.push_back(x);
    }
    cout<<"Maximum profit : "<<bestTimeToBuyAndSellStock(prices)<<endl;
    return 0;
}