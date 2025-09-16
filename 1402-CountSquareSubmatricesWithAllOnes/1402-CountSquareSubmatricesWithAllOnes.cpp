// Last updated: 9/16/2025, 9:50:00 AM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=matrix[i][0]; //1st column
            if(dp[i][0]==1)ans++;
        }
        for(int j=1;j<n;j++){ //dont count 1st element twice
            dp[0][j]=matrix[0][j]; //1st row
            if(dp[0][j]==1)ans++;
        }
        for(int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                if(matrix[i][j]==1){
                    //min amt of squares getting formed at its top,left,topleft corner +1
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};