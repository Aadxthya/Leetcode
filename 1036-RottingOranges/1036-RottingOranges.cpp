// Last updated: 9/16/2025, 9:50:16 AM
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int fresh = 0;

        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 1: Add all rotten oranges to queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                if (grid[i][j] == 1) fresh++;
            }
        }

        int time = 0;
        int rotted = 0;

        // Step 2: BFS to rot neighboring fresh oranges
        while (!q.empty()) {
            int size = q.size();
            bool didRot = false;
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                        !visited[nx][ny] && grid[nx][ny] == 1) {
                        visited[nx][ny] = 1;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        rotted++;
                        didRot = true;
                    }
                }
            }
            if (didRot) time++;
        }

        // Step 3: Check if all fresh are rotted
        return (rotted == fresh) ? time : -1;
    }
};
