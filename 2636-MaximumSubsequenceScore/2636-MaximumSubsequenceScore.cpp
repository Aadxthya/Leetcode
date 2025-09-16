// Last updated: 9/16/2025, 9:48:36 AM
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);

        for (int i = 0; i < n; ++i)
            pairs[i] = {nums2[i], nums1[i]};

        // Sort by descending nums2
        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, result = 0;

        for (auto& [b, a] : pairs) {
            sum += a;
            minHeap.push(a);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k)
                result = max(result, sum * b);
        }

        return result;
    }
};
