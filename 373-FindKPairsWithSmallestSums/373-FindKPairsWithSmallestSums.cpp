// Last updated: 9/16/2025, 9:52:13 AM
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        // Min-heap to store {sum, index1, index2}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        // Push the first column (pairs of nums1[i] with nums2[0])
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push(make_tuple(nums1[i] + nums2[0], i, 0));
        }
        
        // Extract the smallest sums from the heap
        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            
            // If there's a next element in nums2, push the next pair (nums1[i], nums2[j+1])
            if (j + 1 < nums2.size()) {
                minHeap.push(make_tuple(nums1[i] + nums2[j+1], i, j+1));
            }
        }
        
        return result;
    }
};