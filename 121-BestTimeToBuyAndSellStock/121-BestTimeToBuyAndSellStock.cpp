// Last updated: 9/16/2025, 9:53:47 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
            int mini = prices[0];
            int profit = 0;

            if(prices.size()<2)
            return 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] - mini > profit)profit = prices[i] - mini;
            if(prices[i] < mini) mini = prices[i];

        }
        return profit;

    }
};