// Last updated: 9/16/2025, 9:54:55 AM
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // This will store all the permutations
        backtrack(nums, 0, result); // Start the backtracking from index 0
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            // If we've considered every position, add the permutation to the result
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            // Swap the current element with the element at the current index
            swap(nums[index], nums[i]);
            // Recurse to generate permutations with the next position fixed
            backtrack(nums, index + 1, result);
            // Backtrack by swapping back to restore the original array
            swap(nums[index], nums[i]);
        }
    }
};
