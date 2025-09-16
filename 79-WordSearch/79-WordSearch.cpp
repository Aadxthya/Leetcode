// Last updated: 9/16/2025, 9:54:19 AM
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Try DFS from each cell
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        // Base case: found the entire word
        if (index == word.size()) return true;

        // Check out-of-bounds or mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j]; // Save current char
        board[i][j] = '#';       // Mark as visited

        // Explore all 4 directions
        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);

        board[i][j] = temp; // Backtrack

        return found;
    }
};
