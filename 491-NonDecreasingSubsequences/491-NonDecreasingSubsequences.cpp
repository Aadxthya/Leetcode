// Last updated: 9/16/2025, 9:51:40 AM
class Solution {
public:
    set<vector<int>> st;
    void f(int i,vector<int>& nums,vector<int>& temp){
        
        if(temp.size()>=2){
            st.insert(temp);
        }
        if(i==nums.size()){
            return ;
        }
        if(temp.size()==0||nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            f(i+1,nums,temp);
            temp.pop_back();
        }
        f(i+1,nums,temp);
        return ;

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size()<2){
            return {};
        }
        vector<int> temp;
        f(0,nums,temp);
        vector<vector<int>>ans;
        for(auto & it:st){
            ans.push_back(it);
        }
        return ans;
    }
};