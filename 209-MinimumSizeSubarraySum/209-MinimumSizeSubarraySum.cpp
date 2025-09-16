// Last updated: 9/16/2025, 9:52:51 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minn = INT_MAX ; 
        int left = 0 ;
            for(int i = 0 ; i < nums.size() ; i++){
                sum += nums[i];

                while(sum>=target){
                    minn = min( minn , (i - left + 1) );
                    sum -= nums[left++];
                }
            }


        return minn == INT_MAX ? 0 : minn;

    }
};