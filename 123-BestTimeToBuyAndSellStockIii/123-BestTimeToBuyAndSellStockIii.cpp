// Last updated: 9/16/2025, 9:53:44 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> buy(2, INT_MIN);
        vector<int> sell(2, 0);

        for (auto it : prices) {
            for (int i = 0; i < 2; i++) {
                if (i == 0)
                    buy[i] = max(buy[i], -it);
                else
                    buy[i] = max(buy[i], sell[i - 1] - it);
                sell[i] = max(sell[i], buy[i] + it);
            }
        }
        return sell[2 - 1];
    }
};