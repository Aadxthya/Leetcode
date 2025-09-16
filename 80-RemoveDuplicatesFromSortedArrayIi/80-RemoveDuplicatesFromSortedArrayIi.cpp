// Last updated: 9/16/2025, 9:54:18 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums){
            if(i<2 || nums[i - 2]!= n)
                nums[i++] = n;

        }
        return i;
    }
};
