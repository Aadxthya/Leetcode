// Last updated: 9/16/2025, 9:49:18 AM
class Solution {
public:
    // Recursive DP function to calculate max earnings starting from ride `idx`
    long long solve(int idx, int m, vector<vector<int>>& rides, vector<int>& start, vector<long long>& dp){
        // Base case: if no rides left, return 0 earnings
        if(idx >= m) return 0;

        // If already computed, return cached result
        if(dp[idx] != -1) return dp[idx];

        // Find the next ride we can take (using binary search on start times)
        // nextIdx = first ride that starts >= current ride's end
        int nextIdx = lower_bound(start.begin(), start.end(), rides[idx][1]) - start.begin();

        // Option 1: Take this ride
        // Earnings = (distance of ride) + (tip) + (earnings from next non-conflicting ride)
        long long take = (rides[idx][1] - rides[idx][0])   // distance (end - start)
                         + rides[idx][2]                   // tip
                         + solve(nextIdx, m, rides, start, dp); // continue from next ride

        // Option 2: Skip this ride and move to the next one
        long long notTake = solve(idx+1, m, rides, start, dp);

        // Store and return the max of taking or skipping
        return dp[idx] = max(take, notTake);
    }

    // Main function
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();

        // Step 1: Sort rides by start time (needed for binary search correctness)
        sort(rides.begin(), rides.end());

        // Step 2: Create an array of ride start times (to binary search on)
        vector<int> start(m);
        for(int i=0; i<m; i++){
            start[i] = rides[i][0];
        }

        // Step 3: DP array initialized with -1 (for memoization)
        vector<long long> dp(m, -1);

        // Step 4: Solve starting from the first ride
        return solve(0, m, rides, start, dp);
    }
};
