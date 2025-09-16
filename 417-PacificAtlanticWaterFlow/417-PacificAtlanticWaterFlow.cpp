// Last updated: 9/16/2025, 9:51:56 AM
class Solution {
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& visi, vector<vector<int>>& h, int m, int n) {
        int ar1[] = {0, 1, 0, -1}; 
        int ar2[] = {1, 0, -1, 0}; 

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {  // loop over 4 directions, not m
                int xr = x + ar1[i];
                int yr = y + ar2[i];

                if (xr < 0 || xr >= n || yr < 0 || yr >= m || visi[xr][yr] == 1) {
                    continue;
                }

                if (h[x][y] <= h[xr][yr]) {
                    q.push({xr, yr});
                    visi[xr][yr] = 1;
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visi1(n, vector<int>(m, 0));
        vector<vector<int>> visi2(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Pacific boundary
        for (int i = 0; i < m; i++) {
            q.push({0, i});
            visi1[0][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            visi1[i][0] = 1;
        }

        bfs(q, visi1, heights, m, n);

        // Clear queue before using it for Atlantic
        while (!q.empty()) q.pop();

        // Atlantic boundary
        for (int i = 0; i < m; i++) {
            q.push({n - 1, i});
            visi2[n - 1][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            visi2[i][m - 1] = 1;
        }

        bfs(q, visi2, heights, m, n);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visi1[i][j] == 1 && visi2[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
