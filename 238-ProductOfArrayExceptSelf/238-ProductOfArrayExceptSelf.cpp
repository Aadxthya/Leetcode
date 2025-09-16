// Last updated: 9/16/2025, 9:52:40 AM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> output(n, 1);
        int pefix = 1;

        for (int i = 0; i < nums.size(); i++) {
            output[i] = pefix;
            pefix *= nums[i];
        }

        int postfix = 1;

        for (int i = n - 1; i >= 0; --i) {

            output[i] *= postfix;
            postfix *= nums[i];
        }
        return output;
    }
};