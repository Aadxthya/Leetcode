// Last updated: 9/16/2025, 9:50:17 AM
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(days.begin(), days.end());
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);

        for (int d = 1; d <= lastDay; ++d) {
            if (travel.count(d) == 0) {
                dp[d] = dp[d - 1];
            } else {
                int cost1 = dp[d - 1] + costs[0];
                int cost7 = dp[max(0, d - 7)] + costs[1];
                int cost30 = dp[max(0, d - 30)] + costs[2];
                dp[d] = min({cost1, cost7, cost30});
            }
        }
        return dp[lastDay];
    }
};
