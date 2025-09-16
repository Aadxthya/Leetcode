// Last updated: 9/16/2025, 9:51:08 AM

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }

        return sell;
    }
};