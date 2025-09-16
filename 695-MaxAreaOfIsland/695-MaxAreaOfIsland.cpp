// Last updated: 9/16/2025, 9:51:11 AM
class Solution {
public:
    int n, m;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0; // mark visited
        int area = 1;
        
        // explore 4 directions
        area += dfs(grid, i + 1, j);
        area += dfs(grid, i - 1, j);
        area += dfs(grid, i, j + 1);
        area += dfs(grid, i, j - 1);
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
