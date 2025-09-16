// Last updated: 9/16/2025, 9:49:25 AM
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark visited

        int steps = 0;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // check bounds
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                    if (maze[nr][nc] == '.') {
                        // if on border and not entrance, it's an exit
                        if (nr == 0 || nc == 0 || nr == m - 1 || nc == n - 1)
                            return steps;

                        // mark visited and continue
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1; // no exit found
    }
};
