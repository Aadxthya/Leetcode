// Last updated: 9/16/2025, 9:48:52 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        long long score = 0;
        int left = 0; 
        int n = nums.size();
        long long ans = 0;
        vector<long long> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int right = 1;right <= n;right ++){
            score = (prefix[right] - prefix[left])*(right - left);
            while(score >= k){

                left++;
                score = (prefix[right] - prefix[left])*(right - left);


            }
            ans += (right - left);

        }

        return ans;
        
    }
};