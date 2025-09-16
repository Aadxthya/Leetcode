// Last updated: 9/16/2025, 9:49:22 AM
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int r[8] = {-1, 1, 1, 0, 0, -1, -1, 1};
        int c[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        bool ans = false;

        char opp = (color == 'W') ? 'B' : 'W';

        for (int i = 0; i < 8; i++) {
            int row = rMove + r[i];
            int col = cMove + c[i];
            int count = 0;

            if (row >= 0 && row < 8 && col >= 0 && col < 8 && board[row][col] == opp) {
                row += r[i];
                col += c[i];
                count++;

                while (row >= 0 && row < 8 && col >= 0 && col < 8) {
                    if (board[row][col] == opp) {
                        count++;
                        row += r[i];
                        col += c[i];
                    } else if (board[row][col] == color) {
                        if (count >= 1) {
                            return true;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        return false;
    }
};
