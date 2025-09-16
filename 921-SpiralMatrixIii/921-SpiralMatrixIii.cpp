// Last updated: 9/16/2025, 9:50:30 AM
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> path = {{rStart, cStart}};
        
        enum dir { east, south, west, north };
        int count = 2;

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int curr_row = rStart;
        int curr_col = cStart;
        int curr_dir = east;

        while (path.size() < rows * cols) {
            for (int i = 0; i < count / 2; i++) {
                curr_row += dr[curr_dir];
                curr_col += dc[curr_dir];
                if (0 <= curr_row && curr_row < rows && 0 <= curr_col && curr_col < cols) 
                    path.push_back({curr_row, curr_col});
            }
            count += 1;
            curr_dir = (curr_dir + 1) % 4;
        }


        return path;
        
    }
};