// Last updated: 9/16/2025, 9:49:04 AM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_1 = 0;
        for(auto it : nums)
            if(it == 1)
                total_1++;

        int count = 0;
        for(int i=0; i<total_1; i++)
        {
            if(nums[i] == 1)
                count++;
        }
        int temp = count;
        for(int j=total_1; j<(n + total_1 - 1); j++)
        {
            // cout<<nums[j-3]<<" "<<nums[j-2]<<" "<<nums[(j-1) % n]<<" "<<count<<" "<<nums[(j - total_1) % n]<<" "<<nums[j % n]<<" "<<j<<endl; 
            temp = temp - nums[(j - total_1) % n] + nums[j % n];
            count = max(count, temp);
        }

        cout<<count<<endl;
        return total_1 - count;
        
    }
};