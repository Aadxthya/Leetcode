// Last updated: 9/16/2025, 9:49:11 AM
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            q1.push({nums[i],i});
            if(q1.size()>k){
                q1.pop();
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q2;
        while(!q1.empty()){
            int x=q1.top().first;
            int y=q1.top().second;
            q1.pop();
            q2.push({y,x});
        }
        vector<int> ans;
        while(!q2.empty()){
            int x=q2.top().second;
            q2.pop();
            ans.push_back(x);
        }
        return ans;
    }
};