// Last updated: 9/16/2025, 9:49:45 AM
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].push_back({to, 1});  // Original direction
            graph[to].push_back({from, 0});  // Reverse direction
        }

        vector<bool> visited(n, false);
        int changes = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto [neighbor, needsReverse] : graph[node]) {
                if (!visited[neighbor]) {
                    changes += needsReverse;
                    dfs(neighbor);
                }
            }
        };

        dfs(0);
        return changes;
    }
};
