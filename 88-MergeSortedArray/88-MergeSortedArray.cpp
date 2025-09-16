// Last updated: 9/16/2025, 9:54:12 AM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Last valid element in nums1
        int j = n - 1;         // Last element in nums2
        int k = m + n - 1;     // End of nums1

        // Merge from the end to avoid overwriting
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements left in nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
