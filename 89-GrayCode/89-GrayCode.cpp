// Last updated: 9/16/2025, 9:54:10 AM
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < (1 << n); ++i) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
