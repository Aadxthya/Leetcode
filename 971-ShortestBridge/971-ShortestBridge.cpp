// Last updated: 9/16/2025, 9:50:25 AM
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;

        // Direction vectors for moving in 4 directions (up, down, left, right)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Helper function to perform DFS and mark the first island
        function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = 2;
            q.push({x, y});
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                    dfs(nx, ny);
                }
            }
        };
        
        // Find the first island and mark it
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }
        
        // BFS to find the shortest path to the second island
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (grid[nx][ny] == 1) return steps; // Found the second island
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2; // Mark as visited
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ++steps;
        }
        
        return -1; // This should never be reached if input is valid
    }
};
