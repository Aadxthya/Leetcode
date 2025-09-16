// Last updated: 9/16/2025, 9:52:17 AM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mpp;
        vector<int> ans;

        // Store elements of nums1
        for (int v : nums1) {
            mpp[v] = true;
        }

        // Check elements of nums2
        for (int v : nums2) {
            if (mpp[v]) {
                ans.push_back(v);
                mpp[v] = false; // to avoid duplicates in result
            }
        }

        return ans;
    }
};
    