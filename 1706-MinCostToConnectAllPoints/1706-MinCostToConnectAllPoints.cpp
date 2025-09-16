// Last updated: 9/16/2025, 9:49:37 AM
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            // Find the unvisited node with the smallest minDist value
            for (int v = 0; v < n; ++v) {
                if (!inMST[v] && (u == -1 || minDist[v] < minDist[u]))
                    u = v;
            }
            inMST[u] = true;
            result += minDist[u];

            // Update the minDist to other nodes
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }
        return result;
    }
};
