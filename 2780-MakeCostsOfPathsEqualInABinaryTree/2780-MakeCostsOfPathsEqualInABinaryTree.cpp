// Last updated: 9/16/2025, 9:48:27 AM
class Solution {
public:

    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        vector<int> nums=cost;
          for(int i=n/2-1;i>=0;i--){
            int left=2*i+1;
            int right=2*i+2;
            nums[i]+=max(nums[left],nums[right]);
            ans=ans+abs(nums[left]-nums[right]); 
          }
        return ans;
    }
};