#include<bits/stdc++.h>
using namespace std;
int bestTimeToBuyAndSellStock(vector<int> &prices) {
    int mini = prices[0], maxProfit = 0;   // Initialize the minimum price and maximum profit
    for(int i=1; i<prices.size(); i++) { // Traverse the array
        int cost = prices[i]-mini; // Calculate the cost
        maxProfit = max(maxProfit, cost); // Update the maximum profit
        mini = min(mini, prices[i]); // Update the minimum price
    }
    return maxProfit; // Return the maximum profit
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