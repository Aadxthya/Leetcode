// Last updated: 9/16/2025, 9:52:22 AM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // Initialize with max value
         // Base case: 0 coins needed for amount 0
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};