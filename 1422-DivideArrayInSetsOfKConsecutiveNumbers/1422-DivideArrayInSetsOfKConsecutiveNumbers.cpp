// Last updated: 9/16/2025, 9:49:57 AM
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto it : freq) {
            int start = it.first;
            int count = it.second;
            if (count > 0) {
                for (int i = 0; i < k; ++i) {
                    if (freq[start + i] < count) {
                        return false;
                    }
                    freq[start + i] -= count;
                }
            }
        }

        return true;
    }
};