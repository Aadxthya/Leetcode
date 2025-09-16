// Last updated: 9/16/2025, 9:48:44 AM
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int s = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1]
                      + grid[i][j]
                      + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
