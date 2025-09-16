// Last updated: 9/16/2025, 9:52:52 AM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses; // Corrected: get n from input parameter
        vector<vector<int>> adj(n);
        vector<int> count(n, 0); // indegree array

        // Build adjacency list and indegree count
        for (const auto& edge : prerequisites) {
            int u = edge[1]; // prerequisite course
            int v = edge[0]; // dependent course
            adj[u].push_back(v);
            count[v]++;
        }

        stack<int> st;
        // Add all nodes with zero indegree to stack
        for(int i = 0; i < n; i++) {
            if(count[i] == 0) {
                st.push(i);
            }
        }

        int processed = 0; // count of processed (taken) courses

        while(!st.empty()) {
            int j = st.top();
            st.pop();
            processed++;
            // For all courses dependent on course j
            for(int next : adj[j]) {
                count[next]--;
                if(count[next] == 0) {
                    st.push(next);
                }
            }
        }

        // If all courses can be finished, processed should equal n
        return processed == n;
    }
};
