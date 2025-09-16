// Last updated: 9/16/2025, 9:48:37 AM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) h = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            if(search(nums2, nums1[i])) return nums1[i];
        }
        return -1;
    }
};