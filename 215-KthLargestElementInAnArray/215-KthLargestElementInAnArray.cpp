// Last updated: 9/16/2025, 9:52:50 AM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int , vector<int>, greater<int>> min_heapp (nums.begin(), nums.begin() + k);
            for(int i = k;i<nums.size();i++){
                if (nums[i]>min_heapp.top()){
                min_heapp.pop();
                min_heapp.push(nums[i]);
            }

            }    
            return min_heapp.top();

            }

};

    
