// Last updated: 9/16/2025, 9:52:59 AM
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0; i<=31; i++) {
            int last = (n>>i)&1;
            ans = ans<<1;
            ans = ans | last;
        }
        return ans;
    }
};