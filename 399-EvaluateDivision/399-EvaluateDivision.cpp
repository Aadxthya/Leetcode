// Last updated: 9/16/2025, 9:52:00 AM
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string start, string end, unordered_set<string>& visited) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;

        if (start == end) return 1.0;

        visited.insert(start);

        for (auto& [neighbor, weight] : graph[start]) {
            if (visited.count(neighbor)) continue;

            double result = dfs(neighbor, end, visited);
            if (result != -1.0) {
                return result * weight;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Step 2: Answer each query using DFS
        vector<double> results;
        for (auto& query : queries) {
            unordered_set<string> visited;
            double result = dfs(query[0], query[1], visited);
            results.push_back(result);
        }

        return results;
    }
};
