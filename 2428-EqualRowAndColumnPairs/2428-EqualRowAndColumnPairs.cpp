// Last updated: 9/16/2025, 9:48:48 AM
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;
        map<vector<int>, int> rowCount;

        for (const auto& row : grid) {
            rowCount[row]++;
        }

        for (int col = 0; col < n; ++col) {
            vector<int> colVec;
            for (int row = 0; row < n; ++row) {
                colVec.push_back(grid[row][col]);
            }
            result += rowCount[colVec];
        }

        return result;
    }
};
