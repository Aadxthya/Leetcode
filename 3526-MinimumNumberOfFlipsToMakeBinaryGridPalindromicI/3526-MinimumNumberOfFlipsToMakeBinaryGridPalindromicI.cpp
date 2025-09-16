// Last updated: 9/16/2025, 9:48:07 AM
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Helper function to count flips to make a row palindromic
        auto rowFlips = [&](vector<int>& row) {
            int flips = 0;
            for (int i = 0; i < row.size() / 2; ++i) {
                if (row[i] != row[row.size() - 1 - i]) {
                    flips++;
                }
            }
            return flips;
        };
        
        // Helper function to count flips to make a column palindromic
        auto colFlips = [&](vector<vector<int>>& grid, int col) {
            int flips = 0;
            for (int i = 0; i < grid.size() / 2; ++i) {
                if (grid[i][col] != grid[grid.size() - 1 - i][col]) {
                    flips++;
                }
            }
            return flips;
        };
        
        // Calculate the total flips to make all rows palindromic
        int rowTotalFlips = 0;
        for (int i = 0; i < m; ++i) {
            rowTotalFlips += rowFlips(grid[i]);
        }
        
        // Calculate the total flips to make all columns palindromic
        int colTotalFlips = 0;
        for (int j = 0; j < n; ++j) {
            colTotalFlips += colFlips(grid, j);
        }
        
        // Return the minimum of the two
        return min(rowTotalFlips, colTotalFlips);
    }
};
