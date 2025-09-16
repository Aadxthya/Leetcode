// Last updated: 9/16/2025, 9:51:59 AM
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


class Solution {
public:
    


int splitArray(vector<int>& nums, int m) {
    int low = *max_element(nums.begin(), nums.end()); // 8
    int high = accumulate(nums.begin(), nums.end(), 0); // 23
    int ans = low;

    while (low <= high) {
        int mid = (low + high) / 2; // limit
        int n = no_of_subarrays_with_max_sum_as_mid(nums, mid);
        
        if (n > m) {
            low = mid + 1;
        } else {
            ans = mid; // minimize ans
            high = mid - 1;
        }
    }

    return ans;
}

int no_of_subarrays_with_max_sum_as_mid(vector<int>& nums, int mid) {
    int sum = 0;
    int count = 1;

    for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] > mid) {
            sum = nums[i];
            count++;
        } else {
            sum += nums[i];
        }
    }

    return count;
}

};