//Best Time to Buy and Sell stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int  mini_price = prices[0];
        int max_profit = 0;
        for( int i = 1; i < n; i++){
            mini_price = min( mini_price , prices[i]);
            int profit = prices[i] - mini_price;
            max_profit = max(profit , max_profit);
        }
        return max_profit;
    }
};
