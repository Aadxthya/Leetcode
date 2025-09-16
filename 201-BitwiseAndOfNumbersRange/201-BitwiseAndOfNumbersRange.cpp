// Last updated: 9/16/2025, 9:52:55 AM
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Move both left and right rightwards until they are equal
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
