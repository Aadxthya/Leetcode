// Last updated: 9/16/2025, 9:50:01 AM
class Solution {
public:
    int numSubUptil(vector<int>& nums, int goal){
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int count = 0;
        
        while(right<n){
            sum+=nums[right]%2;
            
            while(left<=right && sum>goal){
                sum-=nums[left]%2;
                left++;
            }
            
            count += right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubUptil(nums, k)-numSubUptil(nums, k-1);
    }
};