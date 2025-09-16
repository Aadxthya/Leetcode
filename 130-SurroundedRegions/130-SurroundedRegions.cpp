// Last updated: 9/16/2025, 9:53:38 AM
class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& board,int* drow,int *dcol){
        board[row][col]='B';
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        // First and Last Row
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,drow,dcol);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,drow,dcol);
            }
        }
        // First and Last Col
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,drow,dcol);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='B'){
                    board[i][j]='O';
                }
            }
        }
    }
};



