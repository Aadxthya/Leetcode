// Last updated: 9/16/2025, 9:54:36 AM
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> abovrow(n, 1);

        for (int i = 1; i < m; i++) {
            std::vector<int> currow(n, 1);
            for (int j = 1; j < n; j++) {
                currow[j] = currow[j - 1] + abovrow[j];
            }
            abovrow = currow;
        }
        
        return abovrow[n - 1];
    }
};
        