// Last updated: 9/16/2025, 9:52:33 AM
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int xor1 = 0, xor2 = 0;
        // XOR all array elements
        for (int i = 0; i < n; i++) {
            xor2 ^= arr[i];
        }
        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }
        // Missing number is the XOR of xor1 and xor2
        return xor1 ^ xor2;
    }
};
