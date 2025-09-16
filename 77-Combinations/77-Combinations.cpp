// Last updated: 9/16/2025, 9:54:22 AM
class Solution {
public:
    void util(int ind,vector<int> set,vector<vector<int>>& ans,int n,int k,int val)
    {
        if(ind>k)
        {
            ans.push_back(set);
            return;
        }
        for(int i=val;i<=n;i++)
        {
            set.push_back(i);
            util(ind+1,set,ans,n,k,i+1);
            set.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> set;
        util(1,set,ans,n,k,1);
        return ans;
    }
};