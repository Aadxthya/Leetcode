// Last updated: 9/16/2025, 9:50:06 AM
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, component);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> adj(n);
        
        // Step 1: Build adjacency list
        for (auto &p : pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(n, false);
        string result = s;

        // Step 2: DFS for connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Step 3: Collect characters in this component
                string chars = "";
                for (int idx : component) chars.push_back(s[idx]);

                // Step 4: Sort both indices & chars
                sort(component.begin(), component.end());
                sort(chars.begin(), chars.end());

                // Step 5: Assign smallest chars back
                for (int k = 0; k < component.size(); k++) {
                    result[component[k]] = chars[k];
                }
            }
        }
        return result;
    }
};
