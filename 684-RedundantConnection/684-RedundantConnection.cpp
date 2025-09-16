// Last updated: 9/16/2025, 9:51:13 AM
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        // Initially, each node is its own parent
        for (int i=1; i<=n; ++i) parent[i] = i;

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        // Union function
        auto union_set = [&](int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return false; // Already connected
            parent[py] = px;
            return true;
        };

        // Try to union each edge, return the edge that can't be unioned
        for (auto& edge : edges) {
            if (!union_set(edge[0], edge[1]))
                return edge; // This edge forms a cycle
        }
        return {};
    }
};
